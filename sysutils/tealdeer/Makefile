# $FreeBSD$

PORTNAME=	tealdeer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	2
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

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.7.4 \
		ansi_term-0.11.0 \
		app_dirs-1.2.1 \
		arrayvec-0.4.11 \
		assert_cmd-0.10.2 \
		atty-0.2.13 \
		autocfg-0.1.5 \
		backtrace-0.3.33 \
		backtrace-sys-0.1.31 \
		base64-0.10.1 \
		bitflags-1.1.0 \
		byteorder-1.3.2 \
		bytes-0.4.12 \
		c2-chacha-0.2.2 \
		cc-1.0.38 \
		cfg-if-0.1.9 \
		cloudabi-0.0.3 \
		cookie-0.12.0 \
		cookie_store-0.7.0 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.7.2 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.6 \
		difference-2.0.0 \
		docopt-1.0.2 \
		dtoa-0.4.4 \
		either-1.5.2 \
		encoding_rs-0.8.17 \
		env_logger-0.6.2 \
		errno-0.2.4 \
		errno-dragonfly-0.1.1 \
		error-chain-0.12.1 \
		escargot-0.3.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		filetime-0.2.6 \
		flate2-1.0.9 \
		float-cmp-0.4.0 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.28 \
		futures-cpupool-0.1.8 \
		gcc-0.3.55 \
		getrandom-0.1.6 \
		h2-0.1.26 \
		http-0.1.18 \
		http-body-0.1.0 \
		httparse-1.3.4 \
		humantime-1.2.0 \
		hyper-0.12.33 \
		hyper-tls-0.3.2 \
		idna-0.1.5 \
		indexmap-1.0.2 \
		iovec-0.1.2 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.60 \
		lock_api-0.1.5 \
		log-0.4.7 \
		matches-0.1.8 \
		memchr-2.2.1 \
		memoffset-0.5.1 \
		mime-0.3.13 \
		mime_guess-2.0.0-alpha.6 \
		miniz-sys-0.1.12 \
		miniz_oxide-0.2.3 \
		miniz_oxide_c_api-0.2.2 \
		mio-0.6.19 \
		miow-0.2.1 \
		native-tls-0.2.3 \
		net2-0.2.33 \
		nodrop-0.1.13 \
		normalize-line-endings-0.2.2 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		ole32-sys-0.2.0 \
		openssl-0.10.24 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.48 \
		owning_ref-0.4.0 \
		pager-0.15.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		percent-encoding-1.0.1 \
		phf-0.7.24 \
		phf_codegen-0.7.24 \
		phf_generator-0.7.24 \
		phf_shared-0.7.24 \
		pkg-config-0.3.15 \
		ppv-lite86-0.2.5 \
		predicates-1.0.1 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro2-0.4.30 \
		publicsuffix-1.5.2 \
		quick-error-1.2.2 \
		quote-0.6.13 \
		rand-0.4.6 \
		rand-0.6.5 \
		rand-0.7.0 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_core-0.5.0 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		regex-1.2.0 \
		regex-syntax-0.6.10 \
		remove_dir_all-0.5.2 \
		reqwest-0.9.19 \
		rustc-demangle-0.1.15 \
		rustc_version-0.2.3 \
		ryu-1.0.0 \
		same-file-1.0.5 \
		schannel-0.1.15 \
		scopeguard-0.3.3 \
		scopeguard-1.0.0 \
		security-framework-0.3.1 \
		security-framework-sys-0.3.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.97 \
		serde_derive-1.0.97 \
		serde_json-1.0.40 \
		serde_urlencoded-0.5.5 \
		shell32-sys-0.1.2 \
		siphasher-0.2.3 \
		slab-0.4.2 \
		smallvec-0.6.10 \
		spin-0.5.0 \
		stable_deref_trait-1.1.1 \
		string-0.2.1 \
		strsim-0.7.0 \
		syn-0.15.42 \
		synstructure-0.10.2 \
		tar-0.4.26 \
		tempdir-0.3.7 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		thread_local-0.3.6 \
		time-0.1.42 \
		tokio-0.1.22 \
		tokio-buf-0.1.1 \
		tokio-current-thread-0.1.6 \
		tokio-executor-0.1.8 \
		tokio-io-0.1.12 \
		tokio-reactor-0.1.9 \
		tokio-sync-0.1.6 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.15 \
		tokio-timer-0.2.11 \
		toml-0.5.1 \
		treeline-0.1.0 \
		try-lock-0.2.2 \
		try_from-0.3.2 \
		ucd-util-0.1.5 \
		unicase-1.4.2 \
		unicase-2.4.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-xid-0.1.0 \
		url-1.7.2 \
		utf8-ranges-1.0.3 \
		utime-0.2.1 \
		uuid-0.7.4 \
		vcpkg-0.2.7 \
		version_check-0.1.5 \
		walkdir-2.2.9 \
		want-0.2.0 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		winreg-0.6.1 \
		ws2_32-sys-0.2.1 \
		xattr-0.2.2 \
		xdg-2.2.0
CARGO_BUILD_ARGS=	--no-default-features
CARGO_INSTALL_ARGS=	--no-default-features
CARGO_TEST_ARGS=	--no-default-features

PLIST_FILES=	bin/tldr \
		etc/bash_completion.d/tldr.bash \
		share/fish/completions/tldr.fish
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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
