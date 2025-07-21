PORTNAME=	eternalterminal
DISTVERSIONPREFIX=	et-v
DISTVERSION=	6.2.10
CATEGORIES=	net

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Remote shell that reconnects without interrupting session
WWW=		https://eternalterminal.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	OpenSSL versions prior to 3.0.0 are not supported

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind

USES=		cmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	MisterTea
GH_PROJECT=	EternalTerminal

CMAKE_ON=	DISABLE_VCPKG
CMAKE_OFF=	BUILD_TESTING

CONFLICTS_INSTALL=	linux-enemyterritory # bin/et

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' ${WRKSRC}/rc.d/etserver

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/etserver
	${INSTALL_DATA} ${WRKSRC}/etc/et.cfg \
		${STAGEDIR}${PREFIX}/etc/etserver/et.cfg.sample
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/etserver \
		${STAGEDIR}${PREFIX}/etc/rc.d

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
