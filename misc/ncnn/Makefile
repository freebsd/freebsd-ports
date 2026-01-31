PORTNAME=	ncnn
DISTVERSION=	20260113
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance neural network inference framework
WWW=		https://github.com/Tencent/ncnn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libabsl_flags_program_name.so:devel/abseil \
		libprotobuf.so:devel/protobuf

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Tencent

CMAKE_ON=		NCNN_SYSTEM_GLSLANG
CMAKE_TESTING_ON=	NCNN_BUILD_TESTS

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN

VULKAN_DESC=		Vulkan compute support
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		glslangValidator:graphics/glslang
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	NCNN_VULKAN

.include <bsd.port.mk>
