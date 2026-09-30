PORTNAME=	sisl
DISTVERSIONPREFIX=	SISL-
DISTVERSION=	4.6.0-100
DISTVERSIONSUFFIX=	-ge0a82b1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spline library
WWW=		https://github.com/SINTEF-Geometry/SISL

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	SINTEF-Geometry
GH_PROJECT=	SISL
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/SINTEF-Geometry/SISL/issues/66

.include <bsd.port.mk>
