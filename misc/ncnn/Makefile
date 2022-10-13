PORTNAME=	ncnn
DISTVERSION=	20220729
PORTREVISION=	2
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance neural network inference framework
WWW=		https://github.com/Tencent/ncnn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Tencent

#CMAKE_ON=		NCNN_SHARED_LIB NCNN_ENABLE_LTO # NCNN_SHARED_LIB=ON causes variability in the shared library name, see https://github.com/Tencent/ncnn/issues/4234
CMAKE_TESTING_ON=	NCNN_BUILD_TESTS # in order to run tests please disable NCNN_SHARED_LIB above; many tests fail, see https://github.com/Tencent/ncnn/issues/4233

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN

VULKAN_DESC=		Vulkan compute support
VULKAN_GH_TUPLE=	KhronosGroup:glslang:11.9.0-19-g86ff4bca:glslang/glslang
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	NCNN_VULKAN

.include <bsd.port.mk>
