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

replace() {
    sed -e 's|<template_config \(.*\)>|<agent_config \1>|' \
        -e 's|</template_config>|</agent_config>|' \
        -e "s|%%OSSEC_SYSCHECK_BIN_DIRS%%|${ossec_syscheck_bin_dirs}|" \
        -e "s|%%OSSEC_SYSCHECK_ETC_DIRS%%|${ossec_syscheck_etc_dirs}|" \
        "${ossec_file}"
}

extract() {
    sed -n '/^<agent_config .*>$/,/^<\/agent_config>$/p'
}

replace | extract
