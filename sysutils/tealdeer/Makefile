# $FreeBSD$

PORTNAME=	tealdeer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Fast tldr client written in Rust

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	dbrgn

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.9 \
		ansi_term-0.12.1 \
		anyhow-1.0.26 \
		app_dirs-1.2.1 \
		assert_cmd-0.10.2 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		bumpalo-3.2.0 \
		bytes-0.5.4 \
		c2-chacha-0.2.3 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crc32fast-1.2.0 \
		difference-2.0.0 \
		docopt-1.1.0 \
		dtoa-0.4.5 \
		encoding_rs-0.8.22 \
		env_logger-0.7.1 \
		errno-0.2.4 \
		errno-dragonfly-0.1.1 \
		escargot-0.3.1 \
		filetime-0.2.8 \
		flate2-1.0.13 \
		float-cmp-0.6.0 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-channel-0.3.4 \
		futures-core-0.3.4 \
		futures-io-0.3.4 \
		futures-sink-0.3.4 \
		futures-task-0.3.4 \
		futures-util-0.3.4 \
		gcc-0.3.55 \
		getrandom-0.1.14 \
		h2-0.2.1 \
		heck-0.3.1 \
		hermit-abi-0.1.8 \
		http-0.2.0 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		hyper-0.13.2 \
		hyper-tls-0.4.1 \
		idna-0.2.0 \
		indexmap-1.3.2 \
		iovec-0.1.4 \
		itoa-0.4.5 \
		js-sys-0.3.35 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.67 \
		log-0.4.8 \
		matches-0.1.8 \
		memchr-2.3.3 \
		mime-0.3.16 \
		mime_guess-2.0.1 \
		miniz_oxide-0.3.6 \
		mio-0.6.21 \
		miow-0.2.1 \
		native-tls-0.2.3 \
		net2-0.2.33 \
		nom-4.2.3 \
		normalize-line-endings-0.2.2 \
		num-traits-0.2.11 \
		num_cpus-1.12.0 \
		ole32-sys-0.2.0 \
		openssl-0.10.28 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.54 \
		pager-0.15.0 \
		percent-encoding-2.1.0 \
		pin-project-0.4.8 \
		pin-project-internal-0.4.8 \
		pin-project-lite-0.1.4 \
		pin-utils-0.1.0-alpha.4 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		predicates-1.0.3 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro2-1.0.9 \
		quick-error-1.2.3 \
		quote-1.0.2 \
		rand-0.4.6 \
		rand-0.7.3 \
		rand_chacha-0.2.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		regex-1.3.4 \
		regex-syntax-0.6.14 \
		remove_dir_all-0.5.2 \
		reqwest-0.10.3 \
		ryu-1.0.2 \
		same-file-1.0.6 \
		schannel-0.1.17 \
		security-framework-0.3.4 \
		security-framework-sys-0.3.3 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.48 \
		serde_urlencoded-0.6.1 \
		shell32-sys-0.1.2 \
		slab-0.4.2 \
		smallvec-1.2.0 \
		sourcefile-0.1.4 \
		strsim-0.9.3 \
		syn-1.0.16 \
		tar-0.4.26 \
		tempdir-0.3.7 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		thread_local-1.0.1 \
		time-0.1.42 \
		tokio-0.2.12 \
		tokio-tls-0.3.0 \
		tokio-util-0.2.0 \
		toml-0.5.6 \
		tower-service-0.3.0 \
		treeline-0.1.0 \
		try-lock-0.2.2 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.12 \
		unicode-segmentation-1.6.0 \
		unicode-xid-0.2.0 \
		url-2.1.1 \
		utime-0.2.1 \
		vcpkg-0.2.8 \
		version_check-0.1.5 \
		version_check-0.9.1 \
		walkdir-2.3.1 \
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
		weedle-0.10.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		ws2_32-sys-0.2.1 \
		xattr-0.2.2 \
		xdg-2.2.0
CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/tldr \
		etc/bash_completion.d/tldr.bash \
		share/fish/completions/tldr.fish \
		share/zsh/site_functions/_tldr
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS LOGGER

LOGGER_DESC=	Debug build with logging enabled
LOGGER_VARS=	CARGO_FEATURES+=logging

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tldr
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash_${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/tldr.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/fish_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/fish/completions/tldr.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site_functions
	${INSTALL_DATA} ${WRKSRC}/zsh_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions/_tldr

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
