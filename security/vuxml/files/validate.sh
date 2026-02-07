#! /bin/sh
vuxml_file="$1"
if [ -z "${vuxml_file}" ]; then
  exec >&2
  echo "Usage: validate.sh /path/to/vuxml/document"
  exit 1
fi

xml_catalog="${LOCALBASE:-/usr/local}/share/xml/catalog.ports"
sgml_catalog="${LOCALBASE:-/usr/local}/share/sgml/catalog.ports"

SGML_CATALOG_FILES="${sgml_catalog}"; export SGML_CATALOG_FILES
XML_CATALOG_FILES="${xml_catalog}"; export XML_CATALOG_FILES
SP_CHARSET_FIXED="YES"; export SP_CHARSET_FIXED
SP_ENCODING="XML"; export SP_ENCODING


X=`/usr/bin/which xmllint onsgmls`
if [ -z "$X" ]; then
  exec >&2
  echo "Could not find \`xmllint' nor \`onsgmls'."
  echo "Install ports/textproc/libxml2 for \`xmllint', or"
  echo "ports/textproc/opensp for \`onsgmls'."
  exit 1
fi

validate() {
  echo ">>> Validating..."
  echo "$@"
  if $@; then
    echo ">>> Successful."
    return 0
  else
    echo ">>> FAILED."
    return 1
  fi
}

for x in ${X}; do
  case ${x} in
  *xmllint)
    validate ${x} --valid --noout "${vuxml_file}"
    exit $?
    ;;
  *onsgmls)
    validate ${x} -wxml -s "${vuxml_file}"
    exit $?
    ;;
  *)
    echo "Oops, I don't know how to use \`${x}'."
    exit 1
    ;;
  esac
done
