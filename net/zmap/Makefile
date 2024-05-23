PORTNAME=	zmap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/judy/judy/Judy-1.0.5/:judy
DISTFILES=	Judy-1.0.5.tar.gz:judy

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet scanner
WWW=		https://zmap.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gengetopt>0:devel/gengetopt \
		gmake:devel/gmake
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libgmp.so:math/gmp \
		libunistring.so:devel/libunistring

USES=		cmake:insource pkgconfig
USE_GITHUB=	yes

JUDY_WRKSRC=	${WRKDIR}/judy-1.0.5

CFLAGS+=	-D_SYSTYPE_BSD \
		-I${JUDY_WRKSRC}/src
LDFLAGS+=	-L${JUDY_WRKSRC}/src/obj/.libs

CMAKE_ON=	FORCE_CONF_INSTALL

MANPAGE=	zblacklist.1 zmap.1 ztee.1

pre-build: # build the Judy library
	@cd ${JUDY_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ./configure --disable-shared && \
		${SETENV} ${MAKE_ENV} ${GMAKE}

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
