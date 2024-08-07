PORTNAME=	ollama
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run Llama 2, Mistral, and other large language models
WWW=		https://ollama.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libllama.so:misc/llama-cpp \
		libvulkan.so:graphics/vulkan-loader

USES=		go:1.22,modules pkgconfig

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	.

USE_GITHUB=	nodefault
GH_TUPLE=	ggerganov:llama.cpp:6eeaeba:llama_cpp/llm/llama.cpp

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	@${CP} ${WRKSRC}/app/store/store_linux.go ${WRKSRC}/app/store/store_bsd.go
	@cd ${GO_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} generate ${GO_BUILDFLAGS} \
			./...

.include <bsd.port.mk>
