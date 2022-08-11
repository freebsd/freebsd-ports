PORTNAME=	libnss-cache
PORTVERSION=	0.21
DISTVERSIONPREFIX=	version/
CATEGORIES=	net

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NSS module for directory services using an indexed, local disk cache

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	google

PLIST_FILES=	lib/nss_nsscache.so.1

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX=$$(DESTDIR)/usr|PREFIX=${STAGEDIR}${PREFIX}|g' \
		-e 's|LIBRARY=libnss_cache.so|LIBRARY=nss_nsscache.so|g' \
		-e 's|SONAME=libnss_cache.so.2|SONAME=nss_nsscache.so.1|g' \
		${WRKSRC}/Makefile

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/nss_nsscache.so ${STAGEDIR}${PREFIX}/lib/nss_nsscache.so.1.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nss_nsscache.so.1

.include <bsd.port.mk>
