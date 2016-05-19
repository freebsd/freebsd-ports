# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zmap
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	yuri@rawbw.com
COMMENT=	Internet scanner

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt
LIB_DEPENDS=	libdnet.so:net/libdnet \
		libgmp.so:math/gmp

USE_GITHUB=	yes

USES=		cmake pkgconfig

MANPAGE=	zblacklist.1 zmap.1 ztee.1

OPTIONS_DEFINE=	REDIS MONGO JSON
OPTIONS_DEFAULT=JSON
JSON_DESC=	Build with support for JSON

REDIS_LIB_DEPENDS=	libhiredis.so:/databases/hiredis
REDIS_CMAKE_ON+=	-DWITH_REDIS=ON
REDIS_CMAKE_OFF+=	-DWITH_REDIS=OFF

MONGO_LIB_DEPENDS+=	libmongoc-1.0.so:/devel/mongo-c-driver
MONGO_CMAKE_ON+=	-DWITH_MONGO=ON
MONGO_CMAKE_OFF+=	-DWITH_MONGO=OFF

JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSON_CMAKE_ON+=		-DWITH_JSON=ON
JSON_CMAKE_OFF+=	-DWITH_JSON=OFF

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap|${LOCALBASE}/etc/zmap|g' -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e 's|share/man/man1|man/man1|g' \
		${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap/zmap.conf|${LOCALBASE}/etc/zmap/zmap.conf|g' \
		${WRKSRC}/src/zopt.ggo.in \
		${WRKSRC}/src/zmap.c
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap/blacklist.conf|${LOCALBASE}/etc/zmap/blacklist.conf|g' \
		${WRKSRC}/conf/zmap.conf \
		${WRKSRC}/src/zmap.c
.if ${OSVERSION} < 1000033
	@${REINPLACE_CMD} -i '' -e 's|COMMAND flex |COMMAND ${LOCALBASE}/bin/flex |g' \
		${WRKSRC}/src/CMakeLists.txt
.endif

post-install:
.for m in ${MANPAGE}
	${GZIP_CMD} ${STAGEDIR}${MANPREFIX}/man/man1/$m
.endfor

.include <bsd.port.mk>
