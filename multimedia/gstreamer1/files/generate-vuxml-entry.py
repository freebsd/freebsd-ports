#!/usr/bin/env python3
import argparse
import os
import re
import uuid
import sys
from datetime import datetime
import requests
from bs4 import BeautifulSoup

GST_SECURITY_URL = "https://gstreamer.freedesktop.org/security/"

PACKAGE_MAP = {
    'gstreamer': ['gstreamer1'],
    'gst-devtools': ['gstreamer1-devtools'],
    'gst-plugins-bad': ['gstreamer1-plugins-bad'],
    'gst-plugins-base': ['gstreamer1-plugins'],
    'gst-plugins-good': ['gstreamer1-plugins-good'],
    'gst-plugins-rs': ['gstreamer1-plugins-rust'],
    'gst-plugins-ugly': ['gstreamer1-plugins-ugly'],
    'gst-libav': ['gstreamer1-libav'],
    'gst-rtsp-server': ['gstreamer1-rtsp-server'],
    'gst-editing-services': ['gstreamer1-editing-services']
}

def get_supported_python_versions():
    """Parses Mk/Uses/python.mk to find active FreeBSD Python versions."""
    portsdir = os.environ.get('PORTSDIR', '/usr/ports')
    python_mk = os.path.join(portsdir, 'Mk', 'Uses', 'python.mk')
    versions = []

    try:
        with open(python_mk, 'r') as f:
            for line in f:
                if line.strip().startswith('_PYTHON_VERSIONS'):
                    data_part = line.split('#')[0]
                    parts = data_part.split('=', 1)[1].strip().split()
                    for v in parts:
                        clean_v = v.replace('.', '')
                        if clean_v and clean_v[0].isdigit() and clean_v.isalnum():
                            versions.append(clean_v)
                    break
    except Exception as e:
        print(f"[!] Warning: Could not parse {python_mk} ({e}). Falling back to py312.", file=sys.stderr)

    return versions if versions else ['312']

def map_module_to_port(module_name):
    """Returns a list of correctly formatted FreeBSD port names."""
    module_name = module_name.lower().strip()
    if module_name == 'gst-python':
        return [f"py{v}-gstreamer1" for v in get_supported_python_versions()]

    return PACKAGE_MAP.get(module_name, [f"gstreamer1-{module_name.replace('gst-', '')}"])

def parse_sa_id(sa_string):
    match = re.search(r'(\d{4})-(\d{4})', sa_string)
    if match:
        return int(match.group(1) + match.group(2))
    return 0

def parse_version_string(v_str):
    if not v_str:
        return (0, 0, 0)
    try:
        return tuple(int(x) for x in v_str.split('.') if x.isdigit())
    except ValueError:
        return (0, 0, 0)

def get_fixed_version_from_detail(url):
    """Fetches a detail page and extracts the version it fixes."""
    try:
        resp = requests.get(url, timeout=5)
        # Look for either a literal '<' or the HTML entity '&lt;'
        match = re.search(r'(?:<|&lt;)\s*([0-9]+\.[0-9]+\.[0-9]+)', resp.text)
        if match:
            return match.group(1)
    except requests.RequestException:
        pass
    return None

def auto_detect_boundaries(soup, fixed_version, user_tip_sa=None, user_base_sa=None, max_lookahead=4):
    """
    Crawls the index top-down to find the contiguous batch of SAs.
    Uses user_tip_sa as a strict start point (ceiling) and user_base_sa as a strict end point (floor).
    """
    print(f"[*] Auto-detecting SA range for version {fixed_version} (and newer)...", file=sys.stderr)
    if user_tip_sa:
        print(f"[*] Hard ceiling (tip) set to: {user_tip_sa}", file=sys.stderr)
    if user_base_sa:
        print(f"[*] Hard floor (base) set to: {user_base_sa}", file=sys.stderr)

    target_v_tuple = parse_version_string(fixed_version)

    # Normalize user boundaries to integer IDs to avoid prefix mismatch (e.g., "SA-2026-0040" vs "GStreamer-SA-2026-0040")
    tip_id = parse_sa_id(user_tip_sa) if user_tip_sa else None
    base_id = parse_sa_id(user_base_sa) if user_base_sa else None

    sa_links = []
    for tr in soup.find_all('tr'):
        tds = tr.find_all(['td', 'th'])
        if len(tds) >= 4:
            raw_id_col = tds[0].get_text(separator=' ', strip=True)
            sa_match = re.search(r'GStreamer-SA-(\d{4}-\d{4})', raw_id_col, re.IGNORECASE)
            if sa_match:
                a_tag = tds[3].find('a')
                if a_tag and 'href' in a_tag.attrs:
                    sa_links.append({
                        'id': f"GStreamer-SA-{sa_match.group(1)}",
                        'url': requests.compat.urljoin(GST_SECURITY_URL, a_tag['href'])
                    })

    matched_sas = []
    started = False
    miss_count = 0

    for item in sa_links:
        current_id = parse_sa_id(item['id'])

        # Wait until we hit the explicit tip (if defined)
        if tip_id and not started and current_id != tip_id:
            continue

        found_ver = get_fixed_version_from_detail(item['url'])
        current_v_tuple = parse_version_string(found_ver)

        # Match if the found version is equal to or newer than the target fixed_version
        if current_v_tuple >= target_v_tuple:
            matched_sas.append(item['id'])
            started = True
            miss_count = 0
            print(f"  -> {item['id']} patches version {found_ver} (>= {fixed_version})", file=sys.stderr)
        elif started:
            miss_count += 1
            print(f"  -> {item['id']} patches version {found_ver}. Lookahead buffer: {miss_count}/{max_lookahead}", file=sys.stderr)

            # Only abort on lookahead if the user HAS NOT defined a hard base
            if miss_count >= max_lookahead and not base_id:
                print(f"[*] Hit {max_lookahead} older entries in a row. Ending auto-crawl.", file=sys.stderr)
                break

        # Hard stop if we hit the explicitly defined base
        if base_id and current_id == base_id:
            print(f"[*] Hit user-defined base floor {item['id']}. Ending auto-crawl.", file=sys.stderr)
            break

    if not matched_sas:
        print(f"[!] Auto-detect failed: Could not find any SAs fixing >= {fixed_version} within boundaries.", file=sys.stderr)
        sys.exit(1)

    start_sa = min(matched_sas, key=parse_sa_id)
    end_sa = max(matched_sas, key=parse_sa_id)

    print(f"[*] Auto-detected range: {start_sa} to {end_sa}\n", file=sys.stderr)
    return start_sa, end_sa

