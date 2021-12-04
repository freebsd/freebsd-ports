PORTNAME=	onefetch
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.2
PORTREVISION=	4
CATEGORIES=	sysutils devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Git repository summary on your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS=	git:devel/git

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	o2sh

CARGO_CRATES=	addr2line-0.15.2 \
		adler-1.0.2 \
		adler32-1.2.0 \
		aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		arrayvec-0.4.12 \
		askalono-0.4.3 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.60 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.16 \
		byte-tools-0.3.1 \
		byte-unit-4.0.12 \
		bytecount-0.6.2 \
		bytemuck-1.7.0 \
		byteorder-1.4.3 \
		cc-1.0.68 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		chrono-humanize-0.2.1 \
		chrono-tz-0.5.3 \
		clap-2.33.3 \
		color_quant-1.1.0 \
		colored-2.0.0 \
		crc32fast-1.2.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		dashmap-4.0.2 \
		deflate-0.8.6 \
		deunicode-0.4.3 \
		digest-0.8.1 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		dtoa-0.4.8 \
		either-1.6.1 \
		encoding_rs-0.8.28 \
		encoding_rs_io-0.1.7 \
		env_logger-0.8.4 \
		error-chain-0.12.4 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		fake-simd-0.1.2 \
		flate2-1.0.20 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		generic-array-0.12.4 \
		getrandom-0.2.3 \
		gif-0.11.2 \
		gimli-0.24.0 \
		git2-0.13.20 \
		glob-0.3.0 \
		globset-0.4.8 \
		globwalk-0.8.1 \
		grep-matcher-0.1.5 \
		grep-searcher-0.1.8 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		humansize-1.1.1 \
		humantime-2.1.0 \
		idna-0.2.3 \
		ignore-0.4.18 \
		image-0.23.14 \
		instant-0.1.9 \
		itertools-0.9.0 \
		itoa-0.4.7 \
		jobserver-0.1.22 \
		jpeg-decoder-0.1.22 \
		json-0.12.4 \
		lazy_static-1.4.0 \
		libc-0.2.97 \
		libgit2-sys-0.12.21+1.1.0 \
		libz-sys-1.1.3 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.4 \
		log-0.4.14 \
		maplit-1.0.2 \
		matches-0.1.8 \
		memchr-2.4.0 \
		memmap2-0.3.0 \
		memoffset-0.6.4 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.4 \
		more-asserts-0.2.1 \
		nodrop-0.1.14 \
		num-format-0.4.0 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		object-0.25.3 \
		once_cell-1.8.0 \
		opaque-debug-0.2.3 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		parse-zoneinfo-0.3.0 \
		paste-1.0.5 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pkg-config-0.3.19 \
		png-0.16.8 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.9 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rmp-0.8.10 \
		rmp-serde-0.14.4 \
		rustc-demangle-0.1.20 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		serde_yaml-0.8.17 \
		sha-1-0.8.2 \
		slug-0.1.4 \
		smallvec-1.6.1 \
		strsim-0.8.0 \
		strum-0.21.0 \
		strum_macros-0.21.1 \
		syn-1.0.73 \
		synstructure-0.12.4 \
		tera-1.12.0 \
		term_size-0.3.2 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		tiff-0.6.1 \
		time-0.1.43 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		tokei-12.1.2 \
		toml-0.5.8 \
		typenum-1.13.0 \
		ucd-trie-0.1.3 \
		unic-char-property-0.9.0 \
		unic-char-range-0.9.0 \
		unic-common-0.9.0 \
		unic-segment-0.9.0 \
		unic-ucd-segment-0.9.0 \
		unic-ucd-version-0.9.0 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		utf8-width-0.1.5 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		weezl-0.1.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5 \
		zstd-0.5.4+zstd.1.4.7 \
		zstd-safe-2.0.6+zstd.1.4.7 \
		zstd-sys-1.4.18+zstd.1.4.7

PLIST_FILES=		bin/${PORTNAME}
PORTDOCS=		CONTRIBUTING.md README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
