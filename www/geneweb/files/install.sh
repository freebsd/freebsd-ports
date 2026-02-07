#!/bin/sh

#
# Install GeneWeb in a user's home directory
#
# Hubert Tournier <hubert@frbsd.org>
#

echo -n "User's account: "
read USER

USER_HOME=`grep "^${USER}:" /etc/passwd | cut -d":" -f6`
if [ "${USER_HOME}" = "" ]
then	echo "Sorry. This user is unknown in the system."
	exit 1
fi
USER_GROUP=`grep "^${USER}:" /etc/passwd | cut -d":" -f4`

echo -n "User's public GeneWeb directory [${USER_HOME}/public_html/geneweb]: "
read PUB_DIR
if [ "${PUB_DIR}" = "" ]
then	PUB_DIR=${USER_HOME}/public_html/geneweb
fi

echo -n "User's private GeneWeb directory [${USER_HOME}/geneweb.db]: "
read PRIV_DIR
if [ "${PRIV_DIR}" = "" ]
then	PRIV_DIR=${USER_HOME}/geneweb.db
fi

echo -n "User's GEDCOM file [return for none]: "
read GEDCOM
if [ "${GEDCOM}" != "" -a ! -f "${GEDCOM}" ]
then	echo "Sorry. This file is unknown in the system."
	exit 1
fi

echo -n "User's GeneWeb database name [${USER}]: "
read DB_NAME
if [ "${DB_NAME}" = "" ]
then	DB_NAME=${USER}
fi

echo -n "Enable database history [no]: "
read DB_HISTORY
case $DB_HISTORY in
	y*) DB_HISTORY=yes ;;
	*) DB_HISTORY=no ;;
esac

echo -n "Disable database forum [no]: "
read DB_FORUM
case $DB_FORUM in
	y*) DB_FORUM=yes ;;
	*) DB_FORUM=no ;;
esac

mkdir ${PUB_DIR}
cat > ${PUB_DIR}/gw.cgi << EOF
#!/bin/sh
cd ${PRIV_DIR}/${DB_NAME}.gwb
/usr/local/bin/gwd -cgi -bd ${PRIV_DIR} -wd ${PRIV_DIR}/${DB_NAME}.gwb 2>/dev/null
EOF
chmod -R 755 ${PUB_DIR}
chown -R ${USER}:${USER_GROUP} ${PUB_DIR}

mkdir -p ${PRIV_DIR}/images/${DB_NAME}
chmod 755 ${PRIV_DIR}
chmod -R 777 ${PRIV_DIR}/images
if [ "${GEDCOM}" = "" ]
then	/usr/local/bin/gwc -o ${PRIV_DIR}/${DB_NAME}
else	/usr/local/bin/ged2gwb ${GEDCOM} -o ${PRIV_DIR}/${DB_NAME}
fi
if [ "${DB_HISTORY}" = "yes" ]
then	touch ${PRIV_DIR}/${DB_NAME}.gwb/history
	chmod 666 ${PRIV_DIR}/${DB_NAME}.gwb/history
fi
touch ${PRIV_DIR}/${DB_NAME}.gwb/forum
chmod 666 ${PRIV_DIR}/${DB_NAME}.gwb/forum
install -o ${USER} -g ${USER_GROUP} -m 644 -c /usr/local/share/geneweb/a.gwf ${PRIV_DIR}/${DB_NAME}.gwf
chmod -R a+w ${PRIV_DIR}/${DB_NAME}.gwb ${PRIV_DIR}/${DB_NAME}.lck
chown -R ${USER}:${USER_GROUP} ${PRIV_DIR}
if [ "${DB_FORUM}" = "yes" ]
then	chflags schg ${PRIV_DIR}/${DB_NAME}.gwb/forum
fi

cat << EOF
===================================================================================================
Now review the settings in ${PRIV_DIR}/${DB_NAME}.gwf

If your web server is Apache, make sure to include the following lines in your config file:
	<Directory ${PUB_DIR}>
	 Options ExecCGI
	 XBitHack on
	 AddHandler cgi-script .cgi
	</Directory>
then reload Apache and point your browser to http://your.machine/~${USER}`echo ${PUB_DIR}|sed s/.*public_html//"`/gw.cgi?b=${DB_NAME}
===================================================================================================
EOF

