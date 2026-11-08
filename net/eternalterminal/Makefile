PORTNAME=	eternalterminal
DISTVERSIONPREFIX=	et-v
DISTVERSION=	7.1.1
CATEGORIES=	net

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Remote shell that reconnects without interrupting session
WWW=		https://eternalterminal.dev/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libabsl_log_internal_check_op.so:devel/abseil \
		libprotobuf.so:devel/protobuf \
		libsodium.so:security/libsodium \
		libunwind.so:devel/libunwind

USES=		cmake:testing ssl
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
	# et1.cmd is the Windows batch version of the et1 wrapper, installed unconditionally
	${RM} ${STAGEDIR}${PREFIX}/bin/et1.cmd

.include <bsd.port.mk>
