#!/bin/sh
#
# Automatically setup the loading of the module without polluting /boot/modules
SYSCTL_CONFIG=/etc/sysctl.conf
LOADER_CONFIG=/etc/rc.conf

sysctl kern.module_path | grep "[:space:;=]@@PREFIX@@/modules[;]\?\b" > /dev/null 2>&1; RESULT=$?
if [ ${RESULT} -eq 1 ]; then
	MODULE_PATH="`sysctl -n kern.module_path`;@@PREFIX@@/modules"
	sysctl "kern.module_path=${MODULE_PATH}"
else
	MODULE_PATH=`sysctl -n kern.module_path`
fi

grep "kern\.module_path" ${SYSCTL_CONFIG} > /dev/null 2>&1; RESULT=$?
if [ ${RESULT} -eq 0 ]; then
	# Variable present
	grep "kern\.module_path" ${SYSCTL_CONFIG} | grep "[:space:;=]@@PREFIX@@/modules[;]\?\b" ${SYSCTL_CONFIG} > /dev/null 2>&1; RESULT=$?
	if [ ${RESULT} -eq 1 ]; then
		# Not present in variable, so add
		ESC_PREFIX=`echo '@@PREFIX@@' | sed -e 's/\//\\\\\//g'`
		sed -i .orig -e 's/kern\.module_path[:space:]*=[:space:]*["]*\([[:alnum:][:space:]\.,;\/_-]*\)["]*/kern\.module_path="\1;'${ESC_PREFIX}'\/modules"/g' ${SYSCTL_CONFIG}
	fi
else
	# Not present.
	echo kern.module_path="${MODULE_PATH}" >> ${SYSCTL_CONFIG}
fi


kldstat -n fuse > /dev/null 2>&1; RESULT=$?
if [ ${RESULT} -eq 0 ]; then
	kldunload -n fuse > /dev/null 2>&1; RESULT=$?
	if [ ${RESULT} -ne 0 ]; then
		echo 'NOTICE: Failed to unload the Fuse module!'
		echo 'NOTICE: Is fuse.ko in use?'
	fi
fi

grep fusefs_enable ${LOADER_CONFIG} > /dev/null 2>&1; RESULT=$?
if [ ${RESULT} -eq 0 ]; then
	# Present, we should leave it alone
#	sed -e s/fusefs_enable.*/fuse_load=\"YES\"/g -i.orig ${LOADER_CONFIG}
else
	# Not present. First time install, so lets start it up
	echo 'fusefs_enable="YES"' >> ${LOADER_CONFIG}
fi

@@PREFIX@@/etc/rc.d/fusefs start > /dev/null 2>&1 ; RESULT=$?
if [ ${RESULT} -ne 0 ]; then
	echo 'NOTICE: Failed to load the Fuse module!'
	echo 'NOTICE: Unload and load Fuse module manually, or reboot.'
fi
