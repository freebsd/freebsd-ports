# $FreeBSD$

PORTNAME=	fselect
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Find files with SQL-like queries

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jhspetersson

CARGO_CRATES=	adler32-1.2.0 \
		ahash-0.3.8 \
		aho-corasick-0.7.13 \
		ansi_term-0.12.1 \
		app_dirs-1.2.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		bitreader-0.3.2 \
		bitstream-io-0.8.5 \
		block-buffer-0.9.0 \
		block-padding-0.2.1 \
		bstr-0.2.13 \
		bytecount-0.6.0 \
		byteorder-1.3.4 \
		bzip2-0.3.3 \
		bzip2-sys-0.1.9+1.0.8 \
		cc-1.0.60 \
		cfg-if-0.1.10 \
		chrono-0.4.19 \
		chrono-english-0.1.4 \
		cloudabi-0.0.3 \
		cpuid-bool-0.1.2 \
		crc32fast-1.2.0 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		digest-0.9.0 \
		either-1.6.1 \
		fixedbitset-0.2.0 \
		flate2-1.0.14 \
		fnv-1.0.7 \
		generic-array-0.14.4 \
		getrandom-0.1.15 \
		hashbrown-0.7.2 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.17 \
		humansize-1.1.0 \
		imagesize-0.8.8 \
		indexmap-1.6.0 \
		itertools-0.8.2 \
		itoa-0.4.6 \
		kamadak-exif-0.5.2 \
		keccak-0.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.79 \
		lock_api-0.3.4 \
		log-0.4.11 \
		lscolors-0.7.1 \
		matroska-0.5.4 \
		memchr-1.0.2 \
		memchr-2.3.3 \
		miniz_oxide-0.3.7 \
		mp3-metadata-0.3.3 \
		mp4parse-0.11.4 \
		mutate_once-0.1.1 \
		nom-3.2.1 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		ole32-sys-0.2.0 \
		opaque-debug-0.3.0 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		petgraph-0.5.1 \
		phf-0.8.0 \
		phf_generator-0.8.0 \
		phf_macros-0.8.0 \
		phf_shared-0.8.0 \
		pkg-config-0.3.18 \
		ppv-lite86-0.2.9 \
		proc-macro-hack-0.5.18 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.18 \
		ryu-1.0.5 \
		scanlex-0.1.2 \
		scopeguard-1.1.0 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		serde_json-1.0.58 \
		sha-1-0.9.1 \
		sha2-0.9.1 \
		sha3-0.9.1 \
		shell32-sys-0.1.2 \
		siphasher-0.3.3 \
		smallvec-1.4.2 \
		static_assertions-1.1.0 \
		syn-1.0.42 \
		text_io-0.1.8 \
		thiserror-1.0.21 \
		thiserror-impl-1.0.21 \
		thread_local-1.0.1 \
		time-0.1.44 \
		toml-0.5.6 \
		tree_magic-0.2.3 \
		typenum-1.12.0 \
		unicode-xid-0.2.1 \
		users-0.11.0 \
		version_check-0.9.2 \
		wana_kana-2.0.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xattr-0.2.2 \
		xdg-2.2.0 \
		zip-0.5.8
CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
_DOCS=		docs/usage.md README.md
PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=		DOCS USERS
OPTIONS_DEFAULT=	USERS

USERS_DESC=	Query with 'user' and 'group' fields
USERS_VARS=	CARGO_FEATURES+=users

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
