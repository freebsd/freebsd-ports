#! /bin/sh
vuxml_file="$1"
if [ -z "${vuxml_file}" ]; then
  exec >&2
  echo "Usage: newentry.sh /path/to/vuxml/document"
  exit 1
fi

tmp="`mktemp -t vuxml`"
[ "$?" -eq 0 ] || exit 1
doclean="yes"
cleanup() {
  if [ "${doclean}" = "yes" ]; then
    rm -f "${tmp}"
  fi
}
trap cleanup EXIT 1 2 13 15

set errexit
vid="`uuidgen | tr '[:upper:]' '[:lower:]'`"
discovery="`date -u '+%Y-%m'`-FIXME"
entry="`date -u '+%Y-%m-%d'`"

awk '/^<\?/,/^<vuxml/ { print }' "${vuxml_file}" >> "${tmp}"
cat << EOF >> "${tmp}"
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
    </references>
    <dates>
      <discovery>${discovery}</discovery>
      <entry>${entry}</entry>
    </dates>
  </vuln>

EOF
awk '/^[[:space:]]+<vuln /,/^NONE$/ { print }' "${vuxml_file}" >> "${tmp}"

set noerrexit

if cp "${tmp}" "${vuxml_file}"; then
  exec >&2
  echo "Template entry added.  Please edit \`${vuxml_file}'."
  exit 0
else
  doclean="no"
  exec >&2
  echo "Could not overwrite \`${vuxml_file}'."
  echo "Results are left in \`${tmp}'."
  exit 1
fi
