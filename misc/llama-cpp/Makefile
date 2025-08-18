PORTNAME=	llama-cpp
DISTVERSIONPREFIX=	b
DISTVERSION=	6191
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's LLaMA model in C/C++ # '
WWW=		https://github.com/ggerganov/llama.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278810
BROKEN_i386=	compilation fails, see https://github.com/ggerganov/llama.cpp/issues/9545

USES=		cmake:testing compiler:c++11-lang python:run shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov
GH_PROJECT=	llama.cpp
GH_TUPLE=	nomic-ai:kompute:4565194:kompute/kompute

SHEBANG_GLOB=	*.py

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	GGML_NATIVE \
		FREEBSD_ALLOW_ADVANCED_CPU_FEATURES \
		LLAMA_BUILD_TESTS
CMAKE_TESTING_ON=	LLAMA_BUILD_TESTS

# user for llama-server, only used when EXAMPLES=ON
USER=		nobody
SUB_LIST=	USER=${USER}

OPTIONS_DEFINE=		CURL EXAMPLES VULKAN
OPTIONS_DEFAULT=	CURL VULKAN
OPTIONS_SUB=		yes

CURL_DESCR=		Use libcurl to download model from an URL
CURL_CMAKE_BOOL=	LLAMA_CURL
CURL_USES=		localbase
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

EXAMPLES_CMAKE_BOOL=	LLAMA_BUILD_EXAMPLES

VULKAN_DESC=		Vulkan GPU offload support
VULKAN_CMAKE_BOOL=	GGML_VULKAN
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

BINARY_ALIAS=	git=false \
		python=${PYTHON_CMD} # for tests

post-patch: # set version in the code
	@${REINPLACE_CMD} \
		-e "s|set(BUILD_NUMBER 0)|set(BUILD_NUMBER ${DISTVERSION})|" \
		${WRKSRC}/cmake/build-info.cmake

do-test-ci: # build of tests fails, see https://github.com/ggerganov/llama.cpp/issues/10955
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} bash ci/run.sh ./tmp/results ./tmp/mnt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
USE_RC_SUBR=	llama-server
.endif

# tests as of 4458: 97% tests passed, 1 tests failed out of 31, see https://github.com/ggerganov/llama.cpp/issues/11036

# tests as of 4649:
# 88% tests passed, 4 tests failed out of 32
# The following tests FAILED:
#         18 - test-chat (Subprocess aborted)                    main   # see https://github.com/ggerganov/llama.cpp/issues/11705
#         24 - test-gguf (SEGFAULT)                              main
#         25 - test-backend-ops (SEGFAULT)                       main
#         32 - test-eval-callback (SEGFAULT)                     curl eval-callback

.include <bsd.port.mk>
