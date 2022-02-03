PORTNAME=	tealdeer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fast tldr client written in Rust

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	dbrgn

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		app_dirs2-2.3.3 \
		assert_cmd-2.0.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.8.0 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.72 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		clap-3.0.0-rc.11 \
		clap_derive-3.0.0-rc.11 \
		combine-4.6.2 \
		core-foundation-0.9.2 \
		core-foundation-sys-0.8.3 \
		crc32fast-1.3.0 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		difflib-0.4.0 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		encoding_rs-0.8.30 \
		env_logger-0.9.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		escargot-0.5.7 \
		filetime-0.2.15 \
		flate2-1.0.22 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		futures-channel-0.3.19 \
		futures-core-0.3.19 \
		futures-io-0.3.19 \
		futures-sink-0.3.19 \
		futures-task-0.3.19 \
		futures-util-0.3.19 \
		getrandom-0.2.3 \
		h2-0.3.9 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		http-0.2.6 \
		http-body-0.4.4 \
		httparse-1.5.1 \
		httpdate-1.0.2 \
		humantime-2.1.0 \
		hyper-0.14.16 \
		hyper-rustls-0.23.0 \
		ident_case-1.0.1 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		ipnet-2.3.1 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		jni-0.19.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.55 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		mime-0.3.16 \
		miniz_oxide-0.4.4 \
		mio-0.7.14 \
		miow-0.3.7 \
		ndk-0.4.0 \
		ndk-glue-0.4.0 \
		ndk-macro-0.2.0 \
		ndk-sys-0.2.2 \
		normalize-line-endings-0.3.0 \
		ntapi-0.3.6 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		num_enum-0.5.6 \
		num_enum_derive-0.5.6 \
		once_cell-1.9.0 \
		openssl-probe-0.1.4 \
		os_str_bytes-6.0.0 \
		pager-0.16.0 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.16 \
		predicates-2.1.0 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.4 \
		proc-macro-crate-0.1.5 \
		proc-macro-crate-1.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.14 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.8 \
		ring-0.16.20 \
		rustls-0.20.2 \
		rustls-native-certs-0.6.1 \
		rustls-pemfile-0.2.1 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		schannel-0.1.19 \
		sct-0.7.0 \
		security-framework-2.4.2 \
		security-framework-sys-2.4.2 \
		serde-1.0.132 \
		serde_derive-1.0.132 \
		serde_json-1.0.73 \
		serde_urlencoded-0.7.0 \
		slab-0.4.5 \
		socket2-0.4.2 \
		spin-0.5.2 \
		strsim-0.9.3 \
		strsim-0.10.0 \
		syn-1.0.84 \
		tempfile-3.2.0 \
		termcolor-1.1.2 \
		termtree-0.2.3 \
		textwrap-0.14.2 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.15.0 \
		tokio-rustls-0.23.2 \
		tokio-util-0.6.9 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.29 \
		tracing-core-0.1.21 \
		try-lock-0.2.3 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		url-2.2.2 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		want-0.3.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.78 \
		wasm-bindgen-backend-0.2.78 \
		wasm-bindgen-futures-0.4.28 \
		wasm-bindgen-macro-0.2.78 \
		wasm-bindgen-macro-support-0.2.78 \
		wasm-bindgen-shared-0.2.78 \
		web-sys-0.3.55 \
		webpki-0.22.0 \
		webpki-roots-0.22.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		xdg-2.4.0 \
		zip-0.5.13
CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/tldr \
		etc/bash_completion.d/tldr.bash \
		share/fish/completions/tldr.fish \
		share/zsh/site-functions/_tldr
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS LOGGER

LOGGER_DESC=	Debug build with logging enabled
LOGGER_VARS=	CARGO_FEATURES+=logging

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tldr
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

	${INSTALL_DATA} ${WRKSRC}/bash_${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/tldr.bash
	${INSTALL_DATA} ${WRKSRC}/fish_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/fish/completions/tldr.fish
	${INSTALL_DATA} ${WRKSRC}/zsh_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tldr

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
