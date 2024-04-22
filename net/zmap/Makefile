PORTNAME=	zmap
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet scanner
WWW=		https://zmap.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt
LIB_DEPENDS=	libdnet.so:net/libdnet \
		libgmp.so:math/gmp \
		libunistring.so:devel/libunistring

USE_GITHUB=	yes

USES=		cmake:insource pkgconfig

CFLAGS+=	-D_SYSTYPE_BSD

MANPAGE=	zblacklist.1 zmap.1 ztee.1

OPTIONS_DEFINE=	REDIS MONGO JSON
OPTIONS_DEFAULT=JSON
JSON_DESC=	Build with support for JSON

REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CMAKE_BOOL=	WITH_REDIS

MONGO_LIB_DEPENDS=	libmongoc-1.0.so:devel/mongo-c-driver
MONGO_CMAKE_BOOL=	WITH_MONGO

JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSON_CMAKE_BOOL=	WITH_JSON

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap|${LOCALBASE}/etc/zmap|g' -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap/zmap.conf|${LOCALBASE}/etc/zmap/zmap.conf|g' \
		${WRKSRC}/src/zopt.ggo.in \
		${WRKSRC}/src/zmap.c
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap/blacklist.conf|${LOCALBASE}/etc/zmap/blacklist.conf|g' \
		${WRKSRC}/conf/zmap.conf \
		${WRKSRC}/src/zmap.c

.include <bsd.port.mk>
