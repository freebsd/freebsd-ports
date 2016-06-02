# Created by: Kevin Bowling <k@kev009.com>
# $FreeBSD$

PORTNAME=	libnss-cache
PORTVERSION=	0.15
DISTVERSIONPREFIX=	version/
CATEGORIES=	net

MAINTAINER=	k@kev009.com
COMMENT=	NSS module for directory services using an indexed, local disk cache

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	google

PLIST_FILES=	lib/nss_nsscache.so lib/nss_nsscache.so.1

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX=$$(DESTDIR)/usr|PREFIX=${STAGEDIR}${PREFIX}|g' \
		-e 's|LIBRARY=libnss_cache.so.2.0|LIBRARY=nss_nsscache.so.1|g' \
		-e 's|BASE_LIBRARY=libnss_cache.so.2|BASE_LIBRARY=nss_nsscache.so|g' \
		-e 's|SONAME=libnss_cache.so.2|SONAME=nss_nsscahe.so.1|g' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nss_nsscache.so.1

.include <bsd.port.mk>
