#!/bin/sh

# This is the DTC's BSD interactive install configuration script
# called by the make install
# made by Thomas Goirand <thomas@goirand.fr> and Frederic Cambus


PREFIX=%%PREFIX%%
LOCALBASE=%%LOCALBASE%%
QMAIL_DIR=%%QMAIL_DIR%%

UID=`id -u`

if [ $UID -ne 0 ]
then
	echo "##### WARNING #####"
	echo ""
	echo "In order to work correctly, the"
	echo "installation program should be run"
	echo "as root. Press ENTER to continue"
	echo "anyway or CTRL-C to abort process."
	read XX
fi

# DATABASE CONFIGURATION
PSMYSQL=`pgrep -n mysqld`

while [ "$PSMYSQL" = "" ]
do
	echo ""
	echo "### MYSQL CONFIGURATION ###"
	echo ""
	echo "WARNING: Your MySQL Server MUST be running."
	echo "If not, please add mysql_enable=\"YES\" in your"
	echo "/etc/rc.conf and issue the following cmd:"
	echo "%%PREFIX%%/etc/rc.d/mysql-server start"
	echo ""
	echo "Press ENTER to continue, CTRL-C to abort install"
	echo "or start and ENTER to have MySQL started for you"
	startmysql=""
	read startmysql

	if [ "$startmysql" = start ]
	then
		echo "Starting MySQL"
		if grep mysql_enable /etc/rc.conf
		then
			echo "Skipping /etc/rc.conf already configured."
		else
			echo "Backing up /etc/rc.conf."
			cp /etc/rc.conf /etc/rc.conf.DTC.Backup
			echo "### Configured by DTC 0.31 - please do not remove" >>/etc/rc.conf
			echo "mysql_enable=\"YES\"" >>/etc/rc.conf
		fi
		%%PREFIX%%/etc/rc.d/mysql-server start
		#Let MySQL finish starting and show on ps
		sleep 5
	fi
	PSMYSQL=`ps -axf|grep mysqld|grep -v grep|awk '{print $1}'`
done

. %%WWWDIR%%/admin/install/bsd_config
. %%WWWDIR%%/admin/install/interactive_installer
. %%WWWDIR%%/admin/install/functions

enableBsdBind
copyBsdPhpIni
interactiveInstaller
DTCsetupDaemons
