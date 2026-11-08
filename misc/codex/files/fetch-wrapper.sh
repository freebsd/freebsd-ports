#!/bin/sh

set -eu
set -o pipefail

PATH=/bin:/usr/bin:${LOCALBASE:=/usr/local}/bin

out=
url=
args=
substitution=

while [ $# -gt 0 ]; do
    case $1 in
        -S)
            shift 2
            continue
            ;;
        -o)
            out="$2"
            shift 2
            continue
            ;;
        https://*)
            url="$1"
            ;;
    esac
    args="${args} $1"
    shift
done

case ${url} in
    https://github.com/*/archive/*)
        substitution="|^[^/]*/||"
        fetch ${args} -o - | \
            tar -cf - \
                --mtime "@0" \
                --numeric-owner \
                --uid 0 --gid 0 \
                -s ${substitution} \
                @- | \
            gzip -n > ${out}
        ;;
    https://*.googlesource.com/*/+archive/*)
        substitution="|^||"
        fetch ${args} -o - | \
            tar -cf - \
                --mtime "@0" \
                --numeric-owner \
                --uid 0 --gid 0 \
                -s ${substitution} \
                @- | \
            gzip -n > ${out}
        ;;
    *)
        fetch ${args} -o ${out}
        ;;
esac
