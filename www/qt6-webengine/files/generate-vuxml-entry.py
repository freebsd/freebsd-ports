#!/usr/bin/env python3
import argparse
import json
import os
import re
import sys
import textwrap
import time
import urllib.error
import urllib.request
import uuid
from datetime import datetime
from typing import Callable, Dict, List, Set, Tuple, Iterator

def clean_subject_description(subject: str, cves: Set[str]) -> str:
    """Sanitize a commit subject into a readable vulnerability description."""
    parts = subject.split(":", 1)
    desc = parts[1].strip() if len(parts) > 1 else subject

    if len(parts) <= 1:
        for cve in cves:
            desc = desc.replace(cve, "")

    desc = re.sub(r'\[(?:backport|fixup)\]\s*', '', desc, flags=re.IGNORECASE)
    desc = re.sub(r'^(?:and|,|\s)*', '', desc, flags=re.IGNORECASE)
    desc = re.sub(r'\s*\(\d+/\d+\)\s*$|\s*\(part\s*\d+\)\s*$', '', desc, flags=re.IGNORECASE)
    return desc.strip('.:;, \t')

def generate_vuxml_entry(cve_dict: Dict[str, str], discovery_date: str, non_vulnerable_version: str, branch_name: str) -> str:
    """Generate the final XML entry from processed CVE data."""
    if not cve_dict:
        return ""

    sorted_cves = sorted(cve_dict.keys())
    vid = str(uuid.uuid1())
    today = datetime.utcnow().strftime("%Y-%m-%d")
    final_discovery = discovery_date if discovery_date else today
    cgit_url = f"https://code.qt.io/cgit/qt/qtwebengine-chromium.git/log/?h={branch_name}"

    lines = [
        f'  <vuln vid="{vid}">',
        '    <topic>qt6-webengine -- multiple vulnerabilities</topic>',
        '    <affects>',
        '<package>',
        '<name>qt6-pdf</name>',
        '<name>qt6-webengine</name>',
        f'<range><lt>{non_vulnerable_version}</lt></range>',
        '</package>',
        '    </affects>',
        '    <description>',
        '\t<body xmlns="http://www.w3.org/1999/xhtml">',
        '\t<p>Qt qtwebengine-chromium repo reports:</p>',
        f'\t<blockquote cite="{cgit_url}">',
        f'\t  <p>Backports for {len(sorted_cves)} security bugs in Chromium:</p>',
        '\t  <ul>'
    ]

    # Initialize the text wrapper to 100 columns.
    # expand_tabs=False ensures we don't accidentally overwrite literal \t characters.
    wrapper = textwrap.TextWrapper(
        width=100,
        initial_indent='\t    ',
        subsequent_indent='\t\t',
        expand_tabs=False,
        break_long_words=False,
        break_on_hyphens=False
    )

    for cve in sorted_cves:
        # Pass the raw un-indented string, and let TextWrapper handle both the indent and the wrap
        lines.append(wrapper.fill(f'<li>{cve}: {cve_dict[cve]}</li>'))

    lines.extend([
        '\t  </ul>',
        '\t</blockquote>',
        '\t</body>',
        '    </description>',
        '    <references>'
    ])

    for cve in sorted_cves:
        lines.append(f'      <cvename>{cve}</cvename>')

    lines.extend([
        f'      <url>{cgit_url}</url>',
        '    </references>',
        '    <dates>',
        f'      <discovery>{final_discovery}</discovery>',
        f'      <entry>{today}</entry>',
        '    </dates>',
        '  </vuln>'
    ])

    return "\n".join(lines) + "\n"

# --- Network I/O & File Operations ---

def create_logger(quiet: bool) -> Callable[[str], None]:
    """Higher-order function returning a logging closure based on the quiet flag."""
    return lambda msg: None if quiet else print(msg, file=sys.stderr)

def parse_existing_cves(vuxml_path: str, log: Callable[[str], None]) -> Set[str]:
    """Reads existing VuXML file and returns a set of CVEs already documented for qt6-webengine."""
    existing_cves = set()
    try:
        with open(vuxml_path, 'r', encoding='utf-8') as f:
            content = f.read()
            vuln_blocks = re.split(r'(?=<vuln\s)', content)

            for block in vuln_blocks:
                if '<name>qt6-webengine</name>' in block:
                    found = re.findall(r'<cvename>(CVE-\d{4}-\d+)</cvename>', block, re.IGNORECASE)
                    existing_cves.update([c.upper() for c in found])

            if existing_cves:
                log(f"====> Loaded {len(existing_cves)} existing qt6-webengine CVEs from {vuxml_path}.")
    except FileNotFoundError:
        log(f"         [!] Could not read VuXML file: '{vuxml_path}' not found.")
    except Exception as e:
        log(f"         [!] Error processing VuXML file: {e} ({type(e).__name__})")
    return existing_cves

