PORTNAME=	onnxruntime
DISTVERSIONPREFIX=	v
DISTVERSION=	1.23.2
CATEGORIES=	misc # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, high performance ML inferencing & training accelerator
WWW=		https://onnxruntime.ai/ \
		https://github.com/microsoft/onnxruntime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error: no member named 'linux_id' in 'cpuinfo_processor', see https://github.com/microsoft/onnxruntime/issues/23181
BROKEN_aarch64=	compilation fails: error: no member named 'linux_id' in 'cpuinfo_processor', see https://github.com/microsoft/onnxruntime/issues/23181
BROKEN_i386=	compilation fails: error: requested alignment is less than minimum alignment of 8 for type 'google::protobuf::internal::ThreadSafeArena::CacheAlignedLifecycleIdGenerator'

BUILD_DEPENDS=	gpatch:devel/patch

USES=		cmake:testing compiler:c++11-lang python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_TUPLE=	emscripten-core:emsdk:0742117:emsdk/cmake/external/emsdk \
		google:libprotobuf-mutator:7a2ed51a6b682a83e345ff49fc4cfd7ca47550db:libprotobuf_mutator/cmake/external/libprotobuf-mutator \
		onnx:onnx:b8baa8446686496da4cc8fda09f2b6fe65c2a02c:onnx/cmake/external/onnx

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ON=	onnxruntime_BUILD_SHARED_LIB
CMAKE_OFF=	FETCHCONTENT_FULLY_DISCONNECTED \
		onnxruntime_BUILD_UNIT_TESTS
CMAKE_ARGS=	-Donnx_SOURCE_DIR=${WRKSRC}/cmake/external/onnx
CMAKE_TESTING_ON=	onnxruntime_BUILD_UNIT_TESTS

CXXFLAGS+=	-Wno-array-bounds # workaround for https://github.com/microsoft/onnxruntime/issues/23410
CXXFLAGS+=	-I${WRKSRC}/include/onnxruntime/core/common/logging # otherwise logging.h isn't found
CXXFLAGS+=	-frtti # fixes error: onnxruntime/test/contrib_ops/gather_block_quantized_op_test.cc:85:77: error: use of typeid requires -frtti

BINARY_ALIAS=	patch=gpatch

DEPS_FILE=	${WRKSRC}/cmake/deps.txt

CONFLICTS_BUILD=	abseil benchmark nsync googletest dlpack flatbuffers gsl mimalloc \
			nlohmann-json onnx protobuf psimd pthreadpool pybind11 re2

dev-update-deps-in-makefiles: extract # this should be run when the port is updated
	@${FILESDIR}/convert-deps.sh ${DEPS_FILE}

pre-configure:
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.zip);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}

# NOTE there should be an EXTRACT_ONLY statement
# NOTE shared libs can't be enabled because the build would fail, see discussion in this issue: https://github.com/microsoft/onnxruntime/issues/22331

# tests as of 1.21.1 (cd work/.build && ./onnxruntime_test_all):
# [==========] 4743 tests from 310 test suites ran. (321548 ms total)
# [  PASSED  ] 4732 tests.
# [  FAILED  ] 1 test, listed below:
# [  FAILED  ] OptimizerInitializerTest.LoadExternalData
# see https://github.com/microsoft/onnxruntime/issues/23816

.include <Makefile.MASTER_SITES>
.include <Makefile.DISTFILES>
.include <bsd.port.mk>
