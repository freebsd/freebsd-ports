PORTNAME=	fselect
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Find files with SQL-like queries
WWW=		https://github.com/jhspetersson/fselect

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jhspetersson

CARGO_CRATES=	adler-1.0.2 \
		aes-0.7.5 \
		ahash-0.7.6 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		base64ct-1.0.1 \
		bitflags-1.3.2 \
		bitreader-0.3.6 \
		bitstream-io-1.3.0 \
		block-buffer-0.10.2 \
		bstr-0.2.17 \
		bytecount-0.6.2 \
		byteorder-1.4.3 \
		bzip2-0.4.3 \
		bzip2-sys-0.1.11+1.0.8 \
		cc-1.0.73 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		chrono-english-0.1.7 \
		cipher-0.3.0 \
		clipboard-win-4.4.1 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.5 \
		cpufeatures-0.2.2 \
		crc32fast-1.3.2 \
		crossbeam-utils-0.8.8 \
		crypto-common-0.1.3 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		digest-0.10.3 \
		directories-4.0.1 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		endian-type-0.1.2 \
		env_logger-0.8.4 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		error-code-2.3.1 \
		fallible_collections-0.4.4 \
		fd-lock-3.0.5 \
		fixedbitset-0.2.0 \
		flate2-1.0.23 \
		fnv-1.0.7 \
		generic-array-0.14.5 \
		getrandom-0.2.6 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		hmac-0.12.1 \
		humansize-1.1.1 \
		humantime-2.1.0 \
		imagesize-0.9.0 \
		indexmap-1.8.1 \
		io-lifetimes-0.6.1 \
		itertools-0.8.2 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		jobserver-0.1.24 \
		kamadak-exif-0.5.4 \
		keccak-0.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.125 \
		linux-raw-sys-0.0.46 \
		lock_api-0.3.4 \
		log-0.4.17 \
		lscolors-0.9.0 \
		matroska-0.12.0 \
		memchr-1.0.2 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		miniz_oxide-0.5.1 \
		mp3-metadata-0.3.3 \
		mp4parse-0.12.0 \
		mutate_once-0.1.1 \
		nibble_vec-0.1.0 \
		nix-0.23.1 \
		nom-3.2.1 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_threads-0.1.6 \
		once_cell-1.10.0 \
		opaque-debug-0.3.0 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		password-hash-0.3.2 \
		pbkdf2-0.10.1 \
		petgraph-0.5.1 \
		phf-0.10.1 \
		phf_generator-0.10.0 \
		phf_macros-0.10.0 \
		phf_shared-0.10.0 \
		pkg-config-0.3.25 \
		ppv-lite86-0.2.16 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.38 \
		quote-1.0.18 \
		radix_trie-0.2.1 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rustix-0.34.6 \
		rustyline-9.1.2 \
		ryu-1.0.9 \
		scanlex-0.1.4 \
		scopeguard-1.1.0 \
		serde-1.0.137 \
		serde_derive-1.0.137 \
		serde_json-1.0.81 \
		sha-1-0.10.0 \
		sha1-0.10.1 \
		sha2-0.10.2 \
		sha3-0.10.1 \
		siphasher-0.3.10 \
		smallvec-1.8.0 \
		static_assertions-1.1.0 \
		str-buf-1.0.5 \
		subtle-2.4.1 \
		svg-0.10.0 \
		syn-1.0.94 \
		termcolor-1.1.3 \
		thiserror-1.0.31 \
		thiserror-impl-1.0.31 \
		time-0.1.43 \
		time-0.3.9 \
		time-macros-0.2.4 \
		toml-0.5.9 \
		tree_magic-0.2.3 \
		typenum-1.15.0 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.3 \
		users-0.11.0 \
		utf8parse-0.2.0 \
		version_check-0.9.4 \
		wana_kana-2.1.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.30.0 \
		windows_aarch64_msvc-0.30.0 \
		windows_i686_gnu-0.30.0 \
		windows_i686_msvc-0.30.0 \
		windows_x86_64_gnu-0.30.0 \
		windows_x86_64_msvc-0.30.0 \
		xattr-0.2.3 \
		zip-0.6.2 \
		zstd-0.10.2+zstd.1.5.2 \
		zstd-safe-4.1.6+zstd.1.5.2 \
		zstd-sys-1.6.3+zstd.1.5.2
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
