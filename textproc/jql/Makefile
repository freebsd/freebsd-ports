PORTNAME=	jql
DISTVERSIONPREFIX=	jql-v
DISTVERSION=	8.0.0
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON Query Language CLI tool built with Rust
WWW=		https://github.com/yamafaktory/jql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	yamafaktory

CARGO_CRATES=	addr2line-0.24.1 \
		adler2-2.0.0 \
		aho-corasick-1.1.3 \
		anes-0.1.6 \
		anstream-0.6.15 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.5 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		anyhow-1.0.91 \
		autocfg-1.3.0 \
		backtrace-0.3.74 \
		bumpalo-3.16.0 \
		bytes-1.7.2 \
		cast-0.3.0 \
		cc-1.1.21 \
		cfg-if-1.0.0 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		clap-4.5.20 \
		clap_builder-4.5.20 \
		clap_derive-4.5.18 \
		clap_lex-0.7.2 \
		colorchoice-1.0.2 \
		colored_json-5.0.0 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		crunchy-0.2.2 \
		either-1.13.0 \
		equivalent-1.0.1 \
		gimli-0.31.0 \
		half-2.4.1 \
		hashbrown-0.15.0 \
		heck-0.5.0 \
		hermit-abi-0.4.0 \
		indexmap-2.6.0 \
		is-terminal-0.4.13 \
		is_terminal_polyfill-1.70.1 \
		itertools-0.10.5 \
		itoa-1.0.11 \
		js-sys-0.3.70 \
		libc-0.2.158 \
		log-0.4.22 \
		memchr-2.7.4 \
		miniz_oxide-0.8.0 \
		num-traits-0.2.19 \
		object-0.36.4 \
		once_cell-1.19.0 \
		oorandom-11.1.4 \
		pin-project-lite-0.2.14 \
		plotters-0.3.7 \
		plotters-backend-0.3.7 \
		plotters-svg-0.3.7 \
		proc-macro2-1.0.86 \
		psm-0.1.23 \
		quote-1.0.37 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		regex-1.10.6 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		rustc-demangle-0.1.24 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		serde-1.0.213 \
		serde_derive-1.0.213 \
		serde_json-1.0.132 \
		serde_stacker-0.1.11 \
		shlex-1.3.0 \
		stacker-0.1.17 \
		strsim-0.11.1 \
		syn-2.0.85 \
		thiserror-1.0.65 \
		thiserror-impl-1.0.65 \
		tinytemplate-1.2.1 \
		tokio-1.41.0 \
		tokio-macros-2.4.0 \
		unicode-ident-1.0.13 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		wasm-bindgen-0.2.93 \
		wasm-bindgen-backend-0.2.93 \
		wasm-bindgen-macro-0.2.93 \
		wasm-bindgen-macro-support-0.2.93 \
		wasm-bindgen-shared-0.2.93 \
		web-sys-0.3.70 \
		winapi-util-0.1.9 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.20 \
		yansi-1.0.1
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} # otherwise there's error: found a virtual manifest at `xx` instead of a package manifest

.include <bsd.port.mk>
