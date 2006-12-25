#!/bin/sh
#
# Pantera first time installation script.
#
# License (For this script only, not for Pantera): BSD.
#
# Bug reports & feature requests > onatan@gmail.com
#
# This script assumes the following:
# MySQL client and server are installed and useable.
# There is no Database named "pantera" (default name).
# User will take care of hardening database permissions after the installation
#     is finished.
#

# Feel free to change these, if you know what you're doing
DBNAME="pantera"
DBHOST="localhost"
DBUSER="root"
DBPASS=""


echo "==> Checking that MySQL server is available:"

if [ -n "${DBPASS}" ]; then
	PING=`mysqladmin -h ${DBHOST} -u ${DBUSER} -p=${DBPASS} ping`
else
	PING=`mysqladmin -h ${DBHOST} -u ${DBUSER} ping`
fi

if [ "mysqld is alive" != "${PING}" ]; then
	echo "Cannot connect to MySQL with user 'root' and no password."
	echo "Edit ${0} for different user and password."
	exit 1
fi


echo "==> Creating database schema named ${DBNAME}:"
if [ -n "${DBPASS}" ]; then
	mysqladmin -h ${DBHOST} -u ${DBUSER} -p=${DBPASS} create ${DBNAME}
	CRTDB=$?
else
	mysqladmin -h ${DBHOST} -u ${DBUSER} create ${DBNAME}
	CRTDB=$?
fi

if [ "0" -ne "${CRTDB}" ]; then
	echo "Cannot create schema. Maybe it is already there."
	echo "If you want to drop it, use:"
	echo "mysqladmin drop ${DBNAME}"
	echo "with the proper user-name and password."
	exit 1
fi


echo "==> Identifying Schema file:"

# Hack to get DATADIR:
TMP1=`which pantera.sh`
TMP2=`grep "^cd /" ${TMP1}`
TMP3=`echo "${TMP2}" | sed "s/^cd //" `

DATADIR=$TMP3
SCHEMA_FILE=${DATADIR}/doc/pantera_sql_create_script.txt
if [ ! -r ${SCHEMA_FILE} ]; then
	echo "Cannot identify schema file."
	echo "I guessed it would be at:"
	echo "${SCHEMA_FILE}"
	echo "but it was not there, or not readable."
	echo "If you know where it is, set SCHEMA_FILE variable manually."
	exit 1
fi


echo "==> Installing schema:"

if [ -n "${DBPASS}" ]; then
	mysql -h ${DBHOST} -u ${DBUSER} -p=${DBPASS} ${DBNAME} < ${SCHEMA_FILE}
	INSTSCHM=$?
else
	mysql -h ${DBHOST} -u ${DBUSER} ${DBNAME} < ${SCHEMA_FILE}
	INSTSCHM=$?
fi

if [ "0" -ne "${INSTSCHM}" ]; then
	echo "Cannot install schema."
	echo "Very weird - we should have failed earlier."
	exit 1
fi


echo "==> All Done!"
echo "If you made any changes to the user-name and password,"
echo "or plan to make these changes, update the panteracfg.xml file,"
echo "in ${DATADIR} ."
echo "It would also be a good idea to create a database-user for pantera,"
echo "GRANT this users rights on the \"${DBNAME}\" database schema,"
echo "and set a password for this user. See MySQL Documentation at"
echo "http://www.mysql.org/doc/ for more details."
echo "To use Pantera, run \"pantera.sh\", and set the IP address of"
echo "this machine, and port 8080, to your browsers proxy."
