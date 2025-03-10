PORTNAME=	zmap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet scanner
WWW=		https://zmap.io/ \
		https://github.com/zmap/zmap

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt \
		gmake:devel/gmake
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libJudy.so:devel/judy \
		libgmp.so:math/gmp \
		libpcap.so:net/libpcap \
		libunistring.so:devel/libunistring

USES=		cmake:insource pkgconfig
USE_GITHUB=	yes

CFLAGS+=	-D_SYSTYPE_BSD

CMAKE_ON=	FORCE_CONF_INSTALL

MANPAGE=	zblacklist.1 zmap.1 ztee.1

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
.for cnf in blocklist.conf zmap.conf
	@${MV} ${STAGEDIR}${ETCDIR}/${cnf} ${STAGEDIR}${ETCDIR}/${cnf}.sample
.endfor

.include <bsd.port.mk>
