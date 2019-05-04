# $FreeBSD$

PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast, lightweight, and schema-less search backend

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	valeriansaliou
USE_RC_SUBR=	sonic

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		bindgen-0.47.3 \
		bitflags-0.4.0 \
		bitflags-1.0.5 \
		byteorder-1.3.1 \
		cc-1.0.36 \
		cexpr-0.3.5 \
		cfg-if-0.1.7 \
		clang-sys-0.26.4 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		either-1.5.2 \
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
		hashbrown-0.3.0 \
		humantime-1.2.0 \
		jemalloc-sys-0.3.0 \
		jemallocator-0.3.0 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.54 \
		libloading-0.5.0 \
		librocksdb-sys-5.18.3 \
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
		numtoa-0.1.0 \
		peeking_take_while-0.1.2 \
		proc-macro2-0.4.29 \
		quick-error-1.2.2 \
		quote-0.6.12 \
		radix-0.4.1 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		regex-1.1.6 \
		regex-syntax-0.3.9 \
		regex-syntax-0.6.6 \
		rocksdb-0.12.2 \
		rustc-demangle-0.1.14 \
		rustc_version-0.1.7 \
		scopeguard-0.3.3 \
		semver-0.1.20 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		strsim-0.8.0 \
		syn-0.15.33 \
		termcolor-1.0.4 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		toml-0.5.0 \
		twox-hash-1.2.0 \
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
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

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
