#!/bin/sh

if [ -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 14 \
tuning		"Apache: performance tuning" OFF \
modssl		"Apache: SSL support" OFF \
GD		"PHP3:   GD library support" OFF \
FreeType	"PHP3:   TrueType font rendering (implies GD)" OFF \
zlib		"PHP3:   zlib library support" ON \
mcrypt		"PHP3:   Encryption support" OFF \
mhash		"PHP3:   Crypto-hashing support" OFF \
pdflib		"PHP3:   pdflib support (implies zlib)" OFF \
IMAP		"PHP3:   IMAP support" OFF \
MySQL		"PHP3:   MySQL database support" ON \
PostgreSQL	"PHP3:   PostgreSQL database support" OFF \
mSQL		"PHP3:   mSQL database support" OFF \
dBase		"PHP3:   dBase database support" OFF \
OpenLDAP	"PHP3:   OpenLDAP support" OFF \
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

mkdir -p ${WRKDIRPREFIX}${CURDIR}
exec > ${WRKDIRPREFIX}${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"tuning\")
			echo "APACHE_PERF_TUNING=	YES"
			;;
		\"GD\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libgd.a:\${PORTSDIR}/graphics/gd"
			echo "PHP3_CONF_ARGS+=	--with-gd=\${PREFIX}"
			GD=1
			;;
		\"FreeType\")
			echo "LIB_DEPENDS+=		ttf.3:\${PORTSDIR}/print/freetype"
			echo "PHP3_CONF_ARGS+=	--with-ttf=\${PREFIX}"
			if [ -z "$GD" ]; then
				set $* \"GD\"
			fi
			;;
		\"zlib\")
			echo "PHP3_CONF_ARGS+=	--with-zlib"
			ZLIB=1
			;;
		\"mcrypt\")
			echo "LIB_DEPENDS+=		mcrypt.2:\${PORTSDIR}/security/libmcrypt"
			echo "PHP3_CONF_ARGS+=	--with-mcrypt=\${PREFIX}"
			;;
		\"mhash\")
			echo "LIB_DEPENDS+=		mhash.1:\${PORTSDIR}/security/mhash"
			echo "PHP3_CONF_ARGS+=	--with-mhash=\${PREFIX}"
			;;
		\"pdflib\")
			echo "LIB_DEPENDS+=		pdf.2:\${PORTSDIR}/print/pdflib"
			echo "PHP3_CONF_ARGS+=	--with-pdflib=\${PREFIX} \\"
			echo "			--with-jpeg-dir=\${PREFIX} \\"
			echo "			--with-tiff-dir=\${PREFIX}"
			if [ -z "$ZLIB" ]; then
				set $* \"zlib\"
			fi
			;;
		\"IMAP\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libc-client4.a:\${PORTSDIR}/mail/imap-uw"
			echo "PHP3_CONF_ARGS+=	--with-imap=\${PREFIX}"
			;;
		\"MySQL\")
			echo "LIB_DEPENDS+=		mysqlclient.6:\${PORTSDIR}/databases/mysql322-client"
			echo "PHP3_CONF_ARGS+=	--with-mysql=\${PREFIX}"
			;;
		\"PostgreSQL\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/pgsql/bin/psql:\${PORTSDIR}/databases/postgresql"
			echo "PHP3_CONF_ARGS+=	--with-pgsql=\${PREFIX}/pgsql"
			;;
		\"mSQL\")
			echo "BUILD_DEPENDS+=		msql:\${PORTSDIR}/databases/msql"
			echo "PHP3_CONF_ARGS+=	--with-msql=\${PREFIX}"
			;;
		\"dBase\")
			echo "PHP3_CONF_ARGS+=	--with-dbase"
			;;
		\"OpenLDAP\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libldap.a:\${PORTSDIR}/net/openldap"
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/liblber.a:\${PORTSDIR}/net/openldap"
			echo "PHP3_CONF_ARGS+=	--with-ldap=\${PREFIX}"
			;;
		\"modssl\")
			cat << EOF
PKGNAME=	apache+php3+mod_ssl-\${VERSION_APACHE}+\${VERSION_PHP3}+\${VERSION_MODSSL}
MASTER_SITES+=	http://www.modssl.org/source/ \\
		ftp://ftp.modssl.org/source/ \\
		ftp://ftp.ecrc.net/pub/security/mod_ssl/ \\
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \\
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \\
		ftp://glock.missouri.edu/pub/mod_ssl/ \\
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \\
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \\
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \\
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \\
		ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/
DISTFILES+=	mod_ssl-\${VERSION_MODSSL}-\${VERSION_APACHE}\${EXTRACT_SUFX}

BUILD_DEPENDS+=	openssl:\${PORTSDIR}/security/openssl \\
		mm-config:\${PORTSDIR}/devel/mm \\
		\${PREFIX}/lib/libssl.a:\${PORTSDIR}/security/openssl \\
		\${PREFIX}/lib/libcrypto.a:\${PORTSDIR}/security/openssl \\
		\${PREFIX}/lib/libmm.a:\${PORTSDIR}/devel/mm
RUN_DEPENDS+=	openssl:\${PORTSDIR}/security/openssl

VERSION_MODSSL=	2.3.10

RESTRICTED=	"Contains cryptography"

CONFIGURE_ARGS+=--enable-module=ssl \
		--enable-module=define
CONFIGURE_ENV+=	SSL_BASE='SYSTEM' EAPI_MM='SYSTEM' PATH="\${PREFIX}/bin:\${PATH}"

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
