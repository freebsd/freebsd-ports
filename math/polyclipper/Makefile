PORTNAME=	polyclipper
DISTVERSION=	1.2.4
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to clip polygons (in 2D) and polyhedra (in 3D) by planes
WWW=		https://github.com/LLNL/PolyClipper

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	PolyClipper
GH_TUPLE=	jmikeowen:PYB11Generator:eb954d0:PYB11Generator/extern/PYB11Generator

CMAKE_ON=	ENABLE_CXXONLY # otherwise it looks for python2
CMAKE_OFF=	BUILD_TESTING
CMAKE_TESTING_OFF=	BUILD_TESTING

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
.for f in test_array_vector_2d.cc test_array_vector_3d.cc
	@${ECHO} "==> testing $f"
	@cd ${WRKSRC}/test/test_array_vector && \
		${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${f}.bin ${f} -I${STAGEDIR}${PREFIX}/include && \
		./${f}.bin
.endfor

.include <bsd.port.mk>
