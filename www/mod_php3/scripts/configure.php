#!/bin/sh

if [ -f ${CURDIR}/Makefile.inc ]; then
	exit
fi

/usr/bin/dialog --title "configuration options" --clear \
	--checklist "\n\
Please select desired options:" -1 -1 9 \
tuning		"Apache: performance tuning" OFF \
modssl		"Apache: SSL support" OFF \
GD		"PHP3:   GD library support" ON \
FreeType	"PHP3:   TrueType font rendering (implies GD)" OFF \
zlib		"PHP3:   zlib library support" ON \
MySQL		"PHP3:   MySQL database support" ON \
PostgreSQL	"PHP3:   PostgreSQL database support" OFF \
mSQL		"PHP3:   mSQL database support" OFF \
dBase		"PHP3:   dBase database support" OFF 2> /tmp/checklist.tmp.$$

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

> ${CURDIR}/Makefile.inc

while [ "$1" ]; do
	case $1 in
		\"tuning\")
			echo "APACHE_PERF_TUNING=	YES" >> ${CURDIR}/Makefile.inc
			;;
		\"GD\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/lib/libgd.a:\${PORTSDIR}/graphics/gd" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-gd" >> ${CURDIR}/Makefile.inc
			GD=1
			;;
		\"FreeType\")
			echo "LIB_DEPENDS+=		ttf.3:\${PORTSDIR}/print/freetype" >> ${CURDIR}/Makefile.inc
			if [ -z "$GD" ]; then
				set $* \"GD\"
			fi
			;;
		\"zlib\")
			echo "PHP3_CONF_ARGS+=	--with-zlib" >> ${CURDIR}/Makefile.inc
			;;
		\"MySQL\")
			echo "BUILD_DEPENDS+=		mysql:\${PORTSDIR}/databases/mysql321" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-mysql=\${PREFIX}" >> ${CURDIR}/Makefile.inc
			;;
		\"PostgreSQL\")
			echo "BUILD_DEPENDS+=		\${PREFIX}/pgsql/bin/psql:\${PORTSDIR}/databases/postgresql" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-pgsql=\${PREFIX}/pgsql" >> ${CURDIR}/Makefile.inc
			;;
		\"mSQL\")
			echo "BUILD_DEPENDS+=		msql:\${PORTSDIR}/databases/msql" >> ${CURDIR}/Makefile.inc
			echo "PHP3_CONF_ARGS+=	--with-msql=\${PREFIX}" >> ${CURDIR}/Makefile.inc
			;;
		\"dBase\")
			echo "PHP3_CONF_ARGS+=	--with-dbase" >> ${CURDIR}/Makefile.inc
			;;
		\"modssl\")
			cat << EOF >> ${CURDIR}/Makefile.inc
PKGNAME=	apache-php\${VERSION_PHP3}-\${VERSION_APACHE}+mod_ssl-\${VERSION_MODSSL}
MASTER_SITES+=	http://www.engelschall.com/sw/mod_ssl/distrib/ \\
		ftp://ftp.engelschall.com/sw/mod_ssl/ \\
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \\
		ftp://glock.missouri.edu/pub/mod_ssl/
DISTFILES+=	mod_ssl-\${VERSION_MODSSL}-\${VERSION_APACHE}\${EXTRACT_SUFX}

BUILD_DEPENDS+=	ssleay:\${PORTSDIR}/security/SSLeay \\
		\${PREFIX}/lib/libssl.a:\${PORTSDIR}/security/SSLeay \\
		\${PREFIX}/lib/libcrypto.a:\${PORTSDIR}/security/SSLeay
RUN_DEPENDS+=	ssleay:\${PORTSDIR}/security/SSLeay

VERSION_MODSSL=	2.0.14

RESTRICTED=	"Contains cryptography"

CONFIGURE_ARGS+=--enable-module=ssl
CONFIGURE_ENV+=	SSL_BASE='SYSTEM' PATH="\${PREFIX}/bin:\${PATH}"

PATCHDIR=	\${.CURDIR}/patches.modssl
PLIST=		\${PKGDIR}/PLIST.modssl
SSL=		ssl

pre-patch:
	@cd \${WRKDIR}/mod_ssl-\${VERSION_MODSSL}-\${VERSION_APACHE} \\
	&& \${ECHO_MSG} "===>  Applying mod_ssl-\${VERSION_MODSSL} extension" \\
	&& ./configure --with-apache=../\${DISTNAME}

post-patch:
	@cd \${WRKSRC} \\
	&& find . -type f -name "*.orig" -print | xargs \${RM} -f

post-build:
	@cd \${WRKSRC} \\
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
