#!/bin/sh
#$FreeBSD$
#SAMS database setup script
TMP=./tmp

. ${TMP}/config.cashe

  CONFIGFILEPATH="${CONFIG_FILE}"
  if [ ! -f ${CONFIG_FILE} -a -f ${CONFIG_FILE}.sample ]; then
  	echo "You must copy ${CONFIG_FILE}.sample into ${CONFIG_FILE} first"
	exit
  fi

  if [ ! -f ${CONFIG_FILE} -a ! -f ${CONFIG_FILE}.sample ]; then
	echo "Install SAMS (type \"make install\") before setup it"
	exit
  fi

##################################################################
#
#   Create SAMS user and databases
#
##################################################################
CreateSAMSDatabases()
{
# Some defaults
MYSQLHOSTNAME="localhost"
MYSQLPASSWORD="samspasswd"
MYSQLVERSION="4.0"
SQUIDCACHEFILE="access.log"

stty_orig=`stty -g`
clear
echo "This master will help you to setup SAMS database and configuration"
echo "Enter mysql-server hostname:"
echo -n "[${MYSQLHOSTNAME}]: "
read var
[ "$var" != "" ] && MYSQLHOSTNAME=$var
echo "Hostname is ${MYSQLHOSTNAME}"
echo ""
echo "Print MySQL root password."
echo -n "[]: "
stty -echo
read var
stty $stty_orig
echo ""

if [ "$var" != "" ]; then 
	ROOTPASS=$var
fi

unset var

while [ "$var" != "yes" -a "$var" != "no" ]; do
	echo "Create SAMS user for MySQL database (yes/no)?"
	echo -n "[yes]: "
	read var
	if [ "$var" = "yes" -o "$var" = "" ]; then 
		SAMSUSER=1
		var="yes"
	else if [ "$var" = "no" ]; then 
		SAMSUSER=0
	fi; fi
done

echo "Create MySQL SAMS user"
pass1="a"

while [ "$pass1" != "$pass2" ]; do
echo "Enter NEW password for SAMS MySQL user."
echo -n "[]: "
stty -echo
read pass1
stty $stty_orig
echo "Retype password."
echo -n "[]: "
stty -echo
read pass2
stty $stty_orig

	[ "$pass1" != "$pass2" ] && echo "Passwords don't match"
done
MYSQLPASSWORD=${pass1}

unset var

while [ "$var" != "yes" -a "$var" != "no" ]; do
	echo "Create SAMS database (yes/no)?"
	echo -n "[yes]: "
	read var
	if [ "$var" = "yes" -o "$var" = "" ]; then 
		SAMSBASE=1
		var="yes"
	else if [ "$var" = "no" ]; then 
		SAMSBASE=0
	fi; fi
done

unset var

while [ "$var" != "yes" -a "$var" != "no" ]; do
echo -e "Insert parameters into \n$CONFIGFILEPATH?"
	echo -n "[yes]: "
	read var
	if [ "$var" = "yes" -o "$var" = "" ]; then 
		EDITCONF=1
		var="yes"
	else if [ "$var" = "no" ]; then 
		EDITCONF=0
fi; fi
done

if [ ${SAMSUSER} -eq 1 ]; then
	mysql -u root --password="$ROOTPASS" \
--execute="GRANT ALL ON squidctrl.* TO sams@localhost IDENTIFIED BY \"${MYSQLPASSWORD}\";"
	mysql -u root --password="$ROOTPASS" \
--execute="GRANT ALL ON squidlog.* TO sams@localhost IDENTIFIED BY \"${MYSQLPASSWORD}\";"
fi
  
if [ ${SAMSBASE} -eq 1 ]; then
	mysql -u root -h ${MYSQLHOSTNAME} \
		--password="$ROOTPASS" <./mysql/sams_db.sql 
	mysql -u root -h ${MYSQLHOSTNAME} \
		--password="$ROOTPASS" <./mysql/squid_db.sql 
fi

if [ ${EDITCONF} -eq 1 ]; then
     echo "MYSQLUSER=sams" >>  $CONFIGFILEPATH
     echo "MYSQLPASSWORD=${MYSQLPASSWORD}" >> $CONFIGFILEPATH
	 echo "MYSQLHOSTNAME=${MYSQLHOSTNAME}" >> $CONFIGFILEPATH
fi
return
}


CreateSAMSDatabases


echo "Basic setup done. Don't forget to edit"
echo "$CONFIGFILEPATH manually for detailed configuration"
