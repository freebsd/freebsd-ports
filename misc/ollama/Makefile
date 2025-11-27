PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1-rc0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run Llama 2, Mistral, and other large language models
WWW=		https://ollama.com \
		https://github.com/ollama/ollama

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	bundled patched llama-cpp is placed into the arch-specific path

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		glslc:graphics/shaderc \
		vulkan-headers>0:graphics/vulkan-headers \
		${LOCALBASE}/include/miniaudio/miniaudio.h:audio/miniaudio \
		${LOCALBASE}/include/nlohmann/json_fwd.hpp:devel/nlohmann-json \
		${LOCALBASE}/include/stb/stb_image.h:devel/stb
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		go:1.24,modules localbase pkgconfig

GO_MODULE=	github.com/yurivict/${PORTNAME} # fork with FreeBSD patches
GO_TARGET=	.
GO_ENV+=	CGO_CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/${PORTNAME} \
		bin/ollama-limit-gpu-layers

post-patch: # change import path to the fork
	@cd ${WRKSRC} && \
		(${GREP} -rl ollama/ollama | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|ollama/ollama|yurivict/ollama|g')

post-install: # pending https://github.com/ollama/ollama/issues/6407
	${INSTALL_SCRIPT} ${FILESDIR}/ollama-limit-gpu-layers ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
