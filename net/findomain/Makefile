PORTNAME=	findomain
DISTVERSION=	5.0.0
PORTREVISION=	4
CATEGORIES=	net security

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Cross-platform subdomain enumerator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Findomain

CARGO_CRATES=	addr2line-0.16.0 \
		adler-1.0.2 \
		aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		arrayvec-0.5.2 \
		async-compression-0.3.8 \
		async-trait-0.1.51 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.1 \
		backtrace-0.3.61 \
		base64-0.9.3 \
		base64-0.10.1 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		block-buffer-0.9.0 \
		bumpalo-3.7.0 \
		byteorder-1.4.3 \
		bytes-1.0.1 \
		cc-1.0.69 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		config-0.11.0 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		cpufeatures-0.1.5 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		crypto-mac-0.10.1 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		data-encoding-2.3.2 \
		derive_builder-0.8.1 \
		derive_builder_core-0.8.1 \
		digest-0.9.0 \
		either-1.6.1 \
		encoding_rs-0.8.28 \
		enum-as-inner-0.3.3 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		fallible-iterator-0.2.0 \
		flate2-1.0.20 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		fuchsia-cprng-0.1.1 \
		futures-0.3.16 \
		futures-channel-0.3.16 \
		futures-core-0.3.16 \
		futures-executor-0.3.16 \
		futures-io-0.3.16 \
		futures-macro-0.3.16 \
		futures-sink-0.3.16 \
		futures-task-0.3.16 \
		futures-util-0.3.16 \
		generic-array-0.14.4 \
		getrandom-0.1.16 \
		getrandom-0.2.3 \
		gimli-0.25.0 \
		h2-0.3.3 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hmac-0.10.1 \
		hostname-0.3.1 \
		http-0.2.4 \
		http-body-0.4.3 \
		httparse-1.4.1 \
		httpdate-1.0.1 \
		hyper-0.10.16 \
		hyper-0.14.11 \
		hyper-tls-0.5.0 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		instant-0.1.10 \
		ipconfig-0.2.2 \
		ipnet-2.3.1 \
		itoa-0.4.7 \
		js-sys-0.3.52 \
		language-tags-0.2.2 \
		lazy_static-1.4.0 \
		lexical-core-0.7.6 \
		libc-0.2.98 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.4 \
		log-0.3.9 \
		log-0.4.14 \
		lru-cache-0.1.2 \
		match_cfg-0.1.0 \
		matches-0.1.8 \
		md-5-0.9.1 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		mime-0.2.6 \
		mime-0.3.16 \
		miniz_oxide-0.4.4 \
		mio-0.7.13 \
		miow-0.3.7 \
		native-tls-0.2.7 \
		nom-5.1.2 \
		ntapi-0.3.6 \
		num-traits-0.1.43 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		object-0.26.0 \
		once_cell-1.8.0 \
		opaque-debug-0.3.0 \
		openssl-0.10.35 \
		openssl-probe-0.1.4 \
		openssl-sys-0.9.65 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		percent-encoding-1.0.1 \
		percent-encoding-2.1.0 \
		phf-0.8.0 \
		phf_shared-0.8.0 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		postgres-0.19.1 \
		postgres-protocol-0.6.1 \
		postgres-types-0.2.1 \
		ppv-lite86-0.2.10 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.28 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		rand-0.6.5 \
		rand-0.7.3 \
		rand-0.8.4 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_core-0.6.3 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_hc-0.3.1 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		rdrand-0.4.0 \
		redox_syscall-0.2.10 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.4 \
		resolv-conf-0.7.0 \
		rust-ini-0.13.0 \
		rustc-demangle-0.1.20 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		schannel-0.1.19 \
		scopeguard-1.1.0 \
		security-framework-2.3.1 \
		security-framework-sys-2.3.0 \
		serde-0.8.23 \
		serde-1.0.127 \
		serde-hjson-0.9.1 \
		serde_derive-1.0.127 \
		serde_json-1.0.66 \
		serde_urlencoded-0.7.0 \
		sha1-0.6.0 \
		sha2-0.9.5 \
		siphasher-0.3.6 \
		slab-0.4.4 \
		smallvec-1.6.1 \
		socket2-0.3.19 \
		socket2-0.4.1 \
		static_assertions-1.1.0 \
		stringprep-0.1.2 \
		strsim-0.8.0 \
		strsim-0.9.3 \
		subtle-2.4.1 \
		syn-1.0.74 \
		synstructure-0.12.5 \
		tempfile-3.2.0 \
		textwrap-0.11.0 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		time-0.1.43 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.9.0 \
		tokio-native-tls-0.3.0 \
		tokio-postgres-0.7.2 \
		tokio-util-0.6.7 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.26 \
		tracing-core-0.1.18 \
		traitobject-0.1.0 \
		try-lock-0.2.3 \
		typeable-0.1.2 \
		typenum-1.13.0 \
		unicase-1.4.2 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		url-1.7.2 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.1.5 \
		version_check-0.9.3 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.75 \
		wasm-bindgen-backend-0.2.75 \
		wasm-bindgen-futures-0.4.25 \
		wasm-bindgen-macro-0.2.75 \
		wasm-bindgen-macro-support-0.2.75 \
		wasm-bindgen-shared-0.2.75 \
		web-sys-0.3.52 \
		websocket-0.23.0 \
		which-3.1.1 \
		widestring-0.4.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		winreg-0.7.0 \
		yaml-rust-0.3.5 \
		yaml-rust-0.4.5 \
		trust-dns-proto,trust-dns-resolver@git+https://github.com/Edu4rdSHL/trust-dns?branch=main\#451a00fbe3c0972adb4cdbd9d2e2f2a39a44da0e \
		headless_chrome@git+https://github.com/Edu4rdSHL/rust-headless-chrome\#54ae12d9d33ed41f9f4b60b489e706d501d4f58a

WRKSRC=		${WRKDIR}/Findomain-${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
_DOCS=		docs/create_telegram_webhook.md README.md
PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=	DOCS PGSQL SCREENSHOT

PGSQL_DESC=		Enable subdomain monitoring support
SCREENSHOT_DESC=	Enable website screenshot support (uses headless chrome)

PGSQL_USES=	pgsql
PGSQL_VARS=	WANT_PGSQL=server

SCREENSHOT_RUN_DEPENDS=	chrome:www/chromium

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${_DOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
