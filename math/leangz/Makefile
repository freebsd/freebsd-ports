PORTNAME=	leangz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.19
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lean 4 .olean file (de)compressor
WWW=		https://github.com/digama0/leangz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rust-nightly>0:lang/rust-nightly
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	digama0

CARGO_BUILDDEP=	no # because: error[E0658]: use of unstable library feature 'is_none_or'
CARGO_CRATES=	adler2-2.0.0 \
		allocator-api2-0.2.21 \
		anyhow-1.0.102 \
		bitflags-2.11.0 \
		byteorder-1.5.0 \
		cc-1.2.17 \
		cfg-if-1.0.0 \
		crc32fast-1.4.2 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		either-1.15.0 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fastrand-2.3.0 \
		flate2-1.1.0 \
		foldhash-0.1.5 \
		getrandom-0.4.2 \
		hashbrown-0.15.2 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		id-arena-2.3.0 \
		indexmap-2.13.0 \
		itoa-1.0.15 \
		jobserver-0.1.32 \
		leb128fmt-0.1.0 \
		libc-0.2.182 \
		linux-raw-sys-0.12.1 \
		log-0.4.29 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		miniz_oxide-0.8.5 \
		once_cell-1.21.3 \
		pkg-config-0.3.32 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.94 \
		quote-1.0.40 \
		r-efi-6.0.0 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		rustix-1.1.4 \
		ryu-1.0.20 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.140 \
		shlex-1.3.0 \
		syn-2.0.117 \
		tempfile-3.26.0 \
		unicode-ident-1.0.18 \
		unicode-xid-0.2.6 \
		wasip2-1.0.2+wasi-0.2.9 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		wit-bindgen-0.51.0 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		zerocopy-0.8.24 \
		zerocopy-derive-0.8.24 \
		zstd-0.13.3 \
		zstd-safe-7.2.4 \
		zstd-sys-2.0.15+zstd.1.5.7

BIN_FILES=	bin/${PORTNAME} \
		bin/leantar
PLIST_FILES=	${BIN_FILES}

.include <bsd.port.mk>
