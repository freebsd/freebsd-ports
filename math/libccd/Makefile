PORTNAME=	libccd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for collision detection between two convex shapes
WWW=		https://github.com/danfis/libccd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	danfis
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOUBLE_PECISION

DOUBLE_PECISION_DESC=		Enable double precision computations
DOUBLE_PECISION_CMAKE_BOOL=	ENABLE_DOUBLE_PRECISION

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/danfis/libccd/issues/85

.include <bsd.port.mk>
