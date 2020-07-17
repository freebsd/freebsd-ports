# $FreeBSD$

PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	1
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

CARGO_CRATES=	ahash-0.3.8 \
		aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bindgen-0.53.3 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		cc-1.0.55 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		clang-sys-0.29.3 \
		clap-2.33.1 \
		env_logger-0.7.1 \
		fs_extra-1.1.0 \
		fst-0.3.5 \
		fst-levenshtein-0.2.1 \
		fst-regex-0.2.2 \
		getrandom-0.1.14 \
		glob-0.3.0 \
		hashbrown-0.7.2 \
		hashbrown-0.8.0 \
		hermit-abi-0.1.14 \
		humantime-1.3.0 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		libc-0.2.71 \
		libloading-0.5.2 \
		librocksdb-sys-6.7.4 \
		linked-hash-map-0.5.3 \
		linked_hash_set-0.1.3 \
		log-0.4.8 \
		memchr-2.3.3 \
		memmap-0.6.2 \
		nix-0.17.0 \
		nom-5.1.2 \
		peeking_take_while-0.1.2 \
		ppv-lite86-0.2.8 \
		proc-macro2-1.0.18 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		radix-0.6.0 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		regex-1.3.9 \
		regex-syntax-0.3.9 \
		regex-syntax-0.6.18 \
		rocksdb-0.14.0 \
		rustc-hash-1.1.0 \
		serde-1.0.114 \
		serde_derive-1.0.114 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		syn-1.0.33 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		toml-0.5.6 \
		twox-hash-1.5.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.1 \
		utf8-ranges-1.0.4 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		void-1.0.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		whatlang-0.9.0 \
		which-3.1.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

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
