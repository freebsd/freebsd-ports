PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run Llama 2, Mistral, and other large language models
WWW=		https://ollama.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	bundled patched llama-cpp is placed into the arch-specific path

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		glslc:graphics/shaderc \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		go:1.22,modules pkgconfig

CONFLICTS_BUILD=	llama-cpp

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	.

USE_GITHUB=	nodefault
GH_TUPLE=	ggerganov:llama.cpp:1e6f6554aa11fa10160a5fda689e736c3c34169f:llama_cpp/llm/llama.cpp \
		blabber:go-freebsd-sysctl:503969f:go_sysctl/vendor.x/github.com/blabber/go-freebsd-sysctl

MAKE_ENV=	PATH=${PATH}:${WRKSRC}/llm/build/bsd/x86_64_static/bin # workaround to find vulkan-shaders-gen

PLIST_FILES=	bin/${PORTNAME} \
		bin/ollama-limit-gpu-layers

post-patch: # workaround for https://github.com/ollama/ollama/issues/6259 (use of extenral libllama.so)
	@${REINPLACE_CMD} \
		-e '\
			s| llama | llama ${LOCALBASE}/lib/libvulkan.so omp pthread |; \
			s| llama | ${WRKSRC}/llm/build/bsd/x86_64_static/src/libllama.a |; \
			s| ggml | ${WRKSRC}/llm/build/bsd/x86_64_static/ggml/src/libggml.a |; \
		' \
		${WRKSRC}/llm/ext_server/CMakeLists.txt
	# move vendor.x to vendor
	@(cd ${WRKSRC}/vendor.x && ${TAR} cf - .) | (cd ${WRKSRC}/vendor && ${TAR} xf -)

pre-build:
	@${CP} ${WRKSRC}/app/store/store_linux.go ${WRKSRC}/app/store/store_bsd.go
	@cd ${GO_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} generate ${GO_BUILDFLAGS} \
			./...

post-install: # pending https://github.com/ollama/ollama/issues/6407
	${INSTALL_SCRIPT} ${FILESDIR}/ollama-limit-gpu-layers ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
