#!/bin/sh
# $FreeBSD$

if [ "${BATCH}" ]; then
	${MKDIR} ${WRKDIRPREFIX}${CURDIR}
	${TOUCH} ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
	exit
fi
if [ -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 14 \
tuning		"Apache: performance tuning" OFF \
modssl		"Apache: SSL support" OFF \
GD		"PHP:    GD library support" OFF \
FreeType	"PHP:    TrueType font rendering (implies GD)" OFF \
zlib		"PHP:    zlib library support" ON \
mcrypt		"PHP:    Encryption support" OFF \
mhash		"PHP:    Crypto-hashing support" OFF \
pdflib		"PHP:    pdflib support (implies zlib)" OFF \
IMAP		"PHP:    IMAP support" OFF \
MySQL		"PHP:    MySQL database support" ON \
PostgreSQL	"PHP:    PostgreSQL database support" OFF \
mSQL		"PHP:    mSQL database support" OFF \
dBase		"PHP:    dBase database support" OFF \
OpenLDAP	"PHP:    OpenLDAP support" OFF \
SNMP		"PHP:    SNMP support" OFF \
XML		"PHP:    XML support" OFF \
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

${MKDIR} ${WRKDIRPREFIX}${CURDIR}
exec > ${WRKDIRPREFIX}${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"tuning\")
			echo "CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer -fexpensive-optimizations -ffast-math"
			echo "OPTIM+=		-DBUFFERED_LOGS -DFD_SETSIZE=1024"
			echo "CONFIGURE_ENV+=	OPTIM='\${OPTIM}'"
			;;
		\"GD\")
			echo "LIB_DEPENDS+=	gd.0:\${PORTSDIR}/graphics/gd"
			echo "PHP_CONF_ARGS+=	--with-gd=\${PREFIX}"
			GD=1
			;;
		\"FreeType\")
			echo "LIB_DEPENDS+=	ttf.4:\${PORTSDIR}/print/freetype"
			echo "PHP_CONF_ARGS+=	--with-ttf=\${PREFIX}"
			if [ -z "$GD" ]; then
				set $* \"GD\"
			fi
			;;
		\"zlib\")
			echo "PHP_CONF_ARGS+=	--with-zlib"
			ZLIB=1
			;;
		\"mcrypt\")
			echo "LIB_DEPENDS+=	mcrypt-2.2.2:\${PORTSDIR}/security/libmcrypt"
			echo "PHP_CONF_ARGS+=	--with-mcrypt=\${PREFIX}"
			;;
		\"mhash\")
			echo "mhash is DISABLED for now. Ignoring." > /dev/stderr
			;;
		\"nothing\")
			echo "LIB_DEPENDS+=	mhash.1:\${PORTSDIR}/security/mhash"
			echo "PHP_CONF_ARGS+=	--with-mhash=\${PREFIX}"
			;;
		\"pdflib\")
			echo "pdflib is DISABLED for now. Ignoring." > /dev/stderr
			;;
		\"nothing\")
			echo "LIB_DEPENDS+=	pdf.2:\${PORTSDIR}/print/pdflib"
			echo "PHP_CONF_ARGS+=	--with-pdflib=\${PREFIX} \\"
			echo "		--with-jpeg-dir=\${PREFIX} \\"
			echo "		--with-tiff-dir=\${PREFIX}"
			if [ -z "$ZLIB" ]; then
				set $* \"zlib\"
			fi
			;;
		\"IMAP\")
			echo "IMAP is DISABLED for now. Ignoring." > /dev/stderr
			;;
		\"nothing\")
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/libc-client4.a:\${PORTSDIR}/mail/imap-uw"
			echo "PHP_CONF_ARGS+=	--with-imap=\${PREFIX}"
			;;
		\"MySQL\")
			echo "LIB_DEPENDS+=	mysqlclient.6:\${PORTSDIR}/databases/mysql322-client"
			echo "PHP_CONF_ARGS+=	--with-mysql=\${PREFIX}"
			;;
		\"PostgreSQL\")
			echo "LIB_DEPENDS+=	pq.2:\${PORTSDIR}/databases/postgresql"
			echo "PHP_CONF_ARGS+=	--with-pgsql=\${PREFIX}/pgsql"
			;;
		\"mSQL\")
			echo "BUILD_DEPENDS+=	msql:\${PORTSDIR}/databases/msql"
			echo "PHP_CONF_ARGS+=	--with-msql=\${PREFIX}"
			;;
		\"dBase\")
			echo "PHP_CONF_ARGS+=	--with-dbase"
			;;
		\"OpenLDAP\")
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/libldap.a:\${PORTSDIR}/net/openldap"
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/liblber.a:\${PORTSDIR}/net/openldap"
			echo "PHP_CONF_ARGS+=	--with-ldap=\${PREFIX}"
			if [ -f /usr/lib/libkrb.a -a -f /usr/lib/libdes.a ]; then
				echo "CONFIGURE_ENV+=	LIBS='-lkrb -ldes -L\${PREFIX}/lib'"
			fi
			;;
		\"SNMP\")
			echo "LIB_DEPENDS+=	snmp.4:\${PORTSDIR}/net/ucd-snmp"
			echo "PHP_CONF_ARGS+=	--with-snmp=\${PREFIX} --enable-ucd-snmp-hack"
			;;
		\"XML\")
			echo "BUILD_DEPENDS+=	\${PREFIX}/lib/libexpat.a:\${PORTSDIR}/textproc/expat"
			echo "BUILD_DEPENDS+=	\${PREFIX}/include/xml/xmlparse.h:\${PORTSDIR}/textproc/expat"
			echo "BUILD_DEPENDS+=	\${PREFIX}/include/xml/xmltok.h:\${PORTSDIR}/textproc/expat"
			echo "PHP_CONF_ARGS+=	--with-xml=\${PREFIX}"
			;;
		\"modssl\")
			cat << EOF
PORTNAME=	apache+php+mod_ssl
PORTVERSION=	\${VERSION_APACHE}+\${VERSION_PHP}+\${VERSION_MODSSL}
DISTFILES+=	mod_ssl-\${VERSION_MODSSL}-\${VERSION_APACHE}\${EXTRACT_SUFX}

USE_OPENSSL=	RSA

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	mm-config:\${PORTSDIR}/devel/mm \\
		\${PREFIX}/lib/libmm.a:\${PORTSDIR}/devel/mm

VERSION_MODSSL=	2.6.4

CONFIGURE_ARGS+=--enable-module=ssl \\
		--enable-module=define
CONFIGURE_ENV+=	SSL_BASE='SYSTEM' EAPI_MM='SYSTEM' PATH="\${PREFIX}/bin:\${PATH}"

EXTRA_PATCHES+=	\${PATCHDIR}/ssl_patch-aa

PLIST=		\${PKGDIR}/PLIST.modssl
SSL=		ssl

TYPE=	test
CRT=
KEY=

pre-patch:
	@cd \${WRKDIR}/mod_ssl-\${VERSION_MODSSL}-\${VERSION_APACHE} \\
	&& \${ECHO_MSG} "===>  Applying mod_ssl-\${VERSION_MODSSL} extension" \\
	&& ./configure --with-apache=../\${DISTNAME} --expert

post-patch:
	@cd \${WRKSRC} \\
	&& find . -type f -name "*.orig" -print | xargs \${RM} -f

post-build:
	@cd \${WRKSRC} \\
	&& \${ECHO_MSG} "===>  Creating Dummy Certificate for Server (SnakeOil)" \\
	&& \${ECHO_MSG} "      [use 'make certificate' to create a real one]" \\
	&& \${MAKE} certificate TYPE=dummy >/dev/null 2>&1

certificate:
	@cd \${WRKSRC} \\
	&& \${ECHO_MSG} "===>  Creating Test Certificate for Server" \\
	&& \${MAKE} certificate TYPE=\$(TYPE) CRT=\$(CRT) KEY=\$(KEY)

EOF
			;;
	esac
	shift
done
