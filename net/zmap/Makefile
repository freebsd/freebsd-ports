PORTNAME=	zmap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
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

FLAVORS=	default netmap
FLAVOR?=	${FLAVORS:[1]}
netmap_PKGNAMESUFFIX=	-netmap

USES=		cmake pkgconfig

USE_GITHUB=	yes

.if ${FLAVOR} == netmap
COMMENT+=	(with netmap support)
CMAKE_ON=	WITH_NETMAP
.endif

CMAKE_ON+=	FORCE_CONF_INSTALL

post-patch:
	@${REINPLACE_CMD} -e '\
		s|/etc/zmap|${LOCALBASE}/etc/zmap|g; \
		s|/usr/local|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/etc/zmap/zmap.conf|${LOCALBASE}/etc/zmap/zmap.conf|g' \
		${PATCH_WRKSRC}/src/zopt.ggo.in
	@${REINPLACE_CMD} -e 's|/etc/zmap/blocklist.conf|${LOCALBASE}/etc/zmap/blocklist.conf|g' \
		${PATCH_WRKSRC}/conf/zmap.conf

post-install:
	@${RM} ${STAGEDIR}${ETCDIR}/zmap.conf.bak
	@${MV} ${STAGEDIR}${ETCDIR}/blocklist.conf ${STAGEDIR}${ETCDIR}/blocklist.conf.sample
	@${MV} ${STAGEDIR}${ETCDIR}/zmap.conf ${STAGEDIR}${ETCDIR}/zmap.conf.sample

.include <bsd.port.mk>
