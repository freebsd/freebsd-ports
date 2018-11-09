#!/bin/sh

# Script generates entries for pkg-plist.
# Do not use it directly. Use the following command instead:
#
# make MAINTAINER_MODE=yes clean plist

OSSEC_TYPE=$1
OSSEC_HOME=$2
PLIST=$3
WORKDIR=$4
STAGEDIR=$5

staged_plist="${WORKDIR}/.staged-plist"
fixed_lines=""
skip_lines=""
skip_paths=""
sample_paths="/etc/command.conf.sample /etc/ossec.conf.d/900.local.conf.sample /etc/agent.conf.d/900.local.conf.sample"

print_path() {
    local path="$1"
    local command="$2"
    local full_path="${STAGEDIR}${OSSEC_HOME}${path}"
    if [ -z "${command}" ]; then
        command="@"
        if [ -d "${full_path}" ]; then
            command="@dir"
        fi
    fi
    local user=`stat -f "%Su" "${full_path}"`
    if [ "${user}" == "${USER}" ]; then
        user=""
    fi
    local group=`stat -f "%Sg" "${full_path}"`
    if [ "${group}" == "${GROUP}" ]; then
        group=""
    fi
    local mode=`stat -f "%p" "${full_path}" | tail -c 5`
    echo -e "${command}(${user},${group},${mode}) %%OSSEC_HOME%%${path}" >> "${PLIST}"
}

echo -n > "${PLIST}"

print_path

done_paths=""
while read line; do
    skip_line=""
    for e in ${skip_lines}; do
        if [ "${e}" == "${line}" ]; then
            skip_line="${e}"
            break
        fi
    done
    if [ -z "${skip_line}" ]; then
        path=""
        case $line in
            "@dir %%OSSEC_HOME%%"*)
                path=`echo "${line}" | sed -e "s|@dir %%OSSEC_HOME%%||g"`
                ;;
            "%%OSSEC_HOME%%"*)
                path=`echo "${line}" | sed -e "s|%%OSSEC_HOME%%||g"`
                ;;
            "%%"*)
                unchanged_lines="${unchanged_lines} ${line}"
                ;;
        esac
        if [ -n "${path}" ]; then
            segments=`echo "${path}" | tr "/" "\n"`
            path=""
            for segment in ${segments}; do
                path="${path}/${segment}"
                skip_path=""
                for e in ${skip_paths}; do
                    if [ "${e}" == "${path}" ]; then
                        skip_path="${e}"
                        break
                    fi
                done
                if [ -n "${skip_path}" ]; then
                    break
                fi
                done_path=""
                for e in ${done_paths}; do
                    if [ "${e}" == "${path}" ]; then
                        done_path="${e}"
                        break
                    fi
                done
                if [ -z "${done_path}" ]; then
                    done_paths="${done_paths} ${path}"
                    sample_path=""
                    for e in ${sample_paths}; do
                        if [ "${e}" == "${path}" ]; then
                            sample_path="${e}"
                            break
                        fi
                    done
                    if [ -n "${sample_path}" ]; then
                        print_path "${path}" @sample
                    else
                        print_path "${path}"
                    fi
                fi
            done
        fi
    fi
done < "${staged_plist}"

unchanged_lines="${unchanged_lines} ${fixed_lines}"
for line in ${unchanged_lines}; do
    echo "${line}" >> "${PLIST}"
done
