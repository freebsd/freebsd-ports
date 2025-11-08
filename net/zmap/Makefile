PORTNAME=	zmap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.4
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet scanner
WWW=		https://zmap.io/ \
		https://github.com/zmap/zmap

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt
LIB_DEPENDS=	libgmp.so:math/gmp \
		libjson-c.so:devel/json-c \
		libJudy.so:devel/judy \
		libpcap.so:net/libpcap \
		libunistring.so:devel/libunistring

USES=		cmake pkgconfig

USE_GITHUB=	yes

CMAKE_ON=	FORCE_CONF_INSTALL

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap|${LOCALBASE}/etc/zmap|g' -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap/zmap.conf|${LOCALBASE}/etc/zmap/zmap.conf|g' \
		${WRKSRC}/src/zopt.ggo.in \
		${WRKSRC}/src/zmap.c
	@${REINPLACE_CMD} -i '' -e 's|/etc/zmap/blocklist.conf|${LOCALBASE}/etc/zmap/blocklist.conf|g' \
		${WRKSRC}/conf/zmap.conf \
		${WRKSRC}/src/zmap.c

post-install:
	@${MV} ${STAGEDIR}${ETCDIR}/blocklist.conf ${STAGEDIR}${ETCDIR}/blocklist.conf.sample
	@${MV} ${STAGEDIR}${ETCDIR}/zmap.conf ${STAGEDIR}${ETCDIR}/zmap.conf.sample

.include <bsd.port.mk>
