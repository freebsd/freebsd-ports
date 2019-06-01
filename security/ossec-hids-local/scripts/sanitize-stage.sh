#!/bin/sh

# Script removes paths from stage to make stage-qa happy about "orphaned" files

OSSEC_TYPE=$1
OSSEC_HOME=$2
STAGEDIR=$3

. $(dirname "$0")/plist.conf

NL=$'\n'
IFS=${NL}

for path in ${skip_paths}; do
    rm -rf "${STAGEDIR}${OSSEC_HOME}${path}"
done
