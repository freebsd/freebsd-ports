#!/bin/sh
#
# setup_aswiki: a script for setup the current directory for aswiki
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

ask_copy()
{
	local file ans
	file=$1

	if [ -f ./$file ]; then
		if ask_noyes "Overwrite $file?"; then
			ans=YES
		else
			ans=NO
		fi
	else
		ans=YES
	fi
	if [ $ans = "YES" ]; then
		install -m 644 __DATADIR__/$file .
	else
		echo "$file is untouched; you may update with __DATADIR__/$file."
	fi
	
}

echo "This script will setup current directory for aswiki."
if ask_noyes "Are you ready?"; then
	echo -n "Creating directories..."
	mkdir RCS session cache attach text
	echo "done."
	echo -n "Copying files..."
	ask_copy aswiki.conf
	ask_copy aswiki.cgi
	ask_copy default.css
	echo "done."
else
	echo "Stopped."
	exit 1
fi
