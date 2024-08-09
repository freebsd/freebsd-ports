PORTNAME=	llama-cpp
DISTVERSIONPREFIX=	b
DISTVERSION=	3560
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Facebook's LLaMA model in C/C++ # '
WWW=		https://github.com/ggerganov/llama.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=278810

USES=		cmake:testing compiler:c++11-lang python:run shebangfix
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

BINARY_ALIAS=	git=false

# 2 tests fail: https://github.com/ggerganov/llama.cpp/issues/8906

.include <bsd.port.mk>
