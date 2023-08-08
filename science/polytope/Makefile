PORTNAME=	polytope
DISTVERSION=	0.7.3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for generating Voronoi and Voronoi-like tessellations
WWW=		https://github.com/pbtoast/polytope

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/geometry.hpp:devel/boost-libs
LIB_DEPENDS=	libsz.so:science/libaec

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pbtoast

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	TESTING
CMAKE_TESTING_ON=	TESTING # 1 test is known to fail, see https://github.com/pbtoast/polytope/issues/18

OPTIONS_DEFINE=		SILO
OPTIONS_DEFAULT=	SILO

SILO_DESC=		Use SILO reader/writer
SILO_CMAKE_BOOL=	USE_SILO
SILO_LIB_DEPENDS=	libsiloh5.so:science/silo

.include <bsd.port.mk>
