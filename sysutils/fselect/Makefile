# $FreeBSD$

PORTNAME=	fselect
DISTVERSION=	0.6.10
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

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.10 \
		ansi_term-0.12.1 \
		app_dirs-1.2.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.12.0 \
		bitflags-1.2.1 \
		bitreader-0.3.2 \
		bitstream-io-0.8.5 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.12 \
		byte-tools-0.3.1 \
		bytecount-0.6.0 \
		byteorder-1.3.4 \
		bzip2-0.3.3 \
		bzip2-sys-0.1.8+1.0.8 \
		cc-1.0.52 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		chrono-english-0.1.4 \
		cloudabi-0.0.3 \
		crc32fast-1.2.0 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		digest-0.8.1 \
		either-1.5.3 \
		fake-simd-0.1.2 \
		fixedbitset-0.2.0 \
		flate2-1.0.14 \
		fnv-1.0.6 \
		generic-array-0.12.3 \
		getrandom-0.1.14 \
		hermit-abi-0.1.12 \
		humansize-1.1.0 \
		imagesize-0.8.1 \
		indexmap-1.3.2 \
		itertools-0.8.2 \
		itoa-0.4.5 \
		kamadak-exif-0.5.1 \
		keccak-0.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		lock_api-0.3.4 \
		log-0.4.8 \
		lscolors-0.7.0 \
		matroska-0.5.4 \
		memchr-1.0.2 \
		memchr-2.3.3 \
		miniz_oxide-0.3.6 \
		mp3-metadata-0.3.3 \
		mp4parse-0.11.2 \
		mutate_once-0.1.1 \
		nom-3.2.1 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		ole32-sys-0.2.0 \
		opaque-debug-0.2.3 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		petgraph-0.5.0 \
		phf-0.8.0 \
		phf_generator-0.8.0 \
		phf_macros-0.8.0 \
		phf_shared-0.8.0 \
		podio-0.1.6 \
		ppv-lite86-0.2.6 \
		proc-macro-hack-0.5.15 \
		proc-macro2-1.0.10 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		redox_syscall-0.1.56 \
		regex-1.3.7 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.17 \
		ryu-1.0.4 \
		scanlex-0.1.2 \
		scopeguard-1.1.0 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.51 \
		sha-1-0.8.2 \
		sha2-0.8.1 \
		sha3-0.8.2 \
		shell32-sys-0.1.2 \
		siphasher-0.3.3 \
		smallvec-1.4.0 \
		syn-1.0.18 \
		thread_local-1.0.1 \
		time-0.1.43 \
		toml-0.5.6 \
		tree_magic-0.2.3 \
		typenum-1.12.0 \
		unicode-xid-0.2.0 \
		users-0.10.0 \
		wana_kana-2.0.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xattr-0.2.2 \
		xdg-2.2.0 \
		zip-0.5.5
CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
DOCS=		docs/usage.md README.md
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=		DOCS USERS
OPTIONS_DEFAULT=	USERS

USERS_DESC=	Query with 'user' and 'group' fields
USERS_VARS=	CARGO_FEATURES+=users

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
