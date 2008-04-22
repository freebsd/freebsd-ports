#!/bin/sh

# This is the DTC's BSD interactive install configuration script
# called by the make install
# made by Thomas Goirand <thomas@goirand.fr> and Frederic Cambus


PREFIX=%%PREFIX%%
LOCALBASE=%%LOCALBASE%%
QMAIL_DIR=%%QMAIL_DIR%%

# DATABASE CONFIGURATION
echo "### MYSQL CONFIGURATION ###"
echo ""
echo "WARNING: Your MySQL Server MUST be running."
echo "If not, please add mysql_enable=\"YES\" in your"
echo "/etc/rc.conf and issue the following cmd:"
echo "/usr/local/etc/rc.d/mysql-server start"
echo ""

. ${LOCALBASE}/www/dtc/admin/install/bsd_config
. ${LOCALBASE}/www/dtc/admin/install/interactive_installer
. ${LOCALBASE}/www/dtc/admin/install/functions

enableBsdBind
copyBsdPhpIni
interactiveInstaller
DTCinstallPackage
DTCsetupDaemons
