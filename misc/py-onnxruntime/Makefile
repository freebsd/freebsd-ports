PORTNAME=	onnxruntime
#DISTVERSIONPREFIX=	v
DISTVERSION=	1.32.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, high performance ML inferencing & training accelerator
WWW=		https://onnxruntime.ai/ \
		https://github.com/microsoft/onnxruntime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: error: always_inline function '_mm_setzero_si128' requires target feature 'sse2', but would be inlined into function 'MlasConvDepthwiseKernel' that is compiled without support for 'sse2'

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.6:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21.6:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.25.8:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flatbuffers>=0:devel/py-flatbuffers@${PY_FLAVOR}

USES=		compiler:c++17-lang python
USE_PYTHON=	pep517 autoplist concurrent

# Build using the official build.py script
PEP517_BUILD_DEPEND=

MAKE_ENV+=	ORT_DIST_DIR=${WRKSRC}/dist

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHON_CMD} tools/ci_build/build.py \
		--build_dir ${WRKDIR}/build \
		--config Release \
		--parallel \
		--skip_tests \
		--skip_submodule_sync \
		--allow_running_as_root \
		--enable_pybind \
		--build_wheel \
		--cmake_extra_defines CMAKE_INSTALL_PREFIX=${PREFIX} \
		--cmake_extra_defines onnxruntime_BUILD_UNIT_TESTS=OFF \
		--cmake_extra_defines ONNXRUNTIME_NUMPY_INCLUDE_DIR=${PYTHONPREFIX_SITELIBDIR}/numpy/_core/include

USE_GITHUB=	nodefault
#GH_ACCOUNT=	microsoft
GH_TUPLE=	emscripten-core:emsdk:c0bb220cb6e6f4e0fabb6f6db9efd53390ef5e56:emsdk/cmake/external/emsdk \
		google:libprotobuf-mutator:4373c81cd7d50a65f7fbd8dc3779c0c3b1dc9d72:libprotobuf_mutator/cmake/external/libprotobuf-mutator \
		onnx:onnx:e1ac8e74b620bbdc7ba07f0440806bd93f651a28:onnx/cmake/external/onnx

CXXFLAGS+=	-Wno-array-bounds # workaround for https://github.com/microsoft/onnxruntime/issues/23410
CXXFLAGS+=	-I${WRKSRC}/include/onnxruntime/core/common/logging # otherwise logging.h isn't found
CXXFLAGS_aarch64=	-Wno-error=unused-const-variable # kleidiai halfgemm_kleidiai.cpp: unused variable 'Sve2p1HalfGemmKernelName' when kernel logging is off
CXXFLAGS_powerpc64=	-Wno-error=deprecated-declarations -Wno-error=deprecated-altivec-src-compat
CXXFLAGS_powerpc64le=	-Wno-error=deprecated-declarations

DEPS_FILE=	${WRKSRC}/cmake/deps.txt

CONFLICTS_BUILD=	abseil benchmark nsync googletest dlpack flatbuffers gsl mimalloc \
			nlohmann-json onnx protobuf psimd pthreadpool pybind11 re2

dev-update-deps-in-makefiles: extract # this should be run when the port is updated
	@${FILESDIR}/convert-deps.sh ${DEPS_FILE}

post-patch:
	@${FIND} ${WRKSRC}/cmake/external -name "*.cmake" -exec ${REINPLACE_CMD} -e 's|--binary ||g' {} +

pre-configure:
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.zip);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.tar\.gz);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.tar\.xz);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.tar\.bz2);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}
	@${REINPLACE_CMD} -E 's|;https://codeload\.github\.com/([^/]+)/([^/]+)/tar\.gz/refs/tags/([^/]+);|;file://${DISTDIR}/${DIST_SUBDIR}/\3;|' ${DEPS_FILE}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@${ECHO_MSG} "===> Running Python smoke test"
	${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test-smoke.py ${FILESDIR}/example.onnx

# Python smoke test passed: loads example.onnx and runs inference.

.include <Makefile.MASTER_SITES>
.include <Makefile.DISTFILES>
MASTER_SITES+=	LOCAL/yuri/
DISTFILES+=	microsoft-onnxruntime-v1.32.0_GH0.tar.gz
.include <bsd.port.mk>
