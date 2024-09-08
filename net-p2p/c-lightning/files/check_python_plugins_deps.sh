#!/usr/bin/env bash

set -e

declare -A requirements=(["plugins/clnrest/requirements.txt"]="CLNRESTDEPS_RUN_DEPENDS"
                         ["plugins/wss-proxy/requirements.txt"]="WSSPROXYDEPS_RUN_DEPENDS")

WRKSRC=$(make -V WRKSRC)

for file in ${!requirements[@]} ; do
    (cd ${WRKSRC}/$(dirname ${file}) && poetry export --output $(basename ${file}))
    make_var="${requirements[${file}]}"
    ok=1
    for req in $(grep -E '^[^[:space:]]' "${WRKSRC}/${file}" |cut -f 1 -d =) ; do
        # "cryptography" is handled separately via USE_PYTHON+=cryptography
        # "pkgutil-resolve-name" is included in Python 3.9
        if [ "${req}" != "cryptography" -a \
             "${req}" != "pkgutil-resolve-name" -a \
             -z "$(make -V "${make_var}" |grep -i "$(make -V PYTHON_PKGNAMEPREFIX)${req/-/.}>")" ] ; then

            echo "missing in ${file}: ${req}"
            ok=0
        fi
    done
    if [ ${ok} -eq 1 ] ; then
        echo "ok: ${make_var} matches ${WRKSRC}/${file}"
    fi
done
