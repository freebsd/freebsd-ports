#!/bin/sh

PATH="/usr/bin:/bin"; export PATH       

if grep -q nqs /etc/syslog.conf
then :
else
	echo 'You need to add a line as follows to /etc/syslog.conf'
	echo ''
	echo 'local0.*					/var/log/nqs'
	echo ''
fi
