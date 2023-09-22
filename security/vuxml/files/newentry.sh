#! /bin/sh
set -eu

vuxml_file="$1"
CVE_ID=""
SA_ID=""

show_usage() {
  exec >&2
  echo "Usage: newentry.sh /path/to/vuxml/document [CVE_ID|SA_ID]"
  exit 1
}

if [ -z "${vuxml_file}" ]; then
	show_usage
fi

shift
while [ $# -gt 0 ]; do
case "$1" in
  CVE_ID=*)
    CVE_ID="${1#CVE_ID=}"
    shift
    ;;
  SA_ID=*)
    SA_ID="${1#SA_ID=}"
    shift
    ;;
  *)
    echo "Invalid argument: $1"
    show_usage
    exit 1
    ;;
esac
done

tmp="`mktemp ${TMPDIR:-/tmp}/vuxml.XXXXXXXXXX`" || exit 1
tmp_fbsd_sa=""
tmp_mitre=""
tmp_nvd=""

doclean="yes"
cleanup() {
  if [ "${doclean}" = "yes" ]; then
	rm -f "${tmp}" "${tmp_fbsd_sa}" "${tmp_mitre}" "${tmp_nvd}" > /dev/null
  fi
}
trap cleanup EXIT 1 2 13 15

vid="`uuidgen | tr '[:upper:]' '[:lower:]'`"
[ -z "$vid" ] && exit 1
cvename="INSERT CVE RECORD IF AVAILABLE"
cveurl="INSERT BLOCKQUOTE URL HERE"
details="."
discovery="`date -u '+%Y-%m'`-FIXME" || exit 1
entry="`date -u '+%Y-%m-%d'`" || exit 1
package_name=""
references="INSERT URL HERE"
topic=""
source="SO-AND-SO"
upstream_fix=""
impact=""
DESC_BODY="<body xmlns=\"http://www.w3.org/1999/xhtml\">
	<p>${source} reports:</p>
	<blockquote cite=\"${references}\">
	  <p>${details}</p>
	</blockquote>
	</body>"


# Try to retrieve information if a CVE identifier was provided
if [ -n "${CVE_ID}" ]; then
	if ! command -v jq > /dev/null; then
		echo textproc/jq is needed for CVE automatic entry fill
		exit 1
	fi

	# NVD database only accepts uppercase CVE ids, like CVE-2022-39282, NOT
	# cve-2022-39282.
	CVE_ID=$(echo "${CVE_ID}" | tr '[:lower:]' '[:upper:]') || exit 1

	# Get information from the NVD database JSON format
	tmp_nvd="`mktemp ${TMPDIR:-/tmp}/nvd_json_data.XXXXXXXXXX`" || exit 1
	fetch -q -o "${tmp_nvd}" https://services.nvd.nist.gov/rest/json/cves/2.0?cveId="${CVE_ID}" || exit 1
	# Get information from MITRE database (they provide a nice "topic")
	tmp_mitre="`mktemp ${TMPDIR:-/tmp}/mitre.XXXXXXXXXX`" || exit 1
	fetch -q -o "${tmp_mitre}" https://cveawg.mitre.org/api/cve/"${CVE_ID}"

	# Create variables from input and online sources
	cvename="${CVE_ID}"
	cveurl=https://nvd.nist.gov/vuln/detail/${CVE_ID}
	pref=.vulnerabilities[0].cve
	details=$(jq -r "${pref}.descriptions[0].value|@html" "${tmp_nvd}" | fmt -p -s | sed '1!s/^/\t/') || exit 1
	discovery=$(jq -r "${pref}.published|@html" "${tmp_nvd}" | cut -f1 -dT) || exit 1
	pref=.vulnerabilities[0].cve.configurations[0].nodes[0].cpeMatch[0]
	package_name=$(jq -r "${pref}.criteria|@html" "${tmp_nvd}" | cut -f4 -d:) || exit 1
	upstream_fix=$(jq -r "${pref}.versionEndExcluding|@html" "${tmp_nvd}") || exit 1
	pref=.vulnerabilities[0].cve.references[0]
	references=$(jq -r "${pref}.url|@html" "${tmp_nvd}" | tr " " "\n") || exit 1
	source=$(jq -r "${pref}.source|@html" "${tmp_nvd}" | tr " " "\n") || exit 1
	topic=$(jq -r ".containers.cna.title|@html" "${tmp_mitre}" ) || exit 1