def fetch_and_parse_advisories(sa1, sa2, fixed_version, auto_mode):
    print(f"[*] Fetching GStreamer security advisories from {GST_SECURITY_URL}...", file=sys.stderr)
    try:
        response = requests.get(GST_SECURITY_URL, timeout=10)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"[!] Error fetching security page: {e}", file=sys.stderr)
        sys.exit(1)

    soup = BeautifulSoup(response.text, 'html.parser')

    if auto_mode:
        # Pass sa1 strictly as the tip (start) and sa2 strictly as the base (end)
        sa1, sa2 = auto_detect_boundaries(soup, fixed_version, user_tip_sa=sa1, user_base_sa=sa2)

    id1 = parse_sa_id(sa1)
    id2 = parse_sa_id(sa2)

    start_id = min(id1, id2)
    end_id = max(id1, id2)

    cves = set()
    sa_items = []
    affected_packages = set()
    dates = []
    urls = set()

    target_v_tuple = parse_version_string(fixed_version)

    for tr in soup.find_all('tr'):
        tds = tr.find_all(['td', 'th'])
        if len(tds) >= 3:
            raw_id_col = tds[0].get_text(separator=' ', strip=True)

            sa_match = re.search(r'GStreamer-SA-(\d{4}-\d{4})', raw_id_col, re.IGNORECASE)
            if not sa_match:
                continue

            sa_id = f"GStreamer-SA-{sa_match.group(1)}"
            current_id = parse_sa_id(sa_id)

            if start_id <= current_id <= end_id:
                summary_text = tds[1].get_text(separator=' ', strip=True)

                if "Reserved" in summary_text or "tbd" in summary_text.lower():
                    continue

                a_tag = tds[3].find('a') if len(tds) > 3 else None
                detail_url = None
                if a_tag and 'href' in a_tag.attrs:
                    detail_url = requests.compat.urljoin(GST_SECURITY_URL, a_tag['href'])

                skip_sa = False
                det_text = ""

                if detail_url:
                    try:
                        det_resp = requests.get(detail_url, timeout=5)
                        det_resp.raise_for_status()

                        # Extract and check the version
                        match = re.search(r'(?:<|&lt;)\s*([0-9]+\.[0-9]+\.[0-9]+)', det_resp.text)
                        found_ver = match.group(1) if match else None
                        current_v_tuple = parse_version_string(found_ver)

                        if current_v_tuple < target_v_tuple:
                            print(f"[*] Skipping {sa_id} (fixes {found_ver} < {fixed_version})", file=sys.stderr)
                            skip_sa = True
                        else:
                            det_soup = BeautifulSoup(det_resp.text, 'html.parser')
                            det_text = det_soup.get_text(separator=' ', strip=True)

                    except requests.RequestException as e:
                        print(f"[!] Warning: Failed to fetch {detail_url}: {e}", file=sys.stderr)

                if skip_sa:
                    continue

                # If we made it here, the SA is valid. Append to arrays.
                date_text = tds[2].get_text(strip=True)
                found_cves = re.findall(r'(CVE-\d{4}-\d{4,7})', raw_id_col, re.IGNORECASE)
                cves.update([cve.upper() for cve in found_cves if "XXXX" not in cve.upper()])

                if date_text and re.match(r'\d{4}-\d{2}-\d{2}', date_text):
                    dates.append(date_text)

                clean_summary = " ".join(summary_text.split())
                sa_items.append((sa_id, clean_summary))

                if detail_url:
                    urls.add(detail_url)

                # Parse affected packages using the text we already downloaded
                if det_text:
                    patterns = [
                        r'Affected\s+Version[s]?[\s:]*(?:GStreamer\s+)?(gst-[a-z0-9-]+|gstreamer)',
                        r'Affected\s+module[s]?[\s:]*(?:GStreamer\s+)?([a-z0-9-,\s]+)',
                        r'Module[s]?[\s:]*(?:GStreamer\s+)?([a-z0-9-,\s]+)'
                    ]

                    found_for_this_sa = False
                    for pat in patterns:
                        matches = re.findall(pat, det_text, re.IGNORECASE)
                        for match_str in matches:
                            for mod in re.split(r'[,\s]+', match_str):
                                mod = mod.strip().lower()
                                if mod in PACKAGE_MAP or mod == 'gst-python':
                                    affected_packages.update(map_module_to_port(mod))
                                    found_for_this_sa = True

                    if not found_for_this_sa:
                        for mod in list(PACKAGE_MAP.keys()) + ['gst-python']:
                            if mod != 'gstreamer' and re.search(r'\b' + re.escape(mod) + r'\b', det_text, re.IGNORECASE):
                                affected_packages.update(map_module_to_port(mod))

    if not sa_items:
        print(f"[!] Error: No valid security advisories found in the specified range matching >= {fixed_version}.", file=sys.stderr)
        sys.exit(1)

    if not affected_packages:
        print("[!] Warning: Could not parse any specific packages from the detail pages.", file=sys.stderr)
        print("[!] Falling back to gstreamer1.", file=sys.stderr)
        affected_packages.update(map_module_to_port("gstreamer"))

    generate_vuxml(cves, sa_items, affected_packages, fixed_version, dates, urls)

