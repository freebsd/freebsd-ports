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
pdflib		"pdflib support (implies zlib)" OFF \
IMAP		"IMAP support" OFF \
MySQL		"MySQL database support" ON \
PostgreSQL	"PostgreSQL database support" OFF \
SybaseDB	"Sybase/MS-SQL database support (DB-lib)" OFF \
SybaseCT	"Sybase/MS-SQL database support (CT-lib)" OFF \
Interbase	"Interbase 6 database support (Firebird)" OFF \
dBase		"dBase database support" OFF \
OpenLDAP	"OpenLDAP support" OFF \
OpenSSL		"OpenSSL support" OFF \
SNMP		"SNMP support" OFF \
XML		"XML support" OFF \
FTP		"File Transfer Protocol support" OFF \
CURL		"CURL support" OFF \
gettext		"gettext library support" OFF \
japanese	"jstring and mbregex module" OFF \
YP		"YP/NIS support" OFF \
BCMath		"BCMath support" OFF \
Hyperwave	"Hyperwave support" OFF \
ming		"ming library support" OFF \
sockets		"sockets support" OFF \
sysvsem		"System V semaphore support" OFF \
sysvshm		"System V shared memory support" OFF \
transsid	"Transparent session id" OFF \
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
			echo "LIB_DEPENDS+=	gd.2:\${PORTSDIR}/graphics/gd"
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
			echo "LIB_DEPENDS+=	mcrypt.6:\${PORTSDIR}/security/libmcrypt"
			echo "CONFIGURE_ARGS+=--with-mcrypt=\${PREFIX}"
			;;
		\"mhash\")
			echo "LIB_DEPENDS+=	mhash.2:\${PORTSDIR}/security/mhash"
			echo "CONFIGURE_ARGS+=--with-mhash=\${PREFIX}"
			;;
		\"pdflib\")
			echo "pdflib is DISABLED for now. Ignoring." > /dev/stderr
			;;
		\"nothing\")
			echo "LIB_DEPENDS+=	pdf.2:\${PORTSDIR}/print/pdflib"
			echo "CONFIGURE_ARGS+=--with-pdflib=\${PREFIX} \\"
			echo "		--with-jpeg-dir=\${PREFIX} \\"
			echo "		--with-tiff-dir=\${PREFIX}"
			if [ -z "$ZLIB" ]; then
				set $* \"zlib\"
			fi
			;;
		\"IMAP\")
			echo "LIB_DEPENDS+=	c-client4.8:\${PORTSDIR}/mail/cclient"
			echo "CONFIGURE_ARGS+=--with-imap=\${PREFIX}"
			;;
		\"MySQL\")
			echo "LIB_DEPENDS+=	mysqlclient.10:\${PORTSDIR}/databases/mysql323-client"
			echo "CONFIGURE_ARGS+=--with-mysql=\${PREFIX}"
			;;
		\"PostgreSQL\")
			echo "LIB_DEPENDS+=	pq.2:\${PORTSDIR}/databases/postgresql7"
			echo "CONFIGURE_ARGS+=--with-pgsql=\${PREFIX}/pgsql"
			if /usr/bin/ldd ${PREFIX}/pgsql/bin/postgres 2> /dev/null | /usr/bin/grep -q "libssl"; then
				echo "USE_OPENSSL=	yes"
				LIBS="${LIBS} -L\${OPENSSLBASE}/lib -lcrypto -lssl"
			fi
			;;
		\"SybaseDB\")
			echo "LIB_DEPENDS+=	sybdb.0:\${PORTSDIR}/databases/freetds"
			echo "CONFIGURE_ARGS+=--with-sybase=\${PREFIX}"
			if [ "$SYBASECT" ]; then
				echo "SybaseDB and SybaseCT are mutually exclusive." > /dev/stderr
				rm -f ${WRKDIRPREFIX}${REALCURDIR}/Makefile.inc
				exit 1
			fi
			SYBASEDB=1
			;;
		\"SybaseCT\")
			echo "LIB_DEPENDS+=	ct.0:\${PORTSDIR}/databases/freetds"
			echo "CONFIGURE_ARGS+=--with-sybase-ct=\${PREFIX}"
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
			echo "LIB_DEPENDS+=	ldap.1:\${PORTSDIR}/net/openldap"
			echo "LIB_DEPENDS+=	lber.1:\${PORTSDIR}/net/openldap"
			echo "CONFIGURE_ARGS+=--with-ldap=\${PREFIX}"
			if [ -f /usr/lib/libkrb.a -a -f /usr/lib/libdes.a -a ! -L /usr/lib/libdes.a ]; then
				LIBS="${LIBS} -lkrb -ldes -L\${PREFIX}/lib"
			fi
			;;
		\"OpenSSL\")
			echo "USE_OPENSSL=yes"
			echo "CONFIGURE_ARGS+=--with-openssl=\${OPENSSLBASE}"
			;;
		\"SNMP\")
			echo "LIB_DEPENDS+=	snmp.4:\${PORTSDIR}/net/net-snmp"
			echo "CONFIGURE_ARGS+=--with-snmp=\${PREFIX} --enable-ucd-snmp-hack"
			echo "USE_OPENSSL=	yes"
			LIBS="${LIBS} -L\${OPENSSLBASE}/lib -lcrypto -lssl"
			;;
		\"XML\")
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/libexpat.a:\${PORTSDIR}/textproc/expat"
			echo "BUILD_DEPENDS+=	\${PREFIX}/include/xml/xmlparse.h:\${PORTSDIR}/textproc/expat"
			echo "BUILD_DEPENDS+=	\${PREFIX}/include/xml/xmltok.h:\${PORTSDIR}/textproc/expat"
			echo "CONFIGURE_ARGS+=--with-xml=\${PREFIX}"
			;;
		\"FTP\")
			echo "CONFIGURE_ARGS+=--enable-ftp"
			;;
		\"CURL\")
			echo "CONFIGURE_ARGS+=--with-curl=\${PREFIX}"
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/libcurl.a:\${PORTSDIR}/ftp/curl"
                        ;;
		\"gettext\")
			echo "LIB_DEPENDS+=	intl.1:\${PORTSDIR}/devel/gettext"
			echo "CONFIGURE_ARGS+=--with-gettext=\${PREFIX}"
			;;
		\"japanese\")
			${CAT} << EOF
