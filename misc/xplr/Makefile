PORTNAME=	xplr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.3
CATEGORIES=	misc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Hackable, minimal, fast TUI file explorer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo desktop-file-utils gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sayanarijit

CARGO_CRATES=	ansi-to-tui-0.4.1 \
		anyhow-1.0.55 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.9.1 \
		cassowary-0.3.0 \
		cast-0.2.7 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.34.0 \
		criterion-0.3.5 \
		criterion-plot-0.4.4 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.7 \
		crossbeam-utils-0.8.7 \
		crossterm-0.20.0 \
		crossterm-0.22.1 \
		crossterm_winapi-0.8.0 \
		crossterm_winapi-0.9.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difflib-0.4.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		erased-serde-0.3.18 \
		getrandom-0.2.5 \
		half-1.8.2 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		humansize-1.1.1 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		lazy_static-1.4.0 \
		libc-0.2.119 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.6 \
		log-0.4.14 \
		lua-src-544.0.0 \
		luajit-src-210.3.2+resty1085a4d \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		mime-0.3.16 \
		mime_guess-2.0.4 \
		mio-0.7.14 \
		miow-0.3.7 \
		mlua-0.7.3 \
		natord-1.0.9 \
		ntapi-0.3.7 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		oorandom-11.1.3 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		pkg-config-0.3.24 \
		plotters-0.3.1 \
		plotters-backend-0.3.2 \
		plotters-svg-0.3.1 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rustc-hash-1.1.0 \
		rustc_version-0.4.0 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-1.0.6 \
		serde-1.0.136 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		serde_yaml-0.8.23 \
		signal-hook-0.3.13 \
		signal-hook-mio-0.2.1 \
		signal-hook-registry-1.4.0 \
		smallvec-1.8.0 \
		syn-1.0.86 \
		termtree-0.2.4 \
		textwrap-0.11.0 \
		time-0.1.43 \
		tinytemplate-1.2.1 \
		tui-0.16.0 \
		tui-input-0.1.2 \
		unicase-2.6.0 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
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
