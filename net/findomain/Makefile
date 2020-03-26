# $FreeBSD$

PORTNAME=	findomain
DISTVERSION=	1.4.3
CATEGORIES=	net security

MAINTAINER=	vulcan@wired.sh
COMMENT=	Cross-platform subdomain enumerator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Edu4rdSHL

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.26 \
		async-trait-0.1.24 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.0 \
		backtrace-0.3.44 \
		backtrace-sys-0.1.32 \
		base64-0.10.1 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bumpalo-3.1.2 \
		byte-tools-0.3.1 \
		byteorder-1.3.2 \
		bytes-0.5.3 \
		c2-chacha-0.2.3 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crossbeam-deque-0.7.2 \
		crossbeam-epoch-0.8.0 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.0 \
		crypto-mac-0.7.0 \
		digest-0.8.1 \
		dtoa-0.4.4 \
		either-1.5.3 \
		encoding_rs-0.8.22 \
		enum-as-inner-0.3.0 \
		failure-0.1.7 \
		failure_derive-0.1.7 \
		fake-simd-0.1.2 \
		fallible-iterator-0.2.0 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.3.4 \
		futures-channel-0.3.4 \
		futures-core-0.3.4 \
		futures-executor-0.3.4 \
		futures-io-0.3.4 \
		futures-macro-0.3.4 \
		futures-sink-0.3.4 \
		futures-task-0.3.4 \
		futures-util-0.3.4 \
		generic-array-0.12.3 \
		generic-array-0.13.2 \
		getrandom-0.1.14 \
		h2-0.2.2 \
		heck-0.3.1 \
		hermit-abi-0.1.6 \
		hmac-0.7.1 \
		hostname-0.1.5 \
		http-0.2.0 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		hyper-0.13.4 \
		hyper-tls-0.4.1 \
		idna-0.2.0 \
		indexmap-1.3.1 \
		iovec-0.1.4 \
		ipconfig-0.2.1 \
		itoa-0.4.4 \
		js-sys-0.3.35 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		linked-hash-map-0.5.2 \
		lock_api-0.3.3 \
		log-0.4.8 \
		lru-cache-0.1.2 \
		matches-0.1.8 \
		md5-0.7.0 \
		memchr-2.3.0 \
		memoffset-0.5.3 \
		mime-0.3.16 \
		mime_guess-2.0.1 \
		mio-0.6.21 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		native-tls-0.2.3 \
		net2-0.2.33 \
		nom-4.2.3 \
		num_cpus-1.12.0 \
		opaque-debug-0.2.3 \
		openssl-0.10.28 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.54 \
		parking_lot-0.10.0 \
		parking_lot_core-0.7.0 \
		percent-encoding-2.1.0 \
		phf-0.8.0 \
		phf_shared-0.8.0 \
		pin-project-0.4.7 \
		pin-project-internal-0.4.7 \
		pin-project-lite-0.1.4 \
		pin-utils-0.1.0-alpha.4 \
		pkg-config-0.3.17 \
		postgres-0.17.2 \
		postgres-protocol-0.5.0 \
		postgres-types-0.1.1 \
		ppv-lite86-0.2.6 \
		proc-macro-hack-0.5.11 \
		proc-macro-nested-0.1.3 \
		proc-macro2-1.0.8 \
		quick-error-1.2.3 \
		quote-1.0.2 \
		rand-0.7.3 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		redox_syscall-0.1.56 \
		remove_dir_all-0.5.2 \
		reqwest-0.10.4 \
		resolv-conf-0.6.2 \
		ring-0.16.9 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		rustls-0.16.0 \
		ryu-1.0.2 \
		schannel-0.1.16 \
		scopeguard-1.0.0 \
		sct-0.6.0 \
		security-framework-0.3.4 \
		security-framework-sys-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.105 \
		serde_derive-1.0.105 \
		serde_json-1.0.44 \
		serde_urlencoded-0.6.1 \
		sha2-0.8.1 \
		siphasher-0.3.1 \
		slab-0.4.2 \
		smallvec-1.2.0 \
		socket2-0.3.11 \
		sourcefile-0.1.4 \
		spin-0.5.2 \
		stringprep-0.1.2 \
		strsim-0.8.0 \
		subtle-1.0.0 \
		syn-1.0.13 \
		synstructure-0.12.3 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.11 \
		thiserror-impl-1.0.11 \
		time-0.1.42 \
		tokio-0.2.11 \
		tokio-postgres-0.5.3 \
		tokio-rustls-0.12.2 \
		tokio-tls-0.3.0 \
		tokio-util-0.2.0 \
		tokio-util-0.3.1 \
		tower-service-0.3.0 \
		trust-dns-proto-0.19.3 \
		trust-dns-resolver-0.19.3 \
		trust-dns-rustls-0.19.3 \
		try-lock-0.2.2 \
		typenum-1.11.2 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.11 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		untrusted-0.7.0 \
		url-2.1.1 \
		vcpkg-0.2.8 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		version_check-0.9.1 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.58 \
		wasm-bindgen-backend-0.2.58 \
		wasm-bindgen-futures-0.4.8 \
		wasm-bindgen-macro-0.2.58 \
		wasm-bindgen-macro-support-0.2.58 \
		wasm-bindgen-shared-0.2.58 \
		wasm-bindgen-webidl-0.2.58 \
		web-sys-0.3.35 \
		webpki-0.21.0 \
		webpki-roots-0.19.0 \
		weedle-0.10.0 \
		widestring-0.4.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		winutil-0.1.1 \
		ws2_32-sys-0.2.1 \
		yaml-rust-0.3.5

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	DOCS PGSQL
PGSQL_DESC=	Subdomains monitoring support

PGSQL_USES=	pgsql
PGSQL_VARS=	WANT_PGSQL=server

DOCS=		docs/create_telegram_webhook.md README.md

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
