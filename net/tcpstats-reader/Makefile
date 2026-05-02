PORTNAME=	tcpstats-reader
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	net

MAINTAINER=	dave.seddon.ca@gmail.com
COMMENT=	TCP socket statistics reader for FreeBSD tcpstats kernel module
WWW=		https://github.com/randomizedcoder/bsd-xtcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protobuf>=3.0:devel/protobuf

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	randomizedcoder
GH_PROJECT=	bsd-xtcp
CARGO_ENV+=	GIT_CEILING_DIRECTORIES=${WRKDIR}

CARGO_CRATES=	aho-corasick-1.1.4 \
		android_system_properties-0.1.5 \
		anstream-0.6.21 \
		anstyle-1.0.13 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		anyhow-1.0.102 \
		ascii-1.1.0 \
		autocfg-1.5.0 \
		base64-0.21.7 \
		bitflags-2.11.0 \
		bumpalo-3.20.2 \
		bytes-1.11.1 \
		cc-1.2.56 \
		cfg-if-1.0.4 \
		chrono-0.4.44 \
		chunked_transfer-1.5.0 \
		clap-4.5.60 \
		clap_builder-4.5.60 \
		clap_derive-4.5.55 \
		clap_lex-1.0.0 \
		colorchoice-1.0.4 \
		core-foundation-sys-0.8.7 \
		either-1.15.0 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		escape8259-0.5.3 \
		fastrand-2.3.0 \
		find-msvc-tools-0.1.9 \
		fixedbitset-0.5.7 \
		foldhash-0.1.5 \
		getrandom-0.4.2 \
		hashbrown-0.15.5 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		hostname-0.4.2 \
		httpdate-1.0.3 \
		iana-time-zone-0.1.65 \
		iana-time-zone-haiku-0.1.2 \
		id-arena-2.3.0 \
		indexmap-2.13.0 \
		is_terminal_polyfill-1.70.2 \
		itertools-0.13.0 \
		itertools-0.14.0 \
		itoa-1.0.17 \
		js-sys-0.3.91 \
		leb128fmt-0.1.0 \
		libc-0.2.182 \
		libtest-mimic-0.8.1 \
		linux-raw-sys-0.12.1 \
		log-0.4.29 \
		memchr-2.8.0 \
		multimap-0.10.1 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.2 \
		pbjson-0.7.0 \
		pbjson-build-0.7.0 \
		pbjson-types-0.7.0 \
		petgraph-0.7.1 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		prost-0.13.5 \
		prost-build-0.13.5 \
		prost-derive-0.13.5 \
		prost-types-0.13.5 \
		quote-1.0.45 \
		r-efi-6.0.0 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustix-1.1.4 \
		rustversion-1.0.22 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		shlex-1.3.0 \
		strsim-0.11.1 \
		syn-2.0.117 \
		tempfile-3.26.0 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		tiny_http-0.12.0 \
		unicode-ident-1.0.24 \
		unicode-xid-0.2.6 \
		utf8parse-0.2.2 \
		wasip2-1.0.2+wasi-0.2.9 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-bindgen-0.2.114 \
		wasm-bindgen-macro-0.2.114 \
		wasm-bindgen-macro-support-0.2.114 \
		wasm-bindgen-shared-0.2.114 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		windows-core-0.62.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		windows-sys-0.61.2 \
		wit-bindgen-0.51.0 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		zmij-1.0.21

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-extract:
	@${MKDIR} ${WRKSRC}/.git/refs ${WRKSRC}/.git/objects
	@echo "ref: refs/heads/main" > ${WRKSRC}/.git/HEAD

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
