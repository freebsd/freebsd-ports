PORTNAME=	ggml
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tensor library for machine learning
WWW=		https://github.com/ggml-org/ggml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: LLVM ERROR: out of memory

BUILD_DEPENDS=	spirv-headers>0:graphics/spirv-headers

USES=		cmake:testing compiler:c++17-lang llvm:build,min=22 python:run shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ggml-org

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	GGML_NATIVE \
		GGML_BUILD_TESTS \
		GGML_BUILD_EXAMPLES \
		GGML_SSE42 \
		GGML_AVX \
		GGML_AVX2 \
		GGML_BMI2 \
		GGML_FMA \
		GGML_F16C
CMAKE_TESTING_ON=	GGML_BUILD_TESTS

SO_SUFFIX=	${PORTVERSION}

BINARY_ALIAS=	git=false

PLIST_SUB+=	SO_SUFFIX=${SO_SUFFIX}

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN
OPTIONS_SUB=		yes

VULKAN_CMAKE_BOOL=	GGML_VULKAN
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

# tests as of 0.26.0: 95% tests passed, 1 tests failed out of 21 # 1 test (test-backend-ops) failed due to OOM in a Vulkan device

.include <bsd.port.mk>
