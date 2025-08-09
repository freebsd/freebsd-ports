PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/ \
		https://github.com/arbor-sim/arbor/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/arbor-sim/arbor/issues/2424
BROKEN_armv7=	compilation fails: unknown type name 'float64x2_t'

BUILD_DEPENDS=	bash:shells/bash \
		libfmt>0:devel/libfmt \
		nlohmann-json>0:devel/nlohmann-json \
		random123>0:devel/random123 \
		${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR}
BUILD_DEPENDS+=	${LOCALBASE}/lib/cmake/GTest/GTestConfig.cmake:devel/googletest # https://github.com/arbor-sim/arbor/issues/2205
LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libpugixml.so:textproc/pugixml \
		libunits.so:misc/units
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR}
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake compiler:c++17-lang localbase python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim

SHEBANG_FILES=	scripts/arbor-build-catalogue

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ARB_USE_BUNDLED_UNITS
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

LDFLAGS+=	-L${LOCALBASE}/lib -lunits

OPTIONS_DEFINE=		NATIVE

NATIVE_CMAKE_ON=	-DARB_ARCH=native
NATIVE_CMAKE_OFF=	-DARB_ARCH=none

TEST_TARGET=	tests # tests fail to build, see https://github.com/arbor-sim/arbor/issues/2075

post-install:
	@${RMDIR} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