def fetch_nvd_description(cve: str, log: Callable[[str], None]) -> str:
    """Fetches a fallback CVE description from the NVD JSON API v2.0."""
    url = f"https://services.nvd.nist.gov/rest/json/cves/2.0?cveId={cve}"
    headers = {'User-Agent': 'FreeBSD-VuXML-Generator'}

    # Dynamic Rate Limit & Auth configuration
    # The NVD implements a rolling rate limit of 5 requests/30 secs without an API key and
    # 50 requests/30 secs with an API key (https://nvd.nist.gov/developers/start-here -> Rate Limits).
    # You can request your own API key here: https://nvd.nist.gov/developers/request-an-api-key
    # Organization Name: FreeBSD; Email Address: <your_uname>@FreeBSD.org; Organization Type: Non-Profit
    # Once generated, export the key to the NVD_API_KEY environment variable for quicker results.
    api_key = os.environ.get('NVD_API_KEY')
    if api_key:
        headers['apiKey'] = api_key
        delay = 0.7  # 50 req / 30 sec + 0.1s safety padding
        log(f"      -> Missing description for {cve}, querying NVD API (Authenticated)...")
    else:
        delay = 6.1  # 5 req / 30 sec + 0.1s safety padding
        log(f"      -> Missing description for {cve}, querying NVD API (Public limit)...")

    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as response:
            data = json.loads(response.read().decode('utf-8'))

        vulns = data.get('vulnerabilities', [])
        if not vulns:
            return "Description pending NVD publication"

        descriptions = vulns[0].get('cve', {}).get('descriptions', [])
        for desc_obj in descriptions:
            if desc_obj.get('lang') == 'en':
                desc = desc_obj.get('value', '').strip()
                desc = re.sub(r'\s*in Google Chrome.*', '', desc, flags=re.IGNORECASE)
                desc = re.sub(r'\s*in Chromium.*', '', desc, flags=re.IGNORECASE)
                return desc

        return "Description pending NVD publication"
    except urllib.error.HTTPError as e:
        if e.code == 403:
            log(f"         [!] NVD API HTTP 403 Forbidden for {cve}. Rate limit exceeded or invalid key.")
        else:
            log(f"         [!] NVD API HTTP Error {e.code} for {cve}.")
        return "Unknown vulnerability"
    except Exception as e:
        log(f"         [!] NVD API fetch failed for {cve}: {e}")
        return "Unknown vulnerability"
    finally:
        time.sleep(delay)

def fetch_commits(base_commit: str, branch_name: str, log: Callable[[str], None]) -> List[dict]:
    """Paginates through GitHub commits natively to bypass API limits."""
    commits = []
    page = 1

    while True:
        url = f"https://api.github.com/repos/qt/qtwebengine-chromium/commits?sha={branch_name}&per_page=100&page={page}"
        try:
            req = urllib.request.Request(url, headers={'User-Agent': 'FreeBSD-VuXML-Generator'})
            with urllib.request.urlopen(req) as response:
                page_data = json.loads(response.read().decode('utf-8'))

            if not page_data:
                break

            for commit_obj in page_data:
                if commit_obj['sha'].startswith(base_commit):
                    return commits # Immediate functional return upon finding the base
                commits.append(commit_obj)

            page += 1
        except urllib.error.URLError as e:
            print(f"API Request failed during pagination (Page {page}): {e}", file=sys.stderr)
            sys.exit(1)

    return commits

def main():
    parser = argparse.ArgumentParser(description="Generate FreeBSD VuXML entries for qtwebengine-chromium.")
    parser.add_argument('-q', '--quiet', action='store_true', help='Suppress informational/debugging stderr output')
    parser.add_argument('-f', '--vuxmlfile', help='VuXML file to check for duplicates (/usr/ports/security/vuxml/vuln/2026.xml)')
    parser.add_argument('base_commit', help='Commit hash of the repo to start the comparison from')
    parser.add_argument('branch_name', help='Branch name to target in the repo')
    parser.add_argument('non_vulnerable_version', help='PKGVERSION of the new, non-affected version')

    args = parser.parse_args()
    log = create_logger(args.quiet)

    existing_cves = parse_existing_cves(args.vuxmlfile, log) if args.vuxmlfile else set()

    log(f"====> Querying GitHub API for commits from {args.base_commit} to tip of {args.branch_name}...")
    commits = fetch_commits(args.base_commit, args.branch_name, log)
    log(f"      -> Successfully fetched {len(commits)} commits.")

    # Generator to filter out dependency commits cleanly
    valid_commits: Iterator[dict] = (
        c for c in commits
        if not re.search(r'dependen?c(?:y|ies)\s+for', c.get('commit', {}).get('message', '').split('\n')[0], flags=re.IGNORECASE)
    )

    cve_dict: Dict[str, str] = {}
    discovery_date: str = ""

    for commit in valid_commits:
        subject = commit['commit']['message'].split('\n')[0]
        raw_cves = set(re.findall(r'(CVE-\d{4}-\d+)', subject, flags=re.IGNORECASE))

        if not raw_cves:
            continue

        unique_cves = {c.upper() for c in raw_cves}
        new_cves = unique_cves - existing_cves

        for duplicate in (unique_cves - new_cves):
            log(f"      -> Skipping {duplicate}: Already documented.")

        if not new_cves:
            continue

        # Extract the date and strictly keep the oldest one found
        date_str = commit.get('commit', {}).get('committer', {}).get('date', '')
        if date_str:
            commit_date = date_str.split('T')[0]
            if not discovery_date or commit_date < discovery_date:
                discovery_date = commit_date

        desc = clean_subject_description(subject, new_cves)

        for cve in new_cves:
            if cve in cve_dict and len(cve_dict[cve]) >= 5:
                continue

            # NVD fallback triggered only by short/empty subject lines
            final_desc = desc if len(desc) >= 5 else fetch_nvd_description(cve, log)
            cve_dict[cve] = final_desc

    if not cve_dict:
        log("====> No new/undocumented CVEs found.")
        return

    xml_output = generate_vuxml_entry(cve_dict, discovery_date, args.non_vulnerable_version, args.branch_name)
    print(xml_output)

if __name__ == "__main__":
    main()
