PORTNAME=	llama-cpp
DISTVERSIONPREFIX=	b
DISTVERSION=	10975
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://huggingface.co/buckets/ggml-org/llama-ui/resolve/${UI_ASSETS_TAG}/:ui_assets
DISTFILES=	dist.tar.gz:ui_assets \
		dist.tar.gz.sha256:ui_assets
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's LLaMA model in C/C++ # '
WWW=		https://github.com/ggml-org/llama.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libggml-base.so:misc/ggml

USES=		cmake:testing compiler:c++11-lang python:run shebangfix ssl

BROKEN_armv7=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278810
BROKEN_i386=	compilation fails, see https://github.com/ggml-org/llama.cpp/issues/9545

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggml-org
GH_PROJECT=	llama.cpp

SHEBANG_GLOB=	*.py

UI_ASSETS_TAG=	b10970

CMAKE_ON=	BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS \
		LLAMA_USE_SYSTEM_GGML
CMAKE_OFF=	GGML_NATIVE \
		FREEBSD_ALLOW_ADVANCED_CPU_FEATURES \
		LLAMA_BUILD_TESTS
CMAKE_TESTING_ON=	LLAMA_BUILD_TESTS

# user for llama-server, only used when EXAMPLES=ON
USER=		nobody
SUB_LIST=	USER=${USER}

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	LLAMA_BUILD_EXAMPLES

BINARY_ALIAS=	git=false \
		python=${PYTHON_CMD} # for tests

post-patch:
	# set version in the code
	@${REINPLACE_CMD} \
		-e "s|set(BUILD_NUMBER 0)|set(BUILD_NUMBER ${DISTVERSION})|" \
		${WRKSRC}/cmake/build-info.cmake
	# update UI assets URL to point to fetched files
	@${REINPLACE_CMD} \
		-e "s|https://huggingface.co/buckets/.{HF_BUCKET}/resolve/.{resolved}|file://${DISTDIR}/${DIST_SUBDIR}|" \
		${WRKSRC}/scripts/ui-assets.cmake

do-test-ci: # build of tests fails, see https://github.com/ggml-org/llama.cpp/issues/10955
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} bash ci/run.sh ./tmp/results ./tmp/mnt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
USE_RC_SUBR=	llama-server
.endif

# tests as of 4458: 97% tests passed, 1 tests failed out of 31, see https://github.com/ggml-org/llama.cpp/issues/11036

# tests as of 4649:
# 88% tests passed, 4 tests failed out of 32
# The following tests FAILED:
#         18 - test-chat (Subprocess aborted)                    main   # see https://github.com/ggml-org/llama.cpp/issues/11705
#         24 - test-gguf (SEGFAULT)                              main
#         25 - test-backend-ops (SEGFAULT)                       main
#         32 - test-eval-callback (SEGFAULT)                     curl eval-callback

.include <bsd.port.mk>
