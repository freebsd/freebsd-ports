# Provider for the European Union Vulnerability Database
# https://euvd.enisa.europa.eu/

tmp_euvd=""

init_euvd() {
	tmp_euvd=$(mktemp "${TMPDIR:-/tmp}"/euvd_json_data.XXXXXXXXXX) || exit 1
	fetch -q -o "${tmp_euvd}" "https://euvdservices.enisa.europa.eu/api/enisaid?id=${CVE_ID}" || exit 1
}

cleanup_euvd() {
	rm -f "${tmp_euvd}" 2>/dev/null
}

get_cvename_from_euvd() {
	# EUVD response includes "aliases" (CVE ID if available)
	jq -r '.aliases // .id' "${tmp_euvd}"
}

get_cveurl_from_euvd() {
	echo "https://euvd.enisa.europa.eu/ui/vuln/${CVE_ID}"
}

get_details_from_euvd() {
	jq -r '.description // empty | @html' "${tmp_euvd}" | fmt -p -s | sed '1!s/^/\t/'
}

get_discovery_date_from_euvd() {
	raw=$(jq -r '.datePublished // empty' "${tmp_euvd}")
	if [ -n "$raw" ]; then
		trimmed=$(echo "$raw" | cut -d, -f1-2)
		if date -d "$trimmed" "+%Y-%m-%d" >/dev/null 2>&1; then
			date -d "$trimmed" "+%Y-%m-%d"
		else
			date -j -f "%b %d, %Y" "$trimmed" "+%Y-%m-%d"
		fi
	fi
}

get_entry_date_from_euvd() {
	echo "${entry_date}"
}


get_product_name_from_euvd() {
	jq -r ' .enisaIdProduct[]?.product?.name ' "${tmp_euvd}"
}

get_product_range_from_euvd() {
	jq -r '.enisaIdProduct[]?  | "\(.product_version? | gsub("<";"&lt;") | gsub(">";"&gt;") | gsub("&";"&amp;"))"' "${tmp_euvd}"
}

get_package_name_from_euvd() {
	jq -r '.enisaIdProduct[0]?.product?.name // empty' "${tmp_euvd}"
}

get_references_from_euvd() {
	jq -r '.references // empty | @html' "${tmp_euvd}" | tr " " "\n"
}

get_source_from_euvd() {
	jq -r '.assigner // empty | @html' "${tmp_euvd}"
}

get_topic_from_euvd() {
	# Use first sentence of description
	jq -r '.description // empty' "${tmp_euvd}" | cut -f1 -d.
}

