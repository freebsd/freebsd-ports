#!/bin/sh

PATH="/usr/bin:/bin"; export PATH       

if grep -q nqs /etc/syslog.conf
then :
else
	echo "local0.*					/var/log/nqs" >> /etc/syslog.conf  
	echo ""
	echo "/etc/syslog.conf modified to support nqs (using local0.*)"
	echo ""
fi
