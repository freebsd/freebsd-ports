PORTNAME=	onnxruntime
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.2
CATEGORIES=	misc # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, high performance ML inferencing & training accelerator
WWW=		https://onnxruntime.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gpatch:devel/patch
LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		cmake:testing compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_TUPLE=	emscripten-core:emsdk:d52c465:emsdk/cmake/external/emsdk \
		google:libprotobuf-mutator:7a2ed51:libprotobuf_mutator/cmake/external/libprotobuf-mutator \
		onnx:onnx:595228d:onnx/cmake/external/onnx

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FETCHCONTENT_FULLY_DISCONNECTED \
		onnxruntime_BUILD_UNIT_TESTS
CMAKE_TESTING_ON=	onnxruntime_BUILD_UNIT_TESTS

BINARY_ALIAS=	patch=gpatch

DEPS_FILE=	${WRKSRC}/cmake/deps.txt

dev-update-deps-in-makefiles: extract # this should be run when the port is updated
	@${FILEDIR} ${DEPS_FILE}

pre-configure:
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.zip);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}

# there should be an EXTRACT_ONLY statement
#
# this port is broken at least in some ways: it has missing symbols due to excessive
# and incorrect bundling, see https://github.com/microsoft/onnxruntime/issues/22331
# it still might be useful for some purposes, hence static libraries are installed instead of shared ones

.include <Makefile.MASTER_SITES>
.include <Makefile.DISTFILES>
.include <bsd.port.mk>
