#!/bin/sh

if grep -q nqs /etc/syslog.conf
then :
else
	echo "local0.*					/var/log/nqs" >> /etc/syslog.conf  
	echo ""
	echo "/etc/syslog modified to support nqs"
	echo ""
fi
