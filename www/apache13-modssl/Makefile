# New ports collection makefile for:	Apache + mod_ssl
# Date created:		Sat Aug 22 12:00:00 CDT 1998
# Whom:			rse@engelschall.com
#
# $FreeBSD$
#

PORTNAME=	apache+mod_ssl
PORTVERSION=	${VERSION_APACHE}+${VERSION_MODSSL}
PORTREVISION=   4
CATEGORIES=	www security
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
		http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/ \
		ftp://ftp.rge.com/pub/infosystems/apache/dist/ \
		ftp://ftp.ecrc.net/pub/security/mod_ssl/ \
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
		ftp://apache.compuex.com/pub/apache/dist/ \
		ftp://apache.arctic.org/pub/apache/dist/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \
		ftp://glock.missouri.edu/pub/mod_ssl/ \
		ftp://ftp.epix.net/pub/apache/dist/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \
		ftp://ftp.connectnet.com/pub/www/apache/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/ \
		ftp://www3.service.digital.com/apache/dist/ \
		ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/ \
		ftp://galileo.galilei.com/pub/apache/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/ \
		ftp://apache.nextpath.com/pub/apache/dist/
DISTNAME=	apache_${VERSION_APACHE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	YES

.include <bsd.port.pre.mk>

LIB_DEPENDS=	mm.11:${PORTSDIR}/devel/mm

VERSION_APACHE=	1.3.22
VERSION_MODSSL=	2.8.5

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		--suexec-docroot=${PREFIX}/www/data \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max \
		--enable-module=ssl \
		--enable-module=define

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"${PREFIX}/bin:/bin:/usr/bin\\" \
		-DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(WITH_APACHE_PERF_TUNING) && ${WITH_APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer \
		-fexpensive-optimizations -ffast-math
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		SSL_BASE='SYSTEM' \
		EAPI_MM='SYSTEM' \
		PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8

TYPE=	test
CRT=
KEY=

pre-patch:
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert

post-patch:
	@${PERL} -pi -e 's|-print|-print0|;s|xargs|xargs -0|' \
		${WRKSRC}/Makefile.tmpl
	@cd ${WRKSRC} \
	&& find . -type f -name "*.orig" -print | xargs ${RM} -f

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
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.post.mk>
