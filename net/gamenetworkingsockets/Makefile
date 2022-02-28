# Created by: Karsten Pedersen <kpedersen@disroot.org>

PORTNAME=	gamenetworkingsockets
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	kpedersen@disroot.org
COMMENT=	GameNetworkingSockets is a basic transport layer for games

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	ValveSoftware
GH_PROJECT=	GameNetworkingSockets

CMAKE_ARGS=	-DGAMENETWORKINGSOCKETS_BUILD_EXAMPLES=OFF \
		-DGAMENETWORKINGSOCKETS_BUILD_TESTS=OFF

.include <bsd.port.mk>
