#! /bin/sh
LS="/bin/ls"
VXQUERY="vxquery"
PORTSDIR="${PORTSDIR:-/usr/ports}"
PKGDIR="${PKGDIR:-/var/db/pkg}"
FORMAT="${FORMAT:-text}"
VULN_XML="${VULN_XML:-${PORTSDIR}/security/vuxml/vuln.xml}"

set -e
(cd "$PKGDIR" && "${LS}") | "${VXQUERY}" -f - -t "${FORMAT}" "${VULN_XML}"
