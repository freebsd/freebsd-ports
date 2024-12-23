PORTNAME=	llama-cpp
DISTVERSIONPREFIX=	b
DISTVERSION=	4381
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's LLaMA model in C/C++ # '
WWW=		https://github.com/ggerganov/llama.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278810
BROKEN_i386=	compilation fails, see https://github.com/ggerganov/llama.cpp/issues/9545

USES=		cmake:testing compiler:c++11-lang python:run,test shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov
GH_PROJECT=	llama.cpp
GH_TUPLE=	nomic-ai:kompute:4565194:kompute/kompute

SHEBANG_GLOB=	*.py

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	LLAMA_BUILD_TESTS
CMAKE_TESTING_ON=	LLAMA_BUILD_TESTS

OPTIONS_DEFINE=		EXAMPLES VULKAN
OPTIONS_DEFAULT=	VULKAN
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	LLAMA_BUILD_EXAMPLES

VULKAN_DESC=		Vulkan GPU offload support
VULKAN_CMAKE_BOOL=	GGML_VULKAN
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

BINARY_ALIAS=	git=false \
		python3=${PYTHON_CMD}

do-test-ci: # build of tests fails, see https://github.com/ggerganov/llama.cpp/issues/10955
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} bash ci/run.sh ./tmp/results ./tmp/mnt

# tests as of 4381: 97% tests passed, 1 tests failed out of 31

.include <bsd.port.mk>
