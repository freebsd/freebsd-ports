#!/bin/sh
# $FreeBSD$

if [ -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc ]; then
	exit
fi

tempfile=`/usr/bin/mktemp -t checklist`

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
IMAP		"IMAP support" OFF \
MySQL		"MySQL database support" ON \
PostgreSQL	"PostgreSQL database support" OFF \
SybaseDB	"Sybase/MS-SQL database support (DB-lib)" OFF \
SybaseCT	"Sybase/MS-SQL database support (CT-lib)" OFF \
Interbase	"Interbase 6 database support (Firebird)" OFF \
dBase		"dBase database support" OFF \
OpenLDAP	"OpenLDAP support" OFF \
SNMP		"SNMP support" OFF \
XML		"XML support" OFF \
FTP		"File Transfer Protocol support" OFF \
gettext		"gettext library support" OFF \
YP		"YP/NIS support" OFF \
sysvsem		"System V semaphore support" OFF \
sysvshm		"System V shared memory support" OFF \
2> $tempfile

	retval=$?

	if [ -s $tempfile ]; then
		set `cat $tempfile`
	fi
	rm -f $tempfile

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

${MKDIR} ${WRKDIRPREFIX}${REALCURDIR}
exec > ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"GD\")
			echo "LIB_DEPENDS+=	gd.4:\${PORTSDIR}/graphics/gd"
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
			echo "mcrypt support doesn't compile at the moment. Ignoring." > /dev/stderr
			;;
		\"nothing\")
			echo "LIB_DEPENDS+=	mcrypt.8:\${PORTSDIR}/security/libmcrypt"
			echo "CONFIGURE_ARGS+=--with-mcrypt=\${PREFIX}"
			;;
		\"mhash\")
			echo "LIB_DEPENDS+=	mhash.2:\${PORTSDIR}/security/mhash"
			echo "CONFIGURE_ARGS+=--with-mhash=\${PREFIX}"
			;;
		\"IMAP\")
			echo "LIB_DEPENDS+=	c-client4.8:\${PORTSDIR}/mail/cclient"
			echo "CONFIGURE_ARGS+=--with-imap=\${PREFIX}"
			;;
		\"MySQL\")
			echo "LIB_DEPENDS+=	mysqlclient.10:\${PORTSDIR}/databases/mysql323-client"
			echo "CONFIGURE_ARGS+=--with-mysql=\${PREFIX}"
			MYSQL=1
			;;
		\"PostgreSQL\")
			echo "POSTGRESQL_PORT?=	databases/postgresql7"
			echo "LIB_DEPENDS+=	pq.3:\${PORTSDIR}/\${POSTGRESQL_PORT}"
			echo "CONFIGURE_ARGS+=--with-pgsql=\${PREFIX}"
			if /usr/bin/ldd ${PREFIX}/bin/postgres | /usr/bin/grep -q "libssl"; then
				LIBS="-lcrypto -lssl"
			fi
			;;
		\"SybaseDB\")
			echo "LIB_DEPENDS+=	sybdb.1:\${PORTSDIR}/databases/freetds"
			echo "LIB_DEPENDS+=	iconv.3:\${PORTSDIR}/converters/libiconv"
			echo "CONFIGURE_ARGS+=--with-sybase=\${PREFIX}"
			LIBS="${LIBS} -L\${LOCALBASE}/lib -liconv"
			if [ "$SYBASECT" ]; then
				echo "SybaseDB and SybaseCT are mutually exclusive." > /dev/stderr
				rm -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc
				exit 1
			fi
			SYBASEDB=1
			;;
		\"SybaseCT\")
			echo "LIB_DEPENDS+=	ct.0:\${PORTSDIR}/databases/freetds"
			echo "LIB_DEPENDS+=	iconv.3:\${PORTSDIR}/converters/libiconv"
			echo "CONFIGURE_ARGS+=--with-sybase-ct=\${PREFIX}"
			LIBS="${LIBS} -L\${LOCALBASE}/lib -liconv"
			if [ "$SYBASEDB" ]; then
				echo "SybaseDB and SybaseCT are mutually exclusive." > /dev/stderr
				rm -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc
				exit 1
			fi
			SYBASECT=1
			;;
		\"Interbase\")
			echo "LIB_DEPENDS+=	gds.1:\${PORTSDIR}/databases/firebird"
			echo "CONFIGURE_ARGS+=--with-interbase=\${PREFIX}/firebird"
			LIBS="${LIBS} -L\${PREFIX}/firebird/lib"
			;;
		\"dBase\")
			echo "CONFIGURE_ARGS+=--with-dbase"
			;;
		\"OpenLDAP\")
			echo "LIB_DEPENDS+=	ldap.1:\${PORTSDIR}/net/openldap12"
			echo "LIB_DEPENDS+=	lber.1:\${PORTSDIR}/net/openldap12"
			echo "CONFIGURE_ARGS+=--with-ldap=\${PREFIX}"
			if [ -f /usr/lib/libkrb.a -a -f /usr/lib/libdes.a -a ! -L /usr/lib/libdes.a ]; then
				LIBS="${LIBS} -lkrb -ldes -L\${PREFIX}/lib"
			fi
			;;
		\"SNMP\")
			echo "LIB_DEPENDS+=	snmp.4:\${PORTSDIR}/net/net-snmp"
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
		\"gettext\")
			echo "LIB_DEPENDS+=	intl.5:\${PORTSDIR}/devel/gettext"
			echo "CONFIGURE_ARGS+=--with-gettext=\${PREFIX}"
			;;
		\"YP\")
			echo "CONFIGURE_ARGS+=--with-yp"
			;;
		\"sysvsem\")
			echo "CONFIGURE_ARGS+=--enable-sysvsem"
			;;
		\"sysvshm\")
			echo "CONFIGURE_ARGS+=--enable-sysvshm"
 			;;
		*)
			echo "Invalid option(s): $*" > /dev/stderr
			rm -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc
			exit 1
			;;
	esac
	shift
done

if [ "${LIBS}" ]; then
	echo "CONFIGURE_ENV+=	LIBS='${LIBS}'"
fi

if [ -z "${MYSQL}" ]; then
	echo "WITHOUT_MYSQL=	1"
fi
