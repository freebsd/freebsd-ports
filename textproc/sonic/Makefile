# $FreeBSD$

PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
PORTREVISION=	4
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

CARGO_CRATES=	ahash-0.2.16 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		atty-0.2.13 \
		autocfg-0.1.6 \
		backtrace-0.3.38 \
		backtrace-sys-0.1.31 \
		bindgen-0.49.2 \
		bitflags-1.2.1 \
		byteorder-1.3.2 \
		c2-chacha-0.2.2 \
		cc-1.0.45 \
		cexpr-0.3.5 \
		cfg-if-0.1.10 \
		clang-sys-0.28.1 \
		clap-2.33.0 \
		const-random-0.1.6 \
		const-random-macro-0.1.6 \
		env_logger-0.6.2 \
		failure-0.1.6 \
		fs_extra-1.1.0 \
		fst-0.3.5 \
		fst-levenshtein-0.2.1 \
		fst-regex-0.2.2 \
		fxhash-0.2.1 \
		getrandom-0.1.12 \
		glob-0.3.0 \
		hashbrown-0.3.1 \
		hashbrown-0.6.1 \
		humantime-1.3.0 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		jobserver-0.1.17 \
		lazy_static-1.4.0 \
		libc-0.2.62 \
		libloading-0.5.2 \
		librocksdb-sys-6.1.3 \
		linked-hash-map-0.5.2 \
		linked_hash_set-0.1.3 \
		log-0.4.8 \
		memchr-2.2.1 \
		memmap-0.6.2 \
		nix-0.14.1 \
		nom-4.2.3 \
		num_cpus-1.10.1 \
		peeking_take_while-0.1.2 \
		ppv-lite86-0.2.5 \
		proc-macro-hack-0.5.10 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.5 \
		quick-error-1.2.2 \
		quote-0.6.13 \
		quote-1.0.2 \
		radix-0.5.0 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		regex-1.3.1 \
		regex-syntax-0.3.9 \
		regex-syntax-0.6.12 \
		rocksdb-0.12.4 \
		rustc-demangle-0.1.16 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		syn-1.0.5 \
		termcolor-1.0.5 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		toml-0.5.3 \
		twox-hash-1.5.0 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		utf8-ranges-1.0.4 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		wasi-0.7.0 \
		whatlang-0.7.1 \
		which-2.0.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2

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