MASTER_SITES+=	ftp://night.fminn.nagano.nagano.jp/php4/
DISTFILES=	\${DISTNAME}\${EXTRACT_SUFX} php4_jstring-20010205.tar.gz php4_mbregex-1.2.tar.gz
CONFIGURE_ARGS+=--enable-jstring --enable-mbregex
BUILD_DEPENDS+=	automake:\${PORTSDIR}/devel/automake
BUILD_DEPENDS+=	autoconf:\${PORTSDIR}/devel/autoconf
POSTEXTRACT+=	post-extract-japanese

post-extract-japanese:
	[ -d \${WRKDIR}/jstring -a \${WRKDIR}/mbregex ] && \\
	(cd \${WRKSRC}; \\
	 \${MV} ${WRKDIR}/jstring ext; \\
	 \${MV} ${WRKDIR}/mbregex ext; \\
	 \${RM} configure; \\
	 ./buildconf)

EOF
			;;
		\"YP\")
			echo "CONFIGURE_ARGS+=--enable-yp"
			;;
		\"BCMath\")
			echo "CONFIGURE_ARGS+=--enable-bcmath"
			;;
		\"Hyperwave\")
			echo "CONFIGURE_ARGS+=--with-hyperwave=yes"
			;;
		\"ming\")
			${CAT} << EOF
CONFIGURE_ARGS+=--with-ming=\${PREFIX}
BUILD_DEPENDS+=	/nonexistent:\${PORTSDIR}/graphics/ming:extract
BUILD_DEPENDS+=	automake:\${PORTSDIR}/devel/automake
BUILD_DEPENDS+=	autoconf:\${PORTSDIR}/devel/autoconf
LIB_DEPENDS+=	ming.2:\${PORTSDIR}/graphics/ming
POSTEXTRACT+=	post-extract-ming

post-extract-ming:
	[ -d \`cd \${PORTSDIR}/graphics/ming && \${MAKE} -V WRKSRC\`/../php_ext ] && \\
	(cd \${WRKSRC}; \\
	 \${MKDIR} \${WRKSRC}/ext/ming; \\
	 \${CP} \`cd \${PORTSDIR}/graphics/ming && \${MAKE} -V WRKSRC\`/../php_ext/* \${WRKSRC}/ext/ming; \\
	 \${CP} \${FILESDIR}/ming-config-m4 \${WRKSRC}/ext/ming/config.m4; \\
	 \${RM} configure; \\
	 ./buildconf)

EOF
			;;
		\"sockets\")
			echo "CONFIGURE_ARGS+=--enable-sockets"
			;;
		\"sysvsem\")
			echo "CONFIGURE_ARGS+=--enable-sysvsem"
			;;
		\"sysvshm\")
			echo "CONFIGURE_ARGS+=--enable-sysvshm"
			;;
		\"transsid\")
			echo "CONFIGURE_ARGS+=--enable-trans-sid"
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
