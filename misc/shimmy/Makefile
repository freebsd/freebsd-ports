PORTNAME=	shimmy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
CATEGORIES=	misc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Privacy-first alternative to Ollama
WWW=		https://github.com/Michael-A-Kuykendall/shimmy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo dos2unix llvm

USE_GITHUB=	yes
GH_ACCOUNT=	Michael-A-Kuykendall
GH_TUPLE=	ggml-org:llama.cpp:9515c6131aecaccc955fdedcfe16c3e030aaefcb:llama_cpp/../${_CARGO_GIT_WRKDIR}/llama-cpp-sys-2/llama.cpp

DOS2UNIX_FILES=	Cargo.toml

CARGO_FEATURES=	llama-opencl
CARGO_TEST_ARGS=--lib

MAKE_ENV=	GGML_NATIVE=OFF

PLIST_FILES=	bin/create_realistic_safetensors \
		bin/create_test_safetensors \
		bin/${PORTNAME} \
		bin/test_cache_performance \
		bin/test_real_safetensors
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md DEVELOPERS.md README.md \
		ROADMAP.md SECURITY.md SPEC_KIT_INTEGRATION.md

OPTIONS_DEFINE=	DOCS VULKAN
OPTIONS_DEFAULT=VULKAN

VULKAN_BUILD_DEPENDS=	glslc:graphics/shaderc \
			vulkan-headers>0:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader
VULKAN_USES=		localbase:ldflags
VULKAN_VARS=		CARGO_FEATURES+="llama-vulkan llama-cpp-2/vulkan"

.include <bsd.port.pre.mk>

_CARGO_GIT_WRKDIR!=	${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates-git-fetch.awk /dev/null | \
			${CUT} -f 4 -d ' '

post-patch:
	@${BSDMAKE} PATCHDIR=${FILESDIR}/llama-cpp-rs \
		WRKSRC=${WRKDIR}/${_CARGO_GIT_WRKDIR} do-patch

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
