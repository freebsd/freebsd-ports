# Provider for MITRE
# https://www.mitre.org/

tmp_mitre=""

init_mitre()
{
	tmp_mitre=$(mktemp "${TMPDIR:-/tmp}"/mitre.XXXXXXXXXX) || exit 1
	fetch -q -o "${tmp_mitre}" https://cveawg.mitre.org/api/cve/"${CVE_ID}"
}

cleanup_mitre()
{
	rm "${tmp_mitre}" 2>/dev/null
}

get_cvename_from_mitre()
{
	cvename="${CVE_ID}"
	echo "${cvename}"
}

get_cveurl_from_mitre() {
	echo https://cveawg.mitre.org/api/cve/"${CVE_ID}"
}

get_details_from_mitre() {
	jq -r '.containers?.cna?.descriptions[0]?.value' "${tmp_mitre}" | fmt -p -s
}

get_discovery_date_from_mitre() {
	jq -r '.cveMetadata?.datePublished?' "${tmp_mitre}" | cut -f1 -dT
}

get_entry_date_from_mitre() {
	echo "${entry_date}"
}

get_product_name_from_mitre() {
	jq -r '.containers?.cna?.affected[]?.product' "${tmp_mitre}"
}

get_product_range_from_mitre() {
	jq -r '.containers?.cna?.affected[]??.versions[0]?.lessThan' "${tmp_mitre}"
}

get_package_name_from_mitre() {
	jq -r '.containers?.cna?.affected[0]?.product' "${tmp_mitre}"
}

get_references_from_mitre() {
	jq -r '.containers?.cna?.references[0]?.url' "${tmp_mitre}" | fmt -p -s
}

get_source_from_mitre() {
	jq -r '.containers?.cna?.references[0]?.url' "${tmp_mitre}"
}

get_topic_from_mitre() {
	jq -r ".containers?.cna?.problemTypes[0]?.descriptions[0]?.description" "${tmp_mitre}"
}
