#! /bin/sh
VXQUERY="vxquery"
PORTSDIR="${PORTSDIR:-/usr/ports}"
PKGDIR="${PKGDIR:-/var/db/pkg}"
FORMAT="${FORMAT:-text}"
VULN_XML="${VULN_XML:-${PORTSDIR}/security/vuxml/vuln.xml}"

set -e
cd "$PKGDIR"
echo * | "${VXQUERY}" -f - -t "${FORMAT}" "${VULN_XML}"
