PORTNAME=	polytope
DISTVERSION=	0.7.4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for generating Voronoi and Voronoi-like tessellations
WWW=		https://github.com/LLNL/polytope

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/geometry.hpp:devel/boost-libs
LIB_DEPENDS=	libsz.so:science/libaec

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL

CXXFLAGS+=	-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE # prevent hardening issues with libc++, see https://github.com/LLNL/polytope/issues/24

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	TESTING
CMAKE_TESTING_ON=	TESTING

OPTIONS_DEFINE=		SILO
OPTIONS_DEFAULT=	SILO

SILO_DESC=		Use SILO reader/writer
SILO_CMAKE_BOOL=	USE_SILO
SILO_LIB_DEPENDS=	libsiloh5.so:science/silo

# tests as of 0.7.4: 96% tests passed, 1 tests failed out of 28

.include <bsd.port.mk>
