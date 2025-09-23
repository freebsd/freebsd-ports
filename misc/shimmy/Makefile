PORTNAME=	shimmy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2
CATEGORIES=	misc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Privacy-first alternative to Ollama
WWW=		https://github.com/Michael-A-Kuykendall/shimmy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo llvm ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Michael-A-Kuykendall

CARGO_FEATURES=	full
CARGO_TEST_ARGS=--lib --all-features

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md ROADMAP.md SECURITY.md

OPTIONS_DEFINE=	DOCS VULKAN
OPTIONS_DEFAULT=VULKAN

VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_USES=		localbase:ldflags
VULKAN_VARS=		CARGO_FEATURES+=llama-cpp-2/vulkan

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
