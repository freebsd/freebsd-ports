#!/bin/sh
# $FreeBSD$

if [ -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc ]; then
	exit
fi

if [ "${BATCH}" ]; then
	set \"zlib\" \"MySQL\"
else
	/usr/bin/dialog --title "configuration options" --clear \
		--checklist "\n\
Please select desired options:" -1 -1 16 \
GD		"GD library support" OFF \
FreeType	"TrueType font rendering (implies GD)" OFF \
zlib		"zlib library support" ON \
mcrypt		"Encryption support" OFF \
mhash		"Crypto-hashing support" OFF \
pdflib		"pdflib support (implies zlib)" OFF \
IMAP		"IMAP support" OFF \
MySQL		"MySQL database support" ON \
PostgreSQL	"PostgreSQL database support" OFF \
mSQL		"mSQL database support" OFF \
SybaseDB	"Sybase/MS-SQL database support (DB-lib)" OFF \
SybaseCT	"Sybase/MS-SQL database support (CT-lib)" OFF \
dBase		"dBase database support" OFF \
OpenLDAP	"OpenLDAP support" OFF \
SNMP		"SNMP support" OFF \
XML		"XML support" OFF \
FTP		"File Transfer Protocol support" OFF \
2> /tmp/checklist.tmp.$$

	retval=$?

	if [ -s /tmp/checklist.tmp.$$ ]; then
		set `cat /tmp/checklist.tmp.$$`
	fi
	rm -f /tmp/checklist.tmp.$$

	case $retval in
		0)	if [ -z "$*" ]; then
				echo "Nothing selected"
			fi
			;;
		1)	echo "Cancel pressed."
			exit 1
			;;
	esac
fi

${MKDIR} ${WRKDIRPREFIX}${CURDIR}
exec > ${WRKDIRPREFIX}${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"GD\")
			echo "LIB_DEPENDS+=	gd.0:\${PORTSDIR}/graphics/gd"
			echo "CONFIGURE_ARGS+=--with-gd=\${PREFIX}"
			GD=1
			;;
		\"FreeType\")
			echo "LIB_DEPENDS+=	ttf.4:\${PORTSDIR}/print/freetype"
			echo "CONFIGURE_ARGS+=--with-ttf=\${PREFIX}"
			if [ -z "$GD" ]; then
				set $* \"GD\"
			fi
			;;
		\"zlib\")
			echo "CONFIGURE_ARGS+=--with-zlib"
			ZLIB=1
			;;
		\"mcrypt\")
			echo "LIB_DEPENDS+=	mcrypt-2.2.2:\${PORTSDIR}/security/libmcrypt"
			echo "CONFIGURE_ARGS+=--with-mcrypt=\${PREFIX}"
			;;
		\"mhash\")
			echo "mhash is DISABLED for now. Ignoring." > /dev/stderr
			;;
		\"nothing\")
			echo "LIB_DEPENDS+=	mhash.1:\${PORTSDIR}/security/mhash"
			echo "CONFIGURE_ARGS+=--with-mhash=\${PREFIX}"
			;;
		\"pdflib\")
			echo "LIB_DEPENDS+=	pdf.2:\${PORTSDIR}/print/pdflib"
			echo "CONFIGURE_ARGS+=--with-pdflib=\${PREFIX} \\"
			echo "		--with-jpeg-dir=\${PREFIX} \\"
			echo "		--with-tiff-dir=\${PREFIX}"
			if [ -z "$ZLIB" ]; then
				set $* \"zlib\"
			fi
			;;
		\"IMAP\")
			echo "LIB_DEPENDS+=	c-client4.7:\${PORTSDIR}/mail/imap-uw"
			echo "CONFIGURE_ARGS+=--with-imap=\${PREFIX}"
			;;
		\"MySQL\")
			echo "LIB_DEPENDS+=	mysqlclient.6:\${PORTSDIR}/databases/mysql322-client"
			echo "CONFIGURE_ARGS+=--with-mysql=\${PREFIX}"
			;;
		\"PostgreSQL\")
			echo "LIB_DEPENDS+=	pq.2:\${PORTSDIR}/databases/postgresql"
			echo "CONFIGURE_ARGS+=--with-pgsql=\${PREFIX}/pgsql"
			;;
		\"mSQL\")
			echo "BUILD_DEPENDS+=	msql:\${PORTSDIR}/databases/msql"
			echo "CONFIGURE_ARGS+=--with-msql=\${PREFIX}"
			;;
		\"SybaseDB\")
			echo "LIB_DEPENDS+=	sybdb.0:\${PORTSDIR}/databases/freetds"
			echo "CONFIGURE_ARGS+=--with-sybase=\${PREFIX}"
			if [ "$SYBASECT" ]; then
				echo "SybaseDB and SybaseCT are mutually exclusive." > /dev/stderr
				rm -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
				exit 1
			fi
			SYBASEDB=1
			;;
		\"SybaseCT\")
			echo "LIB_DEPENDS+=	ct.0:\${PORTSDIR}/databases/freetds"
			echo "CONFIGURE_ARGS+=--with-sybase-ct=\${PREFIX}"
			if [ "$SYBASEDB" ]; then
				echo "SybaseDB and SybaseCT are mutually exclusive." > /dev/stderr
				rm -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
				exit 1
			fi
			SYBASECT=1
			;;
		\"dBase\")
			echo "CONFIGURE_ARGS+=--with-dbase"
			;;
		\"OpenLDAP\")
			echo "LIB_DEPENDS+=	ldap.1:\${PORTSDIR}/net/openldap"
			echo "LIB_DEPENDS+=	lber.1:\${PORTSDIR}/net/openldap"
			echo "CONFIGURE_ARGS+=--with-ldap=\${PREFIX}"
			if [ -f /usr/lib/libkrb.a -a -f /usr/lib/libdes.a -a ! -L /usr/lib/libdes.a ]; then
				echo "CONFIGURE_ENV+=	LIBS='-lkrb -ldes -L\${PREFIX}/lib'"
			fi
			;;
		\"SNMP\")
			echo "LIB_DEPENDS+=	snmp.4:\${PORTSDIR}/net/ucd-snmp"
			echo "CONFIGURE_ARGS+=--with-snmp=\${PREFIX} --enable-ucd-snmp-hack"
			;;
		\"XML\")
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/libexpat.a:\${PORTSDIR}/textproc/expat"
			echo "BUILD_DEPENDS+=	\${PREFIX}/include/xml/xmlparse.h:\${PORTSDIR}/textproc/expat"
			echo "BUILD_DEPENDS+=	\${PREFIX}/include/xml/xmltok.h:\${PORTSDIR}/textproc/expat"
			echo "CONFIGURE_ARGS+=--with-xml=\${PREFIX}"
			;;
		\"FTP\")
			echo "CONFIGURE_ARGS+=--with-ftp"
			;;
		*)
			echo "Invalid option(s): $*" > /dev/stderr
			rm -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			exit 1
			;;
	esac
	shift
done
