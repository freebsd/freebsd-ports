#!/bin/sh
OPERA_DIR="%%PREFIX%%/share/opera"
OPERA_PLUGIN_PATH="%%PREFIX%%/share/opera/plugins"
for plugin_dir in \
    %%PREFIX%%/lib/netscape-linux/plugins \
    %%PREFIX%%/linux-jdk1.3.1/jre/plugin/i386/ns4 \
    ;
do
    if [ -d "${plugin_dir}" ] ; then
        OPERA_PLUGIN_PATH="${OPERA_PLUGIN_PATH}:${plugin_dir}"
    fi
done
export OPERA_DIR OPERA_PLUGIN_PATH
exec %%DATADIR%%/bin/opera-static "$@"
