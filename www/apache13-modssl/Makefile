# New ports collection makefile for:	Apache + mod_ssl
# Date created:		Sat Aug 22 12:00:00 CDT 1998
# Whom:			rse@engelschall.com
#
# $FreeBSD$
#

PORTNAME=	apache+mod_ssl
PORTVERSION=	${VERSION_APACHE}+${VERSION_MODSSL}
CATEGORIES=	www security
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/httpd/ \
		ftp://ftp.rge.com/pub/infosystems/apache/dist/httpd/ \
		ftp://apache.compuex.com/pub/apache/dist/httpd/ \
		ftp://apache.arctic.org/pub/apache/dist/httpd/ \
		ftp://ftp.epix.net/pub/apache/dist/httpd/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/httpd/ \
		ftp://ftp.connectnet.com/pub/www/apache/httpd/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/httpd/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/httpd/ \
		ftp://www3.service.digital.com/apache/dist/httpd/ \
		ftp://galileo.galilei.com/pub/apache/httpd/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/httpd/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/httpd/ \
		ftp://apache.nextpath.com/pub/apache/dist/httpd/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/apache/dist/httpd,} \
		${MASTER_SITES_MODSSL:S/$/:modssl/}
DISTNAME=	apache_${VERSION_APACHE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}:modssl

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mm.12:${PORTSDIR}/devel/mm

MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/ \
		ftp://ftp.ecrc.net/pub/security/mod_ssl/ \
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \
		ftp://glock.missouri.edu/pub/mod_ssl/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mod_ssl/source,}
USE_OPENSSL=	YES

.include <bsd.port.pre.mk>

VERSION_APACHE=	1.3.27
VERSION_MODSSL=	2.8.12

DATADIR=	${PREFIX}/www
DOCUMENT_ROOT=	${DATADIR}/data
DEFAULT_PATH=/bin:/usr/bin:${PREFIX}/bin

.if defined(WITH_APACHE_SUEXEC) && ${WITH_APACHE_SUEXEC} == yes

APACHE_SUEXEC_DOCROOT?=${DOCUMENT_ROOT}
APACHE_SUEXEC_USERDIR?=public_html

SUEXEC_CONF=\
		--enable-suexec \
		--suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
		--suexec-caller=www \
		--suexec-uidmin=1000 \
		--suexec-gidmin=1000 \
		--suexec-logfile=/var/log/httpd-suexec.log \
		--suexec-userdir=${APACHE_SUEXEC_USERDIR} \
		--suexec-safepath=${DEFAULT_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+=\
		--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_SUB+=	SUB_SUEXEC=""
SUEXEC_MAN=	suexec.8

.else   # !SUEXEC

SUEXEC_CONF=
PLIST_SUB+=	SUB_SUEXEC="@comment "
SUEXEC_MAN=

.endif  # !SUEXEC

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max \
		--enable-module=ssl \
		--enable-module=define \
		${SUEXEC_CONF}

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"${PREFIX}/bin:/bin:/usr/bin\\" \
		-DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(WITH_APACHE_PERF_TUNING) && ${WITH_APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer \
		-fexpensive-optimizations -ffast-math
.endif

.include "${PORTSDIR}/security/openssl/Makefile.ssl"

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		SSL_BASE='${OPENSSLBASE}' \
		EAPI_MM='SYSTEM' \
		PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
	${SUEXEC_MAN}

TYPE=	test
CRT=
KEY=

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/apache.sh \
		> ${WRKSRC}/apache.sh

pre-patch:
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert

post-patch:
	@${PERL} -pi -e 's|-print|-print0|;s|xargs|xargs -0|' \
		${WRKSRC}/Makefile.tmpl
	@cd ${WRKSRC} \
	&& ${FIND} . -type f -name "*.orig" -print | ${XARGS} ${RM} -f

post-build:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Dummy Certificate for Server (SnakeOil)" \
	&& ${ECHO_MSG} "      [use 'make certificate' to create a real one]" \
	&& ${MAKE} certificate TYPE=dummy >/dev/null 2>&1

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate TYPE=${TYPE} CRT=${CRT} KEY=${KEY}

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh-dist
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.post.mk>
