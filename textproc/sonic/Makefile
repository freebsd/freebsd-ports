# $FreeBSD$

PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.9
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast, lightweight, and schema-less search backend

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	valeriansaliou
GH_TUPLE=	rust-rocksdb:rust-rocksdb:218edeffcc4122097f384e336f6cb08d2de83889:librocksdbsys/rust-rocksdb \
		lz4:lz4:c10863b98e1503af90616ae99725ecd120265dfb:lz4/rust-rocksdb/librocksdb-sys/lz4 \
		facebook:rocksdb:641fae60f63619ed5d0c9d9e4c4ea5a0ffa3e253:rocksdb/rust-rocksdb/librocksdb-sys/rocksdb \
		google:snappy:2d99bd14d471664758e4dfdf81b44f413a7353fd:snappy/rust-rocksdb/librocksdb-sys/snappy \
		madler:zlib:cacf7f1d4e3d44d871b605da3b647f07d718623f:zlib/rust-rocksdb/librocksdb-sys/zlib \
		facebook:zstd:f3a8bd553a865c59f1bd6e1f68bf182cf75a8f00:zstd/rust-rocksdb/librocksdb-sys/zstd
USE_RC_SUBR=	sonic

CARGO_CRATES=	aho-corasick-0.6.10 \
		ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.14 \
		backtrace-sys-0.1.28 \
		bindgen-0.47.3 \
		bitflags-0.4.0 \
		bitflags-1.0.4 \
		byteorder-1.3.1 \
		cc-1.0.32 \
		cexpr-0.3.5 \
		cfg-if-0.1.7 \
		clang-sys-0.26.4 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		either-1.5.1 \
		env_logger-0.6.1 \
		failure-0.1.5 \
		fs_extra-1.1.0 \
		fst-0.3.3 \
		fst-levenshtein-0.2.1 \
		fst-regex-0.2.2 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		graceful-0.1.1 \
		hashbrown-0.1.8 \
		humantime-1.2.0 \
		jemalloc-sys-0.3.0 \
		jemallocator-0.3.0 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		libloading-0.5.0 \
		linked-hash-map-0.5.2 \
		linked_hash_set-0.1.3 \
		log-0.4.6 \
		memchr-2.2.0 \
		memmap-0.6.2 \
		memoffset-0.2.1 \
		nix-0.7.0 \
		nodrop-0.1.13 \
		nom-4.2.3 \
		num_cpus-1.10.0 \
		peeking_take_while-0.1.2 \
		proc-macro2-0.4.27 \
		quick-error-1.2.2 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		regex-1.1.2 \
		regex-syntax-0.3.9 \
		regex-syntax-0.6.5 \
		rustc-demangle-0.1.13 \
		rustc_version-0.1.7 \
		scopeguard-0.3.3 \
		semver-0.1.20 \
		serde-1.0.89 \
		serde_derive-1.0.89 \
		strsim-0.7.0 \
		syn-0.15.29 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		toml-0.5.0 \
		twox-hash-1.1.2 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		whatlang-0.7.0 \
		which-2.0.1 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1
CARGO_USE_GITHUB=	yes

USERS=		sonic
GROUPS=		sonic

PLIST_FILES=	bin/sonic \
		"@sample ${ETCDIR}/config.cfg.sample"
PORTDOCS=	CONFIGURATION.md PROTOCOL.md README.md
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sonic
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.cfg ${STAGEDIR}${ETCDIR}/config.cfg.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
