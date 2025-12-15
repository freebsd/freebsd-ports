PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1-rc0
PORTREVISION=	2
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run Llama 2, Mistral, and other large language models
WWW=		https://ollama.com \
		https://github.com/ollama/ollama

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/miniaudio/miniaudio.h:audio/miniaudio \
		${LOCALBASE}/include/nlohmann/json_fwd.hpp:devel/nlohmann-json \
		${LOCALBASE}/include/stb/stb_image.h:devel/stb

USES=		cmake:indirect go:1.24+,modules localbase pkgconfig

GO_MODULE=	github.com/yurivict/${PORTNAME} # fork with FreeBSD patches
GO_TARGET=	.
GO_ENV+=	CGO_CXXFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/${PORTNAME} \
		bin/ollama-limit-gpu-layers

OPTIONS_GROUP=		BACKENDS
OPTIONS_GROUP_BACKENDS=	CPU VULKAN
OPTIONS_DEFAULT=	CPU VULKAN

CPU_DESC=		Build CPU backend shared libraries
CPU_PLIST_FILES=	lib/ollama/libggml-base.so \
			lib/ollama/libggml-cpu-alderlake.so \
			lib/ollama/libggml-cpu-haswell.so \
			lib/ollama/libggml-cpu-icelake.so \
			lib/ollama/libggml-cpu-sandybridge.so \
			lib/ollama/libggml-cpu-skylakex.so \
			lib/ollama/libggml-cpu-sse42.so \
			lib/ollama/libggml-cpu-x64.so

VULKAN_DESC=		Build Vulkan GPU backend shared library
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_PLIST_FILES=	lib/ollama/libggml-vulkan.so

.include <bsd.port.options.mk>

_CMAKE_FLAGS=	-DCMAKE_BUILD_TYPE=Release -DGGML_BACKEND_DL=ON -DGGML_BACKEND_DIR=${PREFIX}/lib/ollama

post-patch: # change import path to the fork
	@cd ${WRKSRC} && \
		(${GREP} -rl ollama/ollama | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|ollama/ollama|yurivict/ollama|g')

pre-build-CPU-on:
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		${CMAKE_BIN} ${_CMAKE_FLAGS} .. && \
		${MAKE_CMD} ggml-base && \
		${MAKE_CMD} ggml-cpu

pre-build-VULKAN-on:
.if !${PORT_OPTIONS:MCPU}
	@${MKDIR} ${WRKSRC}/build && \
		cd ${WRKSRC}/build && \
		${CMAKE_BIN} ${_CMAKE_FLAGS} ..
.endif
	@cd ${WRKSRC}/build && \
		${MAKE_CMD} ggml-vulkan

post-install: # pending https://github.com/ollama/ollama/issues/6407
	${INSTALL_SCRIPT} ${FILESDIR}/ollama-limit-gpu-layers ${STAGEDIR}${PREFIX}/bin

post-install-CPU-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libggml-base.so \
		${STAGEDIR}${PREFIX}/lib/ollama/
	@for f in ${WRKSRC}/build/lib/ollama/libggml-cpu*.so; do \
		${INSTALL_LIB} $$f ${STAGEDIR}${PREFIX}/lib/ollama/; \
	done

post-install-VULKAN-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ollama
	${INSTALL_LIB} ${WRKSRC}/build/lib/ollama/libggml-vulkan.so \
		${STAGEDIR}${PREFIX}/lib/ollama/

do-test:
	@cd ${WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ./...

.include <bsd.port.mk>
