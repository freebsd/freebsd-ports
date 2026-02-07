PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/ \
		https://github.com/arbor-sim/arbor/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_armv7=	compilation fails: unknown type name 'float64x2_t'

BUILD_DEPENDS=	bash:shells/bash \
		libfmt>0:devel/libfmt \
		nlohmann-json>0:devel/nlohmann-json \
		random123>0:devel/random123 \
		${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR} \
		tinyopt>0:devel/tinyopt
BUILD_DEPENDS+=	${LOCALBASE}/lib/cmake/GTest/GTestConfig.cmake:devel/googletest # https://github.com/arbor-sim/arbor/issues/2205
LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libpugixml.so:textproc/pugixml \
		libunits.so:misc/units
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR}
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++20-lang localbase pkgconfig python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim
GH_TUPLE=	cpm-cmake:CPM.cmake:v0.39.0:cpm

SHEBANG_FILES=	scripts/arbor-build-catalogue

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ARB_USE_BUNDLED_UNITS
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

CONFIGURE_ENV=	CPM_REPO=${WRKSRC_cpm}
CXXFLAGS+=	-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE # prevent hardening issues with libc++, see https://github.com/arbor-sim/arbor/issues/2484
LDFLAGS+=	-L${LOCALBASE}/lib -lunits

OPTIONS_DEFINE=		NATIVE

NATIVE_CMAKE_ON=	-DARB_ARCH=native
NATIVE_CMAKE_OFF=	-DARB_ARCH=none

TEST_TARGET=	tests

post-install:
	@${RMDIR} ${STAGEDIR}${DOCSDIR}

post-test: # run tests
	@${BUILD_WRKSRC}/bin/unit
	@${BUILD_WRKSRC}/bin/unit-local
	@${BUILD_WRKSRC}/bin/unit-modcc

# tests fail with LIBCPP assertion for invalid array element access, see https://github.com/arbor-sim/arbor/issues/2484

.include <bsd.port.mk>
