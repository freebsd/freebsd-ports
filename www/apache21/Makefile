# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	2.0.28
PORTREVISION=	5
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
		http://apache.mirrorcentral.com/dist/httpd/ \
		http://apache.missouri.edu/dist/httpd/ \
		http://ftp.epix.net/apache/dist/httpd/ \
		ftp://ftp.digex.net/pub/packages/network/apache/httpd/ \
		ftp://ftp.cuckoo.com/pub/mirrors/apache/dist/httpd/
DISTNAME=	httpd-${PORTVERSION:S/./_/g}-beta

PATCH_SITES=	http://fallin.lv/distfiles/
PATCHFILES=	${PORTNAME}-${PORTVERSION}_1.diff

MAINTAINER?=	perky@fallin.lv

LATEST_LINK=	apache2

WRKSRC=		${WRKDIR}/httpd-${PORTVERSION:S/./_/g}
FIND=		find

WITH_MPM?=	prefork # or perchild, threaded
HTTP_PORT?=	80

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL} \
		--enable-so \
		--with-suexec-docroot=${PREFIX}/www/data \
		--with-mpm=${WITH_MPM} \
		--with-port=${HTTP_PORT} \
		--includedir=${PREFIX}/include/apache # for apr, apr-util
CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
SHARED_MODULES=	all cgid

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=YES
.endif

.if !defined(WITHOUT_SSL) && exists(/usr/lib/libcrypto.so)
SHARED_MODULES+= ssl
PLIST_SUB+=	SSLOPT=""
.else
PLIST_SUB+=	SSLOPT="@comment "
.endif

.if !defined(WITHOUT_PROXY)
SHARED_MODULES+= proxy proxy-connect proxy-ftp proxy-http
PLIST_SUB+=	PROXYOPT=""
.else
PLIST_SUB+=	PROXYOPT="@comment "
.endif

.if !defined(WITHOUT_CACHE)
SHARED_MODULES+= cache mem-cache file-cache #disk-cache
PLIST_SUB+=	CACHEOPT=""
.else
PLIST_SUB+=	CACHEOPT="@comment "
.endif

CONFIGURE_ARGS+= --enable-mods-shared="${SHARED_MODULES}"

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 suexec.8

pre-extract:
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} "You can disable support for SSL by defining WITHOUT_SSL."
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -exec rm -f {} \;

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
