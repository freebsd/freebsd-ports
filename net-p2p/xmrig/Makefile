# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmrig
PORTVERSION=	2.14.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	High performance Monero (XMR) CPU miner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to configure: Target "xmrig" requires the language dialect "CXX11", but CMake does not know the compile flags to use to enable it.

USES=		cmake ssl
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} USERS=${USERS}
USERS=		xmrig

OPTIONS_DEFINE=	STATIC MICROHTTPD
MICROHTTPD_DESC=Build with libmicrohttpd support
OPTIONS_DEFAULT=MICROHTTPD

STATIC_PREVENTS=MICROHTTPD
STATIC_PREVENTS_MSG=	libmicrohttpd support cannot be built static

MICROHTTPD_LIB_DEPENDS+=	libmicrohttpd.so:www/libmicrohttpd \
				libuv.so:devel/libuv

STATIC_BUILD_DEPENDS+=	${LOCALBASE}/lib/libuv.a:devel/libuv

post-patch-MICROHTTPD-off:
	@${REINPLACE_CMD} -e 's|\(.*WITH_HTTPD.*\)\(ON\)|\1OFF|' \
		${WRKSRC}/CMakeLists.txt

post-patch-STATIC-on:
	@${REINPLACE_CMD} -e 's|\(.*BUILD_STATIC.*\)\(OFF\)|\1ON|' \
		${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/config.json ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
