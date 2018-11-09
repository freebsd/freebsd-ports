#!/bin/sh

if [ $# -lt 3 ]; then
    echo "Too few arguments"
    echo "Usage: `basename $0` <ossec_type> <ossec_prefix> <ossec_file>"
    exit 1
fi

ossec_type="$1"
ossec_prefix="$2"
ossec_file="$3"

if [ ! -f "${ossec_file}" ]; then
    echo "File \"${ossec_file}\" does not exist"
    exit 1
fi

ossec_syscheck_bin_dirs="${ossec_prefix}/bin,${ossec_prefix}/active-response"
ossec_syscheck_etc_dirs="${ossec_prefix}/etc"
if [ "${ossec_type}" != "agent" ]; then
    ossec_syscheck_bin_dirs="${ossec_syscheck_bin_dirs},${ossec_prefix}/agentless"
    ossec_syscheck_etc_dirs="${ossec_syscheck_etc_dirs},${ossec_prefix}/rules"
fi

replace() {
    if grep -q "<template_config>" "${ossec_file}"; then
        sed -e 's|<template_config>|<ossec_config>|' \
            -e 's|</template_config>|</ossec_config>|' \
            -e "s|%%OSSEC_SYSCHECK_BIN_DIRS%%|${ossec_syscheck_bin_dirs}|" \
            -e "s|%%OSSEC_SYSCHECK_ETC_DIRS%%|${ossec_syscheck_etc_dirs}|" \
            "${ossec_file}"
    else
        sed -e 's|<template_config .*os="FreeBSD".*>|<ossec_config>|' \
            -e 's|</template_config>|</ossec_config>|' \
            -e "s|%%OSSEC_SYSCHECK_BIN_DIRS%%|${ossec_syscheck_bin_dirs}|" \
            -e "s|%%OSSEC_SYSCHECK_ETC_DIRS%%|${ossec_syscheck_etc_dirs}|" \
            "${ossec_file}"
    fi
}

extract() {
    sed -n '/^<ossec_config.*>$/,/^<\/ossec_config>$/p'
}

replace | extract
