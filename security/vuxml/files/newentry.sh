#! /bin/sh
vuxml_file="$1"
if [ -z "${vuxml_file}" ]; then
  exec >&2
  echo "Usage: newentry.sh /path/to/vuxml/document"
  exit 1
fi

tmp="`mktemp ${TMPDIR:-/tmp}/vuxml.XXXXXXXXXX`" || exit 1
doclean="yes"
cleanup() {
  if [ "${doclean}" = "yes" ]; then
    rm -f "${tmp}"
  fi
}
trap cleanup EXIT 1 2 13 15

vid="`uuidgen | tr '[:upper:]' '[:lower:]'`"
[ -z "$vid" ] && exit 1
discovery="`date -u '+%Y-%m'`-FIXME" || exit 1
entry="`date -u '+%Y-%m-%d'`" || exit 1

awk '/^<\?/,/^<vuxml/ { print }' "${vuxml_file}" >> "${tmp}" || exit 1
cat << EOF >> "${tmp}" || exit 1
  <vuln vid="${vid}">
    <topic> -- </topic>
    <affects>
      <package>
	<name></name>
	<range><lt></lt></range>
      </package>
    </affects>
    <description>
      <body xmlns="http://www.w3.org/1999/xhtml">
	<p>SO-AND-SO reports:</p>
	<blockquote cite="INSERT URL HERE">
	  <p>.</p>
	</blockquote>
      </body>
    </description>
    <references>
      <url>INSERT SAME URL HERE</url>
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
