PORTNAME=	ggml
DISTVERSION=	g20250828
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tensor library for machine learning
WWW=		https://github.com/ggerganov/ggml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang python:run shebangfix
USE_LDCONFIG=	yes

BROKEN_i386=	compilation fails: LLVM ERROR: out of memory

USE_GITHUB=	yes
GH_ACCOUNT=	ggerganov
GH_TAGNAME=	83835ff

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	GGML_BUILD_TESTS GGML_BUILD_EXAMPLES
CMAKE_TESTING_ON=	GGML_BUILD_TESTS

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN
OPTIONS_SUB=		yes

VULKAN_CMAKE_BOOL=	GGML_VULKAN
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

# tests as of g20250828: 100% tests passed, 0 tests failed out of 21

.include <bsd.port.mk>
