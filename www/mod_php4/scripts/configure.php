#!/bin/sh

if [ -f ${WRKDIRPREFIX}${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 11 \
tuning		"Apache: performance tuning" OFF \
modssl		"Apache: SSL support" OFF \
GD		"PHP3:   GD library support" ON \
FreeType	"PHP3:   TrueType font rendering (implies GD)" OFF \
zlib		"PHP3:   zlib library support" ON \
pdflib		"PHP3:   pdflib support" OFF \
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
> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"tuning\")
			echo "APACHE_PERF_TUNING=	YES" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"GD\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libgd.a:\${PORTSDIR}/graphics/gd" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-gd=\${PREFIX}" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			GD=1
			;;
		\"FreeType\")
			echo "LIB_DEPENDS+=		ttf.3:\${PORTSDIR}/print/freetype" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			if [ -z "$GD" ]; then
				set $* \"GD\"
			fi
			;;
		\"zlib\")
			echo "PHP3_CONF_ARGS+=	--with-zlib" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"pdflib\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libpdf.a:\${PORTSDIR}/print/pdflib" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-pdflib=\${PREFIX}" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"MySQL\")
			echo "LIB_DEPENDS+=		mysqlclient.5:\${PORTSDIR}/databases/mysql322" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-mysql=\${PREFIX}" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"PostgreSQL\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/pgsql/bin/psql:\${PORTSDIR}/databases/postgresql" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-pgsql=\${PREFIX}/pgsql" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"mSQL\")
			echo "BUILD_DEPENDS+=		msql:\${PORTSDIR}/databases/msql" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-msql=\${PREFIX}" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"dBase\")
			echo "PHP3_CONF_ARGS+=	--with-dbase" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"OpenLDAP\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libldap.a:\${PORTSDIR}/net/openldap" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/liblber.a:\${PORTSDIR}/net/openldap" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-ldap=\${PREFIX}" >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
			;;
		\"modssl\")
			cat << EOF >> ${WRKDIRPREFIX}${CURDIR}/Makefile.inc
PKGNAME=	apache-php3-\${VERSION_APACHE}+mod_ssl-\${VERSION_MODSSL}
MASTER_SITES+=	http://www.engelschall.com/sw/mod_ssl/distrib/ \\
		ftp://ftp.engelschall.com/sw/mod_ssl/ \\
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \\
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \\
		ftp://glock.missouri.edu/pub/mod_ssl/ \\
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \\
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \\
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \\
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \\
		ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/
DISTFILES+=	mod_ssl-\${VERSION_MODSSL}-\${VERSION_APACHE}\${EXTRACT_SUFX}

BUILD_DEPENDS+=	ssleay:\${PORTSDIR}/security/openssl \\
		\${PREFIX}/lib/libssl.a:\${PORTSDIR}/security/openssl \\
		\${PREFIX}/lib/libcrypto.a:\${PORTSDIR}/security/openssl
RUN_DEPENDS+=	ssleay:\${PORTSDIR}/security/openssl

VERSION_MODSSL=	2.2.0

RESTRICTED=	"Contains cryptography"

CONFIGURE_ARGS+=--enable-module=ssl
CONFIGURE_ENV+=	SSL_BASE='SYSTEM' PATH="\${PREFIX}/bin:\${PATH}"

PATCHDIR=	\${.CURDIR}/patches.modssl
PLIST=		\${PKGDIR}/PLIST.modssl
SSL=		ssl

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
