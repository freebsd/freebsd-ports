PORTNAME=	shimmy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	misc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Privacy-first alternative to Ollama
WWW=		https://github.com/Michael-A-Kuykendall/shimmy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo llvm

USE_GITHUB=	yes
GH_ACCOUNT=	Michael-A-Kuykendall

CARGO_FEATURES=	llama-opencl
CARGO_TEST_ARGS=--lib

MAKE_ENV=	GGML_NATIVE=OFF

PLIST_FILES=	bin/create_realistic_safetensors \
		bin/create_test_safetensors \
		bin/${PORTNAME} \
		bin/test_real_safetensors
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md DEVELOPERS.md README.md \
		ROADMAP.md SECURITY.md

OPTIONS_DEFINE=		DOCS VISION VULKAN
OPTIONS_DEFAULT=	VISION VULKAN
# i386 build with VULKAN fails with: LLVM ERROR: out of memory
OPTIONS_EXCLUDE_i386=	VULKAN

VISION_DESC=	Visual image/web analysis support

VISION_VARS=	CARGO_FEATURES+=vision
VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_USES=		localbase:ldflags
VULKAN_VARS=		CARGO_FEATURES+="llama-vulkan shimmy-llama-cpp-2/vulkan"

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
