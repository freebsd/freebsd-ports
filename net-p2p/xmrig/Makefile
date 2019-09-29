# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmrig
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	High performance Monero (XMR) CPU miner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to compile: src/common/cpu/BasicCpuInfo_arm.cpp:30:13: fatal error: 'asm/hwcap.h' file not found
BROKEN_armv6=		fails to build: /nxb-bin/usr/lib/clang/8.0.0/include/ia32intrin.h:48:10: error: use of undeclared identifier '__builtin_ia32_readeflags_u32'
BROKEN_armv7=		fails to build: /nxb-bin/usr/lib/clang/8.0.0/include/ia32intrin.h:48:10: error: use of undeclared identifier '__builtin_ia32_readeflags_u32'
BROKEN_powerpc64=	fails to configure: Target "xmrig" requires the language dialect "CXX11", but CMake does not know the compile flags to use to enable it.

USES=		cmake ssl
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} USERS=${USERS}
USERS=		xmrig

OPTIONS_DEFINE=	STATIC MICROHTTPD HWLOC
HWLOC_DESC=	Portable hardware locality
MICROHTTPD_DESC=Build with libmicrohttpd support
OPTIONS_DEFAULT=MICROHTTPD HWLOC

STATIC_PREVENTS=HWLOC MICROHTTPD
STATIC_PREVENTS_MSG=	hwloc and libmicrohttpd support cannot be built static

HWLOC_LIB_DEPENDS+=	libhwloc.so:devel/hwloc

MICROHTTPD_LIB_DEPENDS+=	libmicrohttpd.so:www/libmicrohttpd \
				libuv.so:devel/libuv

STATIC_BUILD_DEPENDS+=	${LOCALBASE}/lib/libuv.a:devel/libuv

post-patch-HWLOC-off:
	@${REINPLACE_CMD} -e 's|\(.*WITH_HWLOC.*\)\(ON\)|\1OFF|' \
		${WRKSRC}/CMakeLists.txt

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
