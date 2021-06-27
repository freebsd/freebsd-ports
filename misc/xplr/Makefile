PORTNAME=	xplr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.3
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Hackable, minimal, fast TUI file explorer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo desktop-file-utils gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sayanarijit

CARGO_CRATES=	ansi-to-tui-0.3.0 \
		anyhow-1.0.40 \
		assert_cmd-1.0.5 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.15 \
		bumpalo-3.6.1 \
		byteorder-1.4.3 \
		cassowary-0.3.0 \
		cast-0.2.3 \
		cc-1.0.67 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		criterion-0.3.4 \
		criterion-plot-0.4.3 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.3 \
		crossbeam-utils-0.8.3 \
		crossterm-0.19.0 \
		crossterm_winapi-0.7.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difference-2.0.0 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		doc-comment-0.3.3 \
		dtoa-0.4.8 \
		either-1.6.1 \
		erased-serde-0.3.13 \
		getrandom-0.2.3 \
		half-1.7.1 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.18 \
		humansize-1.1.1 \
		indexmap-1.6.2 \
		instant-0.1.9 \
		itertools-0.9.0 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		js-sys-0.3.50 \
		lazy_static-1.4.0 \
		libc-0.2.95 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.2 \
		log-0.4.14 \
		lua-src-543.0.0 \
		luajit-src-210.1.3+restyfe08842 \
		memchr-2.3.4 \
		memoffset-0.6.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		mio-0.7.11 \
		miow-0.3.7 \
		mlua-0.5.4 \
		natord-1.0.9 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		oorandom-11.1.3 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		pkg-config-0.3.19 \
		plotters-0.3.0 \
		plotters-backend-0.3.0 \
		plotters-svg-0.3.0 \
		predicates-1.0.8 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.2 \
		proc-macro2-1.0.26 \
		quote-1.0.9 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.2.5 \
		redox_termios-0.1.2 \
		redox_users-0.4.0 \
		regex-1.4.5 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.23 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.126 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		serde_yaml-0.8.17 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.3.0 \
		smallvec-1.6.1 \
		syn-1.0.68 \
		termion-1.5.6 \
		textwrap-0.11.0 \
		time-0.1.44 \
		tinytemplate-1.2.1 \
		treeline-0.1.0 \
		tui-0.15.0 \
		unicase-2.6.0 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.73 \
		wasm-bindgen-backend-0.2.73 \
		wasm-bindgen-macro-0.2.73 \
		wasm-bindgen-macro-support-0.2.73 \
		wasm-bindgen-shared-0.2.73 \
		web-sys-0.3.50 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

PORTDOCS=	CODE_OF_CONDUCT.md README.md RELEASE.md
_EXAMPLES=	${WRKSRC}/src/init.lua
PORTEXAMPLES=	${_EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES

_ASSETS=	${WRKSRC}/assets
_ICONS=		${STAGEDIR}${PREFIX}/share/icons/hicolor

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
