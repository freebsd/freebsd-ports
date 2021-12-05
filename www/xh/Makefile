PORTNAME=	xh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Friendly and fast tool for sending HTTP requests

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ducaale

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.18 \
		alloc-no-stdlib-2.0.1 \
		alloc-stdlib-0.2.1 \
		ansi_term-0.11.0 \
		anyhow-1.0.40 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		ascii-canvas-2.0.0 \
		assert-json-diff-2.0.1 \
		assert_cmd-1.0.4 \
		assert_matches-1.5.0 \
		async-channel-1.6.1 \
		async-compression-0.3.8 \
		async-executor-1.4.1 \
		async-global-executor-2.0.2 \
		async-io-1.4.1 \
		async-lock-2.4.0 \
		async-mutex-1.4.0 \
		async-object-pool-0.1.4 \
		async-process-1.1.0 \
		async-std-1.9.0 \
		async-task-4.0.3 \
		async-trait-0.1.50 \
		atomic-waker-1.0.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base-x-0.2.8 \
		base64-0.13.0 \
		basic-cookies-0.1.4 \
		bincode-1.3.3 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		blocking-1.0.2 \
		brotli-3.3.0 \
		brotli-decompressor-2.3.1 \
		bstr-0.2.16 \
		bumpalo-3.7.0 \
		byteorder-1.4.3 \
		bytes-1.0.1 \
		cache-padded-1.1.1 \
		cc-1.0.68 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		concurrent-queue-1.2.2 \
		console-0.14.1 \
		const_fn-0.4.8 \
		constant_time_eq-0.1.5 \
		cookie-0.14.4 \
		cookie-0.15.0 \
		cookie_store-0.12.0 \
		cookie_store-0.15.0 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		crc32fast-1.2.1 \
		crossbeam-utils-0.8.5 \
		crunchy-0.2.2 \
		ctor-0.1.20 \
		curl-0.4.38 \
		curl-sys-0.4.44+curl-7.77.0 \
		diff-0.1.12 \
		difference-2.0.0 \
		dirs-1.0.5 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		discard-1.0.4 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		ena-0.14.0 \
		encode_unicode-0.3.6 \
		encoding_rs-0.8.28 \
		encoding_rs_io-0.1.7 \
		event-listener-2.5.1 \
		fastrand-1.4.1 \
		fixedbitset-0.2.0 \
		flate2-1.0.20 \
		float-cmp-0.8.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		futures-channel-0.3.15 \
		futures-core-0.3.15 \
		futures-io-0.3.15 \
		futures-lite-1.11.3 \
		futures-macro-0.3.15 \
		futures-sink-0.3.15 \
		futures-task-0.3.15 \
		futures-util-0.3.15 \
		getopts-0.2.21 \
		getrandom-0.1.16 \
		getrandom-0.2.3 \
		gloo-timers-0.2.1 \
		h2-0.3.3 \
		hashbrown-0.9.1 \
		hashbrown-0.11.2 \
		heck-0.3.2 \
		hermit-abi-0.1.18 \
		http-0.2.4 \
		http-body-0.4.2 \
		httparse-1.5.1 \
		httpdate-1.0.1 \
		httpmock-0.5.8 \
		humantime-2.1.0 \
		hyper-0.14.12 \
		hyper-rustls-0.22.1 \
		hyper-tls-0.5.0 \
		idna-0.2.3 \
		indexmap-1.6.2 \
		indicatif-0.15.0 \
		indoc-1.0.3 \
		instant-0.1.9 \
		ipnet-2.3.0 \
		isahc-1.4.0 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		js-sys-0.3.51 \
		jsonxf-1.1.1 \
		kv-log-macro-1.0.7 \
		lalrpop-0.19.5 \
		lalrpop-util-0.19.5 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		levenshtein-1.0.5 \
		libc-0.2.95 \
		libnghttp2-sys-0.1.6+1.43.0 \
		libz-sys-1.1.3 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.4 \
		log-0.4.14 \
		matches-0.1.8 \
		memchr-2.4.0 \
		mime-0.3.16 \
		mime2ext-0.1.4 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.4 \
		mio-0.7.11 \
		miow-0.3.7 \
		native-tls-0.2.7 \
		netrc-rs-0.1.2 \
		new_debug_unreachable-1.0.4 \
		normalize-line-endings-0.3.0 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		number_prefix-0.3.0 \
		once_cell-1.7.2 \
		onig-6.1.1 \
		onig_sys-69.6.0 \
		openssl-0.10.34 \
		openssl-probe-0.1.4 \
		openssl-sys-0.9.63 \
		parking-2.0.0 \
		pem-0.8.3 \
		percent-encoding-2.1.0 \
		petgraph-0.5.1 \
		phf_shared-0.8.0 \
		pico-args-0.4.1 \
		pin-project-1.0.7 \
		pin-project-internal-1.0.7 \
		pin-project-lite-0.2.6 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		plist-1.1.0 \
		polling-2.0.3 \
		ppv-lite86-0.2.10 \
		precomputed-hash-0.1.1 \
		predicates-1.0.8 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.2 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.27 \
		psl-types-2.0.7 \
		publicsuffix-1.5.6 \
		publicsuffix-2.1.0 \
		qstring-0.7.2 \
		quote-1.0.9 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.8 \
		redox_users-0.3.5 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.4 \
		reqwest_cookie_store-0.2.0 \
		ring-0.16.20 \
		rpassword-5.0.1 \
		rust-argon2-0.8.3 \
		rustc_version-0.2.3 \
		rustls-0.19.1 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		schannel-0.1.19 \
		sct-0.6.1 \
		security-framework-2.2.0 \
		security-framework-sys-2.2.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		serde_regex-1.1.0 \
		serde_urlencoded-0.7.0 \
		sha1-0.6.0 \
		shell-escape-0.1.5 \
		signal-hook-0.3.9 \
		signal-hook-registry-1.4.0 \
		siphasher-0.3.5 \
		slab-0.4.3 \
		sluice-0.5.4 \
		socket2-0.4.0 \
		spin-0.5.2 \
		standback-0.2.17 \
		stdweb-0.4.20 \
		stdweb-derive-0.5.3 \
		stdweb-internal-macros-0.2.9 \
		stdweb-internal-runtime-0.1.5 \
		string_cache-0.8.1 \
		strsim-0.8.0 \
		structopt-0.3.21 \
		structopt-derive-0.4.14 \
		syn-1.0.72 \
		syntect-4.5.0 \
		tempfile-3.2.0 \
		term-0.5.2 \
		term_size-0.3.2 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		textwrap-0.11.0 \
		thiserror-1.0.25 \
		thiserror-impl-1.0.25 \
		time-0.2.27 \
		time-macros-0.1.1 \
		time-macros-impl-0.1.2 \
		tiny-keccak-2.0.2 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		tokio-1.6.1 \
		tokio-macros-1.2.0 \
		tokio-native-tls-0.3.0 \
		tokio-rustls-0.22.0 \
		tokio-socks-0.5.1 \
		tokio-util-0.6.7 \
		tower-service-0.3.1 \
		tracing-0.1.26 \
		tracing-attributes-0.1.15 \
		tracing-core-0.1.18 \
		tracing-futures-0.2.5 \
		treeline-0.1.0 \
		try-lock-0.2.3 \
		unicase-2.6.0 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.18 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		unindent-0.1.7 \
		untrusted-0.7.1 \
		url-2.2.2 \
		value-bag-1.0.0-alpha.7 \
		vcpkg-0.2.13 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		waker-fn-1.1.0 \
		walkdir-2.3.2 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.74 \
		wasm-bindgen-backend-0.2.74 \
		wasm-bindgen-futures-0.4.24 \
		wasm-bindgen-macro-0.2.74 \
		wasm-bindgen-macro-support-0.2.74 \
		wasm-bindgen-shared-0.2.74 \
		web-sys-0.3.51 \
		webpki-0.21.4 \
		webpki-roots-0.21.1 \
		wepoll-sys-3.0.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		xml-rs-0.8.3 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES
OPTIONS_SUB=		yes

COMPLETIONS_DESC=		Install shell completions for bash, fish and zsh
COMPLETIONS_PLIST_FILES=	etc/bash_completion.d/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}
MANPAGES_PLIST_FILES=		man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
