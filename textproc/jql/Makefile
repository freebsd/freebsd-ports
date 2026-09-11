PORTNAME=	jql
DISTVERSIONPREFIX=	jql-v
DISTVERSION=	9.0.3
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JSON Query Language CLI tool built with Rust
WWW=		https://github.com/yamafaktory/jql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	fails to link: ld: error: undefined symbol: __atomic_load

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	yamafaktory

CARGO_CRATES=	aho-corasick-1.1.5 \
		alloca-0.4.0 \
		allocator-api2-0.2.21 \
		anes-0.1.6 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		anyhow-1.0.104 \
		ar_archive_writer-0.5.3 \
		autocfg-1.5.1 \
		bumpalo-3.20.3 \
		cast-0.3.0 \
		cc-1.4.5 \
		cfg-if-1.0.4 \
		ciborium-0.2.2 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		clap-4.6.6 \
		clap_builder-4.6.6 \
		clap_derive-4.6.4 \
		clap_lex-1.1.0 \
		colorchoice-1.0.5 \
		colored_json-5.0.0 \
		criterion-0.8.2 \
		criterion-plot-0.8.2 \
		crossbeam-deque-0.8.8 \
		crossbeam-epoch-0.9.21 \
		crossbeam-utils-0.8.23 \
		crunchy-0.2.4 \
		either-1.18.0 \
		equivalent-1.0.2 \
		find-msvc-tools-0.1.12 \
		float-cmp-0.10.0 \
		foldhash-0.2.0 \
		futures-core-0.3.34 \
		futures-task-0.3.34 \
		futures-util-0.3.34 \
		half-2.7.1 \
		halfbrown-0.4.0 \
		hashbrown-0.16.1 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		indexmap-2.14.2 \
		is_terminal_polyfill-1.70.2 \
		itertools-0.13.0 \
		itoa-1.0.18 \
		js-sys-0.3.105 \
		libc-0.2.189 \
		libmimalloc-sys-0.1.49 \
		memchr-2.8.3 \
		mimalloc-0.1.52 \
		num-traits-0.2.19 \
		object-0.39.1 \
		once_cell-1.21.4 \
		once_cell_polyfill-1.70.2 \
		oorandom-11.1.5 \
		page_size-0.6.0 \
		pin-project-lite-0.2.17 \
		plotters-0.3.7 \
		plotters-backend-0.3.7 \
		plotters-svg-0.3.7 \
		proc-macro2-1.0.107 \
		psm-0.1.32 \
		quote-1.0.47 \
		rayon-1.12.0 \
		rayon-core-1.13.0 \
		ref-cast-1.0.27 \
		ref-cast-impl-1.0.27 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rustversion-1.0.23 \
		ryu-1.0.23 \
		same-file-1.0.6 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		serde_json-1.0.151 \
		serde_stacker-0.1.14 \
		shlex-2.0.1 \
		simd-json-0.18.1 \
		simdutf8-0.1.5 \
		slab-0.4.12 \
		stacker-0.1.25 \
		strsim-0.11.1 \
		syn-2.0.119 \
		syn-3.0.5 \
		thiserror-2.0.20 \
		thiserror-impl-2.0.20 \
		tinytemplate-1.2.1 \
		unicode-ident-1.0.24 \
		utf8parse-0.2.2 \
		value-trait-0.12.2 \
		walkdir-2.5.0 \
		wasm-bindgen-0.2.128 \
		wasm-bindgen-macro-0.2.128 \
		wasm-bindgen-macro-support-0.2.128 \
		wasm-bindgen-shared-0.2.128 \
		web-sys-0.3.105 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.11 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-1.0.4 \
		yansi-1.0.1 \
		zerocopy-0.8.56 \
		zerocopy-derive-0.8.56 \
		zmij-1.0.23
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} # otherwise there's error: found a virtual manifest at `xx` instead of a package manifest

.include <bsd.port.mk>
