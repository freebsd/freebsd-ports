PORTNAME=	libefp
DISTVERSION=	1.8.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Effective fragment potential method in quantum chemistry
WWW=		https://github.com/libefp2/libefp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	libefp2
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DENABLE_XHOST:BOOL=OFF
CMAKE_ARGS+=	-DFRAGLIB_DEEP:BOOL=OFF # configuration in dependencies fails without this
CMAKE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/libefp2/libefp/issues/27

.include <bsd.port.mk>
