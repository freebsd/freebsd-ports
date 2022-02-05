PORTNAME=	tealdeer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
PORTREVISION=	13
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

CARGO_CRATES=	addr2line-0.13.0 \
		adler-0.2.3 \
		aho-corasick-0.7.13 \
		android_log-sys-0.1.2 \
		ansi_term-0.12.1 \
		app_dirs2-2.3.0 \
		ascii-0.9.3 \
		assert_cmd-1.0.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.50 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		bumpalo-3.4.0 \
		byteorder-1.3.4 \
		bytes-0.5.6 \
		cc-1.0.59 \
		cesu8-1.1.0 \
		cfg-if-0.1.10 \
		combine-3.8.1 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		crc32fast-1.2.0 \
		derivative-2.1.1 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		docopt-1.1.0 \
		dtoa-0.4.6 \
		either-1.6.0 \
		encoding_rs-0.8.24 \
		env_logger-0.7.1 \
		errno-0.2.6 \
		errno-dragonfly-0.1.1 \
		error-chain-0.12.4 \
		escargot-0.5.0 \
		filetime-0.2.12 \
		flate2-1.0.17 \
		float-cmp-0.8.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-channel-0.3.5 \
		futures-core-0.3.5 \
		futures-io-0.3.5 \
		futures-sink-0.3.5 \
		futures-task-0.3.5 \
		futures-util-0.3.5 \
		gcc-0.3.55 \
		getrandom-0.1.14 \
		gimli-0.22.0 \
		h2-0.2.6 \
		hashbrown-0.8.2 \
		hermit-abi-0.1.15 \
		http-0.2.1 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		hyper-0.13.7 \
		hyper-tls-0.4.3 \
		idna-0.2.0 \
		indexmap-1.5.2 \
		iovec-0.1.4 \
		ipnet-2.3.0 \
		itoa-0.4.6 \
		jni-0.14.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.44 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.76 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.1 \
		mio-0.6.22 \
		miow-0.2.1 \
		native-tls-0.2.4 \
		ndk-0.1.0 \
		ndk-glue-0.1.0 \
		ndk-sys-0.1.0 \
		net2-0.2.34 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		num_enum-0.4.3 \
		num_enum_derive-0.4.3 \
		object-0.20.0 \
		once_cell-1.4.1 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.58 \
		pager-0.15.0 \
		percent-encoding-2.1.0 \
		pin-project-0.4.23 \
		pin-project-internal-0.4.23 \
		pin-project-lite-0.1.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.18 \
		ppv-lite86-0.2.9 \
		predicates-1.0.5 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro-crate-0.1.5 \
		proc-macro2-1.0.19 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.2 \
		reqwest-0.10.8 \
		rustc-demangle-0.1.16 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		schannel-0.1.19 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		serde-1.0.115 \
		serde_derive-1.0.115 \
		serde_json-1.0.57 \
		serde_urlencoded-0.6.1 \
		slab-0.4.2 \
		socket2-0.3.12 \
		strsim-0.9.3 \
		syn-1.0.39 \
		tar-0.4.30 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tinyvec-0.3.4 \
		tokio-0.2.22 \
		tokio-tls-0.3.1 \
		tokio-util-0.3.1 \
		toml-0.5.6 \
		tower-service-0.3.0 \
		tracing-0.1.19 \
		tracing-core-0.1.15 \
		treeline-0.1.0 \
		try-lock-0.2.3 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-xid-0.2.1 \
		unreachable-1.0.0 \
		url-2.1.1 \
		vcpkg-0.2.10 \
		version_check-0.9.2 \
		void-1.0.2 \
		wait-timeout-0.2.0 \
		walkdir-2.3.1 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.67 \
		wasm-bindgen-backend-0.2.67 \
		wasm-bindgen-futures-0.4.17 \
		wasm-bindgen-macro-0.2.67 \
		wasm-bindgen-macro-support-0.2.67 \
		wasm-bindgen-shared-0.2.67 \
		web-sys-0.3.44 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		ws2_32-sys-0.2.1 \
		xattr-0.2.2 \
		xdg-2.2.0
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
