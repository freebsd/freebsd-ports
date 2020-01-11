# $FreeBSD$

PORTNAME=	ncnn
DISTVERSION=	20200106
CATEGORIES=	science # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance neural network inference framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Tencent

OPTIONS_DEFINE=		VULKAN
OPTIONS_DEFAULT=	VULKAN

VULKAN_DESC=		Vulkan compute support
VULKAN_CMAKE_BOOL=	NCNN_VULKAN
VULKAN_BUILD_DEPENDS=	glslangValidator:devel/glslang \
			${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers \
			${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader

.include <bsd.port.mk>
