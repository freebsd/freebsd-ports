PORTNAME=	polyclipper
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.6
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
GH_TUPLE=	LLNL:PYB11Generator:7440ebf4bb5cafcf96712a958fe44d336e0793de:PYB11Generator/extern/PYB11Generator

CMAKE_OFF=	POLYCLIPPER_ENABLE_PYTHON POLYCLIPPER_MODULE_GEN POLYCLIPPER_ENABLE_TESTS # avoid needing pybind11/python bindings
CMAKE_TESTING_OFF=	POLYCLIPPER_ENABLE_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

do-test:
.for f in test_array_vector_2d.cc test_array_vector_3d.cc
	@${ECHO} "==> testing $f"
	@cd ${WRKSRC}/test/test_array_vector && \
		${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${f}.bin ${f} -I${STAGEDIR}${PREFIX}/include && \
		./${f}.bin
.endfor

# tests as of 1.2.6: test_array_vector_2d.cc and test_array_vector_3d.cc both compiled and ran successfully

.include <bsd.port.mk>
