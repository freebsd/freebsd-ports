PORTNAME=	warp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2026.06.03.09.49.stable_00
CATEGORIES=	misc devel x11

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Open agentic development environment born from the terminal
WWW=		https://warp.dev/

LICENSE=		AGPLv3 MIT
LICENSE_COMB=		dual
LICENSE_FILE_AGPLv3=	${WRKSRC}/LICENSE-AGPL
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	brotli:archivers/brotli \
		git:devel/git \
		cargo-about:devel/cargo-about \
		protoc:devel/protobuf \
		curl:ftp/curl \
		bash:shells/bash \
		jq:textproc/jq
LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libasound.so:audio/alsa-lib \
		libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma \
		libwayland-client.so:graphics/wayland \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libxkbcommon.so:x11/libxkbcommon \
		libfontconfig.so:x11-fonts/fontconfig
TEST_DEPENDS=	cargo-nextest:devel/nextest

USES=		cargo cmake:indirect desktop-file-utils gettext-runtime gl \
		pkgconfig python shebangfix ssl xorg

USE_XORG=	x11 xcb xi xcursor
USE_GL=		egl

USE_GITHUB=	yes
GH_ACCOUNT=	warpdotdev

SHEBANG_FILES=	script/prepare_bundled_resources
SHEBANG_REGEX=	./resources/bundled/.*/.*.py

CARGO_FEATURES=		release_bundle \
			gui \
			nld_classifier_v2 \
			nld_heuristic_v2
CARGO_BUILD_ARGS=	--package warp \
			--bin warp-oss

BINARY_ALIAS=	python=${PYTHON_CMD}

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md WARP.md

OPTIONS_DEFINE=	COMPLETIONS DOCS
OPTIONS_DEFAULT=COMPLETIONS
OPTIONS_SUB=	yes

COMPLETIONS_DESC=	Build and/or install shell completions

WARP_PREFIX=	${PREFIX}/${PORTNAME}
BINNAME=	${PORTNAME}-terminal-oss

do-install:
	@${MKDIR} ${STAGEDIR}${WARP_PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/warp-oss \
		${STAGEDIR}${WARP_PREFIX}/bin/${BINNAME}
	${RLN} ${STAGEDIR}${WARP_PREFIX}/bin/${BINNAME} \
		${STAGEDIR}${PREFIX}/bin/${BINNAME}
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} \
		./script/prepare_bundled_resources \
		${STAGEDIR}${WARP_PREFIX}/resources oss release
	${INSTALL_DATA} ${WRKSRC}/app/channels/oss/dev.warp.WarpOss.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/app/channels/oss/icon/no-padding/512x512.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/dev.warp.WarpOss.png

do-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}/${PREFIX}/bin/${BINNAME} completions bash > \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${BINNAME}
	${STAGEDIR}/${PREFIX}/bin/${BINNAME} completions fish > \
		${STAGEDIR}${PREFIX}/share/fish/completions/${BINNAME}.fish
	${STAGEDIR}/${PREFIX}/bin/${BINNAME} completions zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${BINNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${TEST_ENV} \
		${CARGO} nextest run \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--no-fail-fast \
		--workspace \
		--exclude command-signatures-v2
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${TEST_ENV} \
		${CARGO} nextest run \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--package warp_completer \
		--features v2

.include <bsd.port.mk>
