# Provider for the National Vulnerability Database
# https://nvd.nist.gov/

tmp_nvd=""

init_nvd()
{
	tmp_nvd=$(mktemp "${TMPDIR:-/tmp}"/nvd_json_data.XXXXXXXXXX) || exit 1
	fetch -q -o "${tmp_nvd}" https://services.nvd.nist.gov/rest/json/cves/2.0?cveId="${CVE_ID}" || exit 1
}

cleanup_nvd()
{
	rm "${tmp_nvd}" 2>/dev/null
}

get_cvename_from_nvd()
{
	cvename="${CVE_ID}"
	echo "${cvename}"
}

get_cveurl_from_nvd() {
	cveurl=https://nvd.nist.gov/vuln/detail/${CVE_ID}
	echo "${cveurl}"
}

get_details_from_nvd() {
	pref=".vulnerabilities[0]?.cve?"
	jq -r "${pref}.descriptions[0]?.value|@html" "${tmp_nvd}" | fmt -p -s | sed '1!s/^/\t/'
}

get_discovery_date_from_nvd() {
	pref=".vulnerabilities[0]?.cve?"
	jq -r "${pref}.published|@html" "${tmp_nvd}" | cut -f1 -dT
}

get_entry_date_from_nvd() {
	echo "${entry_date}"
}

get_product_name_from_nvd() {
	jq -r '.vulnerabilities[]?.cve?.configurations[]?.nodes[]?.cpeMatch[]? |
		       (.criteria | split(":")[4])' "${tmp_nvd}"
}

get_product_range_from_nvd() {
	jq -r '.vulnerabilities[]?.cve.configurations[]?.nodes[]?.cpeMatch[]?.versionEndExcluding ' "${tmp_nvd}"
}

get_package_name_from_nvd() {
	jq -r '.vulnerabilities[]?.cve?.configurations[]?.nodes[]?.cpeMatch[0]?.criteria' "${tmp_nvd}" | cut -f5 -d:
}

get_references_from_nvd() {
	pref=".vulnerabilities[0]?.cve?.references[0]?"
	jq -r "${pref}.url|@html" "${tmp_nvd}" | tr " " "\n"
}

get_source_from_nvd()
{
	pref=".vulnerabilities[0]?.cve?.references[0]?"
	jq -r "${pref}.source|@html" "${tmp_nvd}" | tr " " "\n"
}

get_topic_from_nvd() {
	# NVD does not provide a nice summary. Let's use the first sentence from
	# the details instead
	pref=".vulnerabilities[0]?.cve?"
	jq -r "${pref}.descriptions[0]?.value|@html" "${tmp_nvd}" | cut -f1 -d.
}

