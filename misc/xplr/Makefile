PORTNAME=	xplr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.9
CATEGORIES=	misc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Hackable, minimal, fast TUI file explorer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	sayanarijit

CARGO_CRATES=	anyhow-1.0.40 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base-x-0.2.8 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.15 \
		bumpalo-3.6.1 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		cassowary-0.3.0 \
		cast-0.2.3 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		colored-2.0.0 \
		const_fn-0.4.6 \
		constant_time_eq-0.1.5 \
		criterion-0.3.4 \
		criterion-plot-0.4.3 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.3 \
		crossbeam-utils-0.8.3 \
		crossterm-0.18.2 \
		crossterm_winapi-0.6.2 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		derive-new-0.5.9 \
		derive_builder-0.9.0 \
		derive_builder_core-0.9.0 \
		digest-0.8.1 \
		dirs-3.0.1 \
		dirs-sys-0.3.5 \
		discard-1.0.4 \
		dtoa-0.4.8 \
		either-1.6.1 \
		fake-simd-0.1.2 \
		filetime-0.2.14 \
		fnv-1.0.7 \
		fsevent-0.4.0 \
		fsevent-sys-2.0.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		generic-array-0.12.4 \
		getrandom-0.1.16 \
		half-1.7.1 \
		handlebars-3.5.4 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.18 \
		humansize-1.1.0 \
		ident_case-1.0.1 \
		indexmap-1.6.2 \
		inotify-0.7.1 \
		inotify-sys-0.1.5 \
		instant-0.1.9 \
		iovec-0.1.4 \
		itertools-0.9.0 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		js-sys-0.3.50 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.92 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.2 \
		log-0.4.14 \
		maplit-1.0.2 \
		memchr-2.3.4 \
		memoffset-0.6.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		mio-0.6.23 \
		mio-0.7.11 \
		mio-extras-2.0.6 \
		miow-0.2.2 \
		miow-0.3.7 \
		natord-1.0.9 \
		net2-0.2.37 \
		notify-4.0.15 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		numtoa-0.1.0 \
		oorandom-11.1.3 \
		opaque-debug-0.2.3 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		plotters-0.3.0 \
		plotters-backend-0.3.0 \
		plotters-svg-0.3.0 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.26 \
		quick-error-2.0.0 \
		quote-1.0.9 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.5 \
		redox_termios-0.1.2 \
		redox_users-0.3.5 \
		regex-1.4.5 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.23 \
		rspec-1.0.0 \
		rust-argon2-0.8.3 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.125 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.125 \
		serde_json-1.0.64 \
		serde_yaml-0.8.17 \
		sha-1-0.8.2 \
		sha1-0.6.0 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.3.0 \
		slab-0.4.2 \
		smallvec-1.6.1 \
		standback-0.2.17 \
		stdweb-0.4.20 \
		stdweb-derive-0.5.3 \
		stdweb-internal-macros-0.2.9 \
		stdweb-internal-runtime-0.1.5 \
		strsim-0.9.3 \
		syn-1.0.68 \
		termion-1.5.6 \
		textwrap-0.11.0 \
		time-0.1.44 \
		time-0.2.26 \
		time-macros-0.1.1 \
		time-macros-impl-0.1.1 \
		tinytemplate-1.2.1 \
		tui-0.14.0 \
		typenum-1.13.0 \
		ucd-trie-0.1.3 \
		unicase-2.6.0 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		version_check-0.9.3 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.73 \
		wasm-bindgen-backend-0.2.73 \
		wasm-bindgen-macro-0.2.73 \
		wasm-bindgen-macro-support-0.2.73 \
		wasm-bindgen-shared-0.2.73 \
		web-sys-0.3.50 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop
PORTDOCS=	CODE_OF_CONDUCT.md README.md RELEASE.md
_EXAMPLES=	${WRKSRC}/src/config.yml
PORTEXAMPLES=	${_EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${_EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
