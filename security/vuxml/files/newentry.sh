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

# -----------------
# Process arguments
# -----------------
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

tmp=$(mktemp "${TMPDIR:-/tmp}"/vuxml.XXXXXXXXXX) || exit 1
tmp_fbsd_sa=""

# -------------------------------------
# Define how to clean up temporal files
# -------------------------------------
#
doclean="yes"
cleanup() {
  if [ "${doclean}" = "yes" ]; then
	rm -f "${tmp}" "${tmp_fbsd_sa}" > /dev/null
  fi

  # Call cleaners for providers
  for provider in ${providers}; do
	cleanup_"${provider}"
	cleanup_"${provider}"
  done
}
trap cleanup EXIT HUP INT PIPE TERM

# -----------------------------
# Variables with default values
# -----------------------------
vid="$(uuidgen | tr '[:upper:]' '[:lower:]')"
[ -z "$vid" ] && exit 1

discovery_date=""
cvename="INSERT CVE RECORD IF AVAILABLE"
cveurl="INSERT BLOCKQUOTE URL HERE"
details="."
discovery_date="$(date -u '+%Y-%m')-FIXME" || exit 1
entry_date="$(date -u '+%Y-%m-%d')" || exit 1
package_name=""
product_name=""
product_range=""
package_list="<package>
<name></name>
<range><lt></lt></range>"
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

# --------------------------------
# Check we have everything we need
# --------------------------------
check_dependencies()
{
	if ! command -v jq > /dev/null; then
		echo textproc/jq is needed for CVE automatic entry fill
		exit 1
	fi
}

# ------------------------------------------
# List of CVE providers sorted by preference
# ------------------------------------------
providers="mitre nvd euvd"

# ------------------------------------------
# List of fields to query for every provider
# ------------------------------------------
fields="cvename cveurl details discovery_date entry_date product_name product_range package_name references source topic"

# Some providers only allow for upper case identifiers
CVE_ID=$(echo "${CVE_ID}" | tr '[:lower:]' '[:upper:]') || exit 1

# -----------------------------------------------------------------------------
# Generic resolver
#
# Gets a variable name and the list of providers and returns the value of the
# variable. If the first defined provider returns empty or nullm, it tries with
# the next one until one provider returns a value or we run out of providers
# -----------------------------------------------------------------------------
resolve_field() {
    field="${1}"
    shift
    providers="$@"

    for provider in $providers; do
        func="get_${field}_from_${provider}"
        if command -v "${func}" >/dev/null 2>&1; then
            value="$($func)"
            if [ -n "${value}" ] && [ "${value}" != "null" ] && [ "${value}" != "n/a" ]; then
                echo "${value}"
                return 0
            fi
	else
		echo "Warning: function ${func} not implemented in provider ${provider}"
        fi
    done
    echo "null"
}

# --------------------------------------------------
# Fill global variables with data from CVE databases
# --------------------------------------------------
get_cve_info() {
	for field in ${fields}; do
	    value=$(resolve_field "${field}" ${providers})
	    eval "${field}=\$value"
	done

DESC_BODY="<body xmlns=\"http://www.w3.org/1999/xhtml\">
	<p>${source} reports:</p>
	<blockquote cite=\"${references}\">
	  <p>${details}</p>
	</blockquote>
	</body>"
}

# ----------------------------------------------------------------
# Fill global variables with data from FreeBSD Security Advisories
# ----------------------------------------------------------------
get_sa_info() {
	SA_URL_BASE=https://www.freebsd.org/security/advisories/

	# Get information from the Project's SA site
	tmp_fbsd_sa=$(mktemp "${TMPDIR:-/tmp}/fbsd_sa_data.XXXXXXXXXX") || exit 1
	fetch -q -o "${tmp_fbsd_sa}" "${SA_URL_BASE}${SA_ID}" || exit 1

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
}

init_providers() {
	for provider in files/*_provider.sh; do
		provider_name=$(basename "${provider}" | cut -f1 -d_)
		. "files/${provider_name}_provider.sh"
		init_"${provider_name}"
	done
}

create_packages_list() {
	tmp_prod=$(mktemp "${TMPDIR:-/tmp}"/vuxml.prod.XXXXXXXXXX) || exit 1
	tmp_ver=$(mktemp "${TMPDIR:-/tmp}"/vuxml.ver.XXXXXXXXXX) || exit 1
	printf "%s" "${product_name}" > "${tmp_prod}"
	printf "%s" "${product_range}" > "${tmp_ver}"

	package_list=$(paste "${tmp_prod}" "${tmp_ver}" | sed \
	-e 's|\t|</name>\n\t<range><lt>|g'  \
	-e 's|^|    <package>\n\t<name>|g' \
	-e 's|$|</lt></range>\n    </package>|g')

	rm "${tmp_prod}" "${tmp_ver}" 2>/dev/null
}

# Try to retrieve information if a CVE identifier was provided
if [ -n "${CVE_ID}" ]; then
	check_dependencies
	init_providers
	get_cve_info "${CVE_ID}"
	create_packages_list
fi

if [ -n "${SA_ID}" ]; then
	get_sa_info
fi

awk '/^<\?/,/^<vuxml/ { print }' "${vuxml_file}" >> "${tmp}" || exit 1
cat << EOF >> "${tmp}" || exit 1
  <vuln vid="${vid}">
    <topic>${package_name} -- ${topic}</topic>
    <affects>
${package_list}
    </affects>
    <description>
        ${DESC_BODY}
    </description>
    <references>
      <cvename>${cvename}</cvename>
      <url>${cveurl}</url>
    </references>
    <dates>
      <discovery>${discovery_date}</discovery>
      <entry>${entry_date}</entry>
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
