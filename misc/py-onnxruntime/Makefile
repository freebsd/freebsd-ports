PORTNAME=	onnxruntime
DISTVERSIONPREFIX=	v
DISTVERSION=	1.27.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform, high performance ML inferencing & training accelerator
WWW=		https://onnxruntime.ai/ \
		https://github.com/microsoft/onnxruntime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		compiler:c++17-lang python

# Build using the official build.py script
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHON_CMD} tools/ci_build/build.py \
		--build_dir ${WRKDIR}/build \
		--config Release \
		--parallel \
		--skip_tests \
		--skip_submodule_sync \
		--allow_running_as_root \
		--cmake_extra_defines CMAKE_INSTALL_PREFIX=${PREFIX} \
		--cmake_extra_defines onnxruntime_BUILD_UNIT_TESTS=OFF

do-install:
	cd ${WRKDIR}/build/Release && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install DESTDIR=${STAGEDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_TUPLE=	emscripten-core:emsdk:0742117:emsdk/cmake/external/emsdk \
		google:libprotobuf-mutator:7a2ed51a6b682a83e345ff49fc4cfd7ca47550db:libprotobuf_mutator/cmake/external/libprotobuf-mutator \
		onnx:onnx:b8baa8446686496da4cc8fda09f2b6fe65c2a02c:onnx/cmake/external/onnx

CXXFLAGS+=	-Wno-array-bounds # workaround for https://github.com/microsoft/onnxruntime/issues/23410
CXXFLAGS+=	-I${WRKSRC}/include/onnxruntime/core/common/logging # otherwise logging.h isn't found

DEPS_FILE=	${WRKSRC}/cmake/deps.txt

CONFLICTS_BUILD=	abseil benchmark nsync googletest dlpack flatbuffers gsl mimalloc \
			nlohmann-json onnx protobuf psimd pthreadpool pybind11 re2

dev-update-deps-in-makefiles: extract # this should be run when the port is updated
	@${FILESDIR}/convert-deps.sh ${DEPS_FILE}

post-patch:
	@${FIND} ${WRKSRC}/cmake/external -name "*.cmake" -exec ${REINPLACE_CMD} -e 's|--binary ||g' {} +

pre-configure:
	@${REINPLACE_CMD} -E 's|;(https://.*)/([^/]+\.zip);|;file://${DISTDIR}/${DIST_SUBDIR}/\2;|' ${DEPS_FILE}

.include <Makefile.MASTER_SITES>
.include <Makefile.DISTFILES>
.include <bsd.port.mk>
