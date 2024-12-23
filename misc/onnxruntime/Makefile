PORTNAME=	onnxruntime
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.2
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, high performance ML inferencing & training accelerator
WWW=		https://onnxruntime.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails: error: no member named 'linux_id' in 'cpuinfo_processor', see https://github.com/microsoft/onnxruntime/issues/23181
BROKEN_i386=	compilation fails: error: requested alignment is less than minimum alignment of 8 for type 'google::protobuf::internal::ThreadSafeArena::CacheAlignedLifecycleIdGenerator'

BUILD_DEPENDS=	gpatch:devel/patch
LIB_DEPENDS=	libabsl_base.so:devel/abseil

USES=		cmake:testing compiler:c++11-lang python:build

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_TUPLE=	emscripten-core:emsdk:d52c465:emsdk/cmake/external/emsdk \
		google:libprotobuf-mutator:7a2ed51:libprotobuf_mutator/cmake/external/libprotobuf-mutator \
		onnx:onnx:595228d:onnx/cmake/external/onnx

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_OFF=	FETCHCONTENT_FULLY_DISCONNECTED \
		onnxruntime_BUILD_UNIT_TESTS
CMAKE_TESTING_ON=	onnxruntime_BUILD_UNIT_TESTS

BINARY_ALIAS=	patch=gpatch

DEPS_FILE=	${WRKSRC}/cmake/deps.txt

CONFLICTS_BUILD=	abseil benchmark nsync googletest dlpack flatbuffers gsl mimalloc \
			nlohmann-json onnx protobuf psimd pthreadpool pybind11 re2

dev-update-deps-in-makefiles: extract # this should be run when the port is updated
	@${FILEDIR}/convert-deps.sh ${DEPS_FILE}

pre-configure:
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.zip);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}

# NOTE there should be an EXTRACT_ONLY statement
# NOTE shared libs can't be enabled because the build would fail, see discussion in this issue: https://github.com/microsoft/onnxruntime/issues/22331

.include <Makefile.MASTER_SITES>
.include <Makefile.DISTFILES>
.include <bsd.port.mk>
