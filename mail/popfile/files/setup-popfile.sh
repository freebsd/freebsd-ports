#!/bin/sh
#
# setup-popfile.sh: a script for setup popfile instance
# $FreeBSD$
#

ask_noyes()
{
	local key

	echo -n "$1 [y/N]: "
	read key
	case "$key" in
	[Yy]*)
		return 0;;
	*)
		return 1;;
	esac
} 

echo "This script will 1) create 'popfile' directory and 2) setup 'popfile' directory for your popfile instance."
if ask_noyes "Are you ready?"; then
	mkdir ./popfile
	if [ -d ./popfile ]; then
		cp -R __DATADIR__/* ./popfile
	fi
	echo "done."
else
	echo "Stopped."
	exit 1
fi
