#!/bin/sh

# Script generates entries for template-rules-default.xml.in.
# Do not use it directly. Use the following command instead:
#
# make MAINTAINER_MODE=yes rules

rules_template=$1
src_dir=$2

skip_files="policy_rules.xml local_rules.xml"
append_files="local_rules.xml"

rules=""
for file in `find "${src_dir}/etc/rules" -depth 1 -name "*.xml"`; do
    file_name="${file##*/}"
    skip_file=""
    for e in ${skip_files}; do
        if [ "${e}" == "${file_name}" ]; then
            skip_file="${e}"
            break
        fi
    done
    if [ -z "${skip_file}" ]; then
        rule_ids=`sed -Ene 's|^.*<rule[[:space:]]+id="([0-9]+)".*$|\1|p' "${file}"`
        if [ -n "${rule_ids}" ]; then
            min_rule_id=`echo "${rule_ids}" | sort -n | head -n 1`
            ref_rule_ids=`sed -Ene 's|^.*<if_sid>([0-9,]+)</if_sid>.*$|\1|p' "${file}" | tr ',' '\n'`
            for ref_rule_id in ${ref_rule_ids}; do
                found_rule_id=""
                for rule_id in ${rule_ids}; do
                    if [ "${ref_rule_id}" = "${rule_id}" ]; then
                        found_rule_id="${rule_id}"
                        break
                    fi
                done
                if [ -z "${found_rule_id}" ]; then
                    # The referenced rule id is not present in this file so it must come from another
                    if [ ${ref_rule_id} -gt ${min_rule_id} ]; then
                        # Ordering by referenced rule id doesn't need to give proper results, but let's hope it does
                        min_rule_id=$((ref_rule_id + 1))
                    fi
                fi
            done

            rules="${rules}${min_rule_id} ${file_name}
"
        fi
    fi
done

echo -n "${rules}" | sort -n

if [ -n "${rules_template}" ]; then
    rules=`echo -n "${rules}" | sort -n | cut -d' ' -f2`
    for file_name in ${append_files}; do
        rules="${rules}
${file_name}"
    done

    echo '<?xml version="1.0" encoding="UTF-8"?>
<template_config>

  <rules>' > "${rules_template}"

    for rule in ${rules}; do
        echo "    <include>${rule}</include>" >> "${rules_template}"
    done

    echo '
    <!-- Files not included by default -->' >> "${rules_template}"

    for skip_file in ${skip_files}; do
        append_file=""
        for e in ${append_files}; do
            if [ "${e}" == "${skip_file}" ]; then
                append_file="${e}"
                break
            fi
        done
        if [ -z "${append_file}" ]; then
            echo "    <!--<include>${skip_file}</include>-->" >> "${rules_template}"
        fi
    done

    echo '  </rules>

</template_config>' >> "${rules_template}"
fi
