PORTNAME=	ncnn
DISTVERSION=	20210525
CATEGORIES=	misc # machine-learning

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
VULKAN_BUILD_DEPENDS=	glslang>0:graphics/glslang \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
			${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader
VULKAN_CMAKE_BOOL=	NCNN_VULKAN NCNN_SYSTEM_GLSLANG
VULKAN_CMAKE_ON=	-DGLSLANG_TARGET_DIR:PATH="${LOCALBASE}/lib/cmake"

post-patch-VULKAN-on:
	@${REINPLACE_CMD} 's,/glslang,,' ${WRKSRC}/src/gpu.cpp

.include <bsd.port.mk>
