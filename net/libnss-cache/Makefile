PORTNAME=	libnss-cache
PORTVERSION=	0.22
DISTVERSIONPREFIX=	version/
CATEGORIES=	net

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NSS module for directory services using an indexed, local disk cache
WWW=		https://github.com/google/libnss-cache

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

PLIST_FILES=	lib/nss_nsscache.so.1

post-patch:
	${REINPLACE_CMD} -e 's|PREFIX=$$(DESTDIR)/usr|PREFIX=${STAGEDIR}${PREFIX}|g' \
		-e 's|LIBRARY=libnss_cache.so.2|LIBRARY=nss_nsscache.so.1|g' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nss_nsscache.so.1

.include <bsd.port.mk>
