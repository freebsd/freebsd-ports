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

. $(dirname "$0")/plist.conf

NL=$'\n'
IFS=${NL}

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
    if [ "${user}" = "${USER}" ]; then
        user=""
    fi
    local group=`stat -f "%Sg" "${full_path}"`
    if [ "${group}" = "${GROUP}" ]; then
        group=""
    fi
    local mode=`stat -f "%p" "${full_path}" | tail -c 5`
    echo "${command}(${user},${group},${mode}) %%OSSEC_HOME%%${path}" >> "${PLIST}"
}

contains() {
    local list="$1"
    local word="$2"

    for e in ${list}; do
        if [ "${e}" = "${word}" ]; then
            return 0
        fi
    done

    return 1
}

echo -n > "${PLIST}"

print_path

done_paths=""
while read line; do
    if ! contains "${skip_lines}" "${line}"; then
        path=""
        case ${line} in
            "@dir %%OSSEC_HOME%%"*)
                path=`echo "${line}" | sed -E 's|@dir %%OSSEC_HOME%%||g'`
                ;;
            "%%OSSEC_HOME%%"*)
                path=`echo "${line}" | sed -E 's|%%OSSEC_HOME%%||g'`
                ;;
            "%%"*)
                unchanged_lines="${unchanged_lines}${NL}${line}"
                ;;
        esac
        if [ -n "${path}" ]; then
            segments=`echo "${path}" | tr "/" "\n"`
            path=""
            for segment in ${segments}; do
                path="${path}/${segment}"
                if contains "${skip_paths}" "${path}"; then
                    break
                fi
                if ! contains "${done_paths}" "${path}"; then
                    done_paths="${done_paths}${NL}${path}"
                    if contains "${sample_paths}" "${path}"; then
                        print_path "${path}" @sample
                    else
                        print_path "${path}"
                    fi
                fi
            done
        fi
    fi
done < "${WORKDIR}/.staged-plist"

unchanged_lines="${unchanged_lines}${NL}${fixed_lines}"
for line in ${unchanged_lines}; do
    echo "${line}" >> "${PLIST}"
done
