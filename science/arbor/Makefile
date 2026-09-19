PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/ \
		https://github.com/arbor-sim/arbor/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/cmake/GTest/GTestConfig.cmake:devel/googletest \
		libfmt>=12.1.0:devel/libfmt \
		nlohmann-json>=3.12.0:devel/nlohmann-json \
		random123>=1.14.0:devel/random123 \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.3:graphics/py-svgwrite@${PY_FLAVOR} \
		tinyopt>=1.0.8:devel/tinyopt
LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libpugixml.so:textproc/pugixml \
		libunits.so:misc/units
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.3:graphics/py-svgwrite@${PY_FLAVOR}
TEST_DEPENDS=	googletest>=1.16.0:devel/googletest

USES=		cmake compiler:c++20-lang localbase pkgconfig python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim
GH_TUPLE=	cpm-cmake:CPM.cmake:v0.39.0:cpm \
		martinus:unordered_dense:v4.5.0:unordered_dense/external/unordered_dense

SHEBANG_FILES=	scripts/arbor-build-catalogue

CMAKE_ON=	BUILD_SHARED_LIBS
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

# tests as of 0.12.2: 1084 tests from 167 test suites ran and 111 tests from 19 test suites ran, all passed

.include <bsd.port.mk>