def generate_vuxml(cves, sa_items, affected_packages, fixed_version, dates, urls):
    vid = str(uuid.uuid4())
    valid_dates = sorted(dates)
    discovery_date = valid_dates[0] if valid_dates else datetime.now().strftime("%Y-%m-%d")
    entry_date = datetime.now().strftime("%Y-%m-%d")

    sa_items.sort(key=lambda x: parse_sa_id(x[0]))

    is_multiple = len(sa_items) > 1

    topic_prefix = "gstreamer1"
    if len(affected_packages) == 1:
        topic_prefix = list(affected_packages)[0]

    print(f'  <vuln vid="{vid}">')

    if is_multiple:
        print(f'    <topic>{topic_prefix} -- multiple vulnerabilities</topic>')
    else:
        single_summary = sa_items[0][1].replace('<', '&lt;').replace('>', '&gt;')
        print(f'    <topic>{topic_prefix} -- {single_summary.lower()}</topic>')

    print('    <affects>')
    print('      <package>')

    for pkg in sorted(affected_packages):
        print(f'\t<name>{pkg}</name>')

    print(f'\t<range><lt>{fixed_version}</lt></range>')
    print('      </package>')
    print('    </affects>')
    print('    <description>')
    print('      <body xmlns="http://www.w3.org/1999/xhtml">')
    print('\t<p>The GStreamer project reports:</p>')
    print(f'\t<blockquote cite="{GST_SECURITY_URL}">')

    if is_multiple:
        print('\t  <p>Multiple security issues were identified and fixed in the GStreamer framework.</p>')
    else:
        print('\t  <p>A security issue was identified and fixed in the GStreamer framework.</p>')

    print('\t  <ul>')

    for sa_id, summary in sa_items:
        safe_summary = summary.replace('<', '&lt;').replace('>', '&gt;')
        print(f'\t    <li>{sa_id}: {safe_summary}</li>')

    print('\t  </ul>')
    print('\t</blockquote>')
    print('      </body>')
    print('    </description>')
    print('    <references>')

    for cve in sorted(cves):
        print(f'      <cvename>{cve}</cvename>')

    if urls:
        for u in sorted(urls):
            print(f'      <url>{u}</url>')
    else:
        print(f'      <url>{GST_SECURITY_URL}</url>')

    print('    </references>')
    print('    <dates>')
    print(f'      <discovery>{discovery_date}</discovery>')
    print(f'      <entry>{entry_date}</entry>')
    print('    </dates>')
    print('  </vuln>\n')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-1", "--sa1", help="First GStreamer SA ID boundary (with --auto, this is the ceiling)", required=False)
    parser.add_argument("-2", "--sa2", help="Second GStreamer SA ID boundary (with --auto, this is the floor)", required=False)
    parser.add_argument("-v", "--fixed-version", help="The version where these issues are fixed (e.g., 1.28.4)", required=True)
    parser.add_argument("-a", "--auto", help="Automatically detect SA range based on fixed-version", action="store_true")

    args = parser.parse_args()

    if not args.fixed_version or not args.fixed_version.strip():
        parser.error("The --fixed-version argument cannot be empty.")

    if not re.match(r'^\d+(?:\.\d+)*$', args.fixed_version):
        parser.error(f"Invalid --fixed-version format: '{args.fixed_version}'. Expected a valid numeric version (e.g., 1.28.4).")

    if not args.auto and (not args.sa1 or not args.sa2):
        parser.error("You must provide both --sa1 and --sa2 unless using --auto.")

    fetch_and_parse_advisories(args.sa1, args.sa2, args.fixed_version, args.auto)
