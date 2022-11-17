PORTNAME=	xplr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.3
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Hackable, minimal, fast TUI file explorer
WWW=		https://xplr.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo desktop-file-utils gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sayanarijit

CARGO_CRATES=	aho-corasick-0.7.19 \
		android_system_properties-0.1.5 \
		ansi-to-tui-1.0.1 \
		anyhow-1.0.64 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.11.0 \
		cassowary-0.3.0 \
		cast-0.3.0 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.22 \
		clap-2.34.0 \
		core-foundation-sys-0.8.3 \
		criterion-0.3.6 \
		criterion-plot-0.4.5 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.10 \
		crossbeam-utils-0.8.11 \
		crossterm-0.23.2 \
		crossterm-0.25.0 \
		crossterm_winapi-0.9.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difflib-0.4.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		doc-comment-0.3.3 \
		either-1.8.0 \
		erased-serde-0.3.23 \
		gethostname-0.2.3 \
		getrandom-0.2.7 \
		half-1.8.2 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		humansize-1.1.1 \
		iana-time-zone-0.1.47 \
		indexmap-1.9.1 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.3 \
		js-sys-0.3.59 \
		lazy_static-1.4.0 \
		libc-0.2.132 \
		linked-hash-map-0.5.6 \
		lock_api-0.4.8 \
		log-0.4.17 \
		lua-src-544.0.1 \
		luajit-src-210.4.1+restyaa7a722 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mime-0.3.16 \
		mime_guess-2.0.4 \
		minimal-lexical-0.2.1 \
		mio-0.8.4 \
		mlua-0.8.3 \
		natord-1.0.9 \
		nom-7.1.1 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.14.0 \
		oorandom-11.1.3 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		pkg-config-0.3.25 \
		plotters-0.3.4 \
		plotters-backend-0.3.4 \
		plotters-svg-0.3.3 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		rayon-1.5.3 \
		rayon-core-1.9.3 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.6.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.27 \
		rustc-hash-1.1.0 \
		ryu-1.0.11 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.144 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.144 \
		serde_json-1.0.85 \
		serde_yaml-0.8.26 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.9.0 \
		syn-1.0.99 \
		termtree-0.2.4 \
		textwrap-0.11.0 \
		thiserror-1.0.34 \
		thiserror-impl-1.0.34 \
		time-0.1.44 \
		tinytemplate-1.2.1 \
		tui-0.18.0 \
		tui-input-0.5.1 \
		unicase-2.6.0 \
		unicode-ident-1.0.3 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.82 \
		wasm-bindgen-backend-0.2.82 \
		wasm-bindgen-macro-0.2.82 \
		wasm-bindgen-macro-support-0.2.82 \
		wasm-bindgen-shared-0.2.82 \
		web-sys-0.3.59 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1 \
		yaml-rust-0.4.5

BINARY_ALIAS=	make=gmake

PORTDOCS=	CODE_OF_CONDUCT.md README.md RELEASE.md
_EXAMPLES=	${WRKSRC}/src/init.lua
PORTEXAMPLES=	${_EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES

_ASSETS=	${WRKSRC}/assets
_ICONS=		${STAGEDIR}${PREFIX}/share/icons/hicolor

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Cargo.toml
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
.endif

.if ${ARCH} == powerpc
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Cargo.toml
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	${INSTALL_DATA} ${_ASSETS}/desktop/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

	@${MKDIR} ${_ICONS}/scalable/apps
	${INSTALL_DATA} ${_ASSETS}/icon/${PORTNAME}.svg \
		${_ICONS}/scalable/apps
.for res in 16 32 64 128
	@${MKDIR} ${_ICONS}/${res}x${res}/apps
.for icon in ico png
	${INSTALL_DATA} ${_ASSETS}/icon/${PORTNAME}${res}.${icon} \
		${_ICONS}/${res}x${res}/apps/${PORTNAME}.${icon}
.endfor
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${_EXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
