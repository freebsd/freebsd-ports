PORTNAME=		libsweep-lidar
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.0
PORTREVISION=		1
CATEGORIES=		misc

MAINTAINER=		hyun@caffeinated.codes
COMMENT=		Low-level Scanse Sweep LiDAR library
WWW=		https://scanse.io/

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

BROKEN=			Fails to build with CMake 4
DEPRECATED=		Abandoned upstream, does not build with CMake 4
EXPIRATION_DATE=	2026-11-30

USES=			cmake compiler:c++11-lang
USE_GITHUB=		yes
GH_ACCOUNT=		scanse
GH_PROJECT=		sweep-sdk
CMAKE_SOURCE_PATH=	${WRKSRC}/libsweep
USE_LDCONFIG=		yes

OPTIONS_DEFINE=		NO_DEVICE
NO_DEVICE_DESC=		The library will generate dummy static point cloud
NO_DEVICE_CMAKE_BOOL=	DUMMY

.include <bsd.port.mk>
