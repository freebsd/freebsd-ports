#! /bin/sh
tidy_file="$1"
vuxml_file="$2"
if [ -z "${vuxml_file}" -o -z "${tidy_file}" ]; then
  exec >&2
  echo "Usage: tidy.sh /path/to/tidy.xsl /path/to/vuxml/document"
  exit 1
fi

X=`/usr/bin/which xsltproc`
if [ -z "$X" ]; then
  exec >&2
  echo "Could not find \`xsltproc\'."
  echo "Install ports/textproc/libxslt."
  exit 1
fi

xsltproc --novalid "${tidy_file}" "${vuxml_file}"