fi

if [ -n "${SA_ID}" ]; then
	SA_URL_BASE=https://www.freebsd.org/security/advisories/

	# Get information from the Project's SA site
	tmp_fbsd_sa="$(mktemp ${TMPDIR:-/tmp}/fbsd_sa_data.XXXXXXXXXX)" || exit 1
	fetch -q -o "${tmp_fbsd_sa}" ${SA_URL_BASE}${SA_ID} || exit 1

	# Create variables from SA note
	if grep -q 'CVE Name' "${tmp_fbsd_sa}"; then
		cve_tmp=$(grep 'CVE Name' "${tmp_fbsd_sa}" | cut -f2 -d:) || exit 1
		cvename="${cve_tmp#"${cve_tmp%%[![:space:]]*}"}"

		# NVD database only accepts uppercase CVE ids, like CVE-2022-39282, NOT
		# cve-2022-39282.
		cvename=$(echo "${cvename}" | tr '[:lower:]' '[:upper:]') || exit 1
		cveurl="https://nvd.nist.gov/vuln/detail/${cvename}"
	fi

	details=$(awk '/II.  Problem Description/ {f=1;next;next} /III. Impact/ {f=0} (f==1) {print}' "${tmp_fbsd_sa}" ) || exit 1
	details=$(echo "<p>${details}</p>" | fmt -p -s | sed -e 's/<p> /<p>/' | sed '1!s/^/\t/')
	impact=$(awk '/III. Impact/ {f=1;next;next} /IV.  Workaround/ {f=0} (f==1) {print}' "${tmp_fbsd_sa}") || exit 1
	impact=$(echo "<p>${impact}</p>" | fmt -p -s | sed -e 's/<p> /<p>/' | sed '1!s/^/\t/')

	package_name="FreeBSD"
	if grep -Eq 'Module:.*kernel' "${tmp_fbsd_sa}"; then
		package_name="${package_name}-kernel"
	fi

	upstream_fix="FIXME"
	references="${SA_URL_BASE}${SA_ID}"
	source="The FreeBSD Project"
	topic_tmp=$(grep 'Topic:' "${tmp_fbsd_sa}" | cut -f2 -d:) || exit 1
	topic="${topic_tmp#"${topic_tmp%%[![:space:]]*}"}"

DESC_BODY="<body xmlns=\"http://www.w3.org/1999/xhtml\">
	<h1>Problem Description:</h1>
	  ${details}
	<h1>Impact:</h1>
	  ${impact}
      </body>"
fi

awk '/^<\?/,/^<vuxml/ { print }' "${vuxml_file}" >> "${tmp}" || exit 1
cat << EOF >> "${tmp}" || exit 1
  <vuln vid="${vid}">
    <topic>${package_name} -- ${topic}</topic>
    <affects>
      <package>
	<name>${package_name}</name>
	<range><lt>${upstream_fix}</lt></range>
      </package>
    </affects>
    <description>
	${DESC_BODY}
    </description>
    <references>
      <cvename>${cvename}</cvename>
      <url>${cveurl}</url>
    </references>
    <dates>
      <discovery>${discovery}</discovery>
      <entry>${entry}</entry>
    </dates>
  </vuln>

EOF
awk '/^[[:space:]]+<vuln /,/^NONE$/ { print }' \
  "${vuxml_file}" >> "${tmp}" || exit 1

if cp "${tmp}" "${vuxml_file}"; then
  exec ${EDITOR:-vi} "${vuxml_file}"
else
  doclean="no"
  exec >&2
  echo "Could not overwrite \`${vuxml_file}'."
  echo "Results are left in \`${tmp}'."
  exit 1
fi
