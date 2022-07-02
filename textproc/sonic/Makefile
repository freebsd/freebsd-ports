PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
PORTREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Fast, lightweight, and schema-less search backend

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	valeriansaliou
USE_RC_SUBR=	sonic

CARGO_CRATES=	ahash-0.3.8 \
		ahash-0.7.6 \
		aho-corasick-0.7.15 \
		autocfg-1.0.1 \
		bindgen-0.59.1 \
		bitflags-1.3.2 \
		bitvec-0.19.5 \
		byteorder-1.4.3 \
		cc-1.0.71 \
		cedarwood-0.4.5 \
		cexpr-0.5.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.3.0 \
		clap-2.33.3 \
		fs_extra-1.2.0 \
		fst-0.3.5 \
		fst-levenshtein-0.3.0 \
		fst-regex-0.3.0 \
		funty-1.1.0 \
		fxhash-0.2.1 \
		getrandom-0.2.3 \
		glob-0.3.0 \
		hashbrown-0.7.2 \
		hashbrown-0.11.2 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		jieba-rs-0.6.6 \
		jobserver-0.1.24 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.107 \
		libloading-0.7.1 \
		librocksdb-sys-6.20.3 \
		linked-hash-map-0.5.4 \
		linked_hash_set-0.1.4 \
		log-0.4.14 \
		memchr-2.3.4 \
		memmap-0.6.2 \
		nix-0.18.0 \
		nom-6.2.1 \
		once_cell-1.8.0 \
		peeking_take_while-0.1.2 \
		phf-0.10.0 \
		phf_codegen-0.10.0 \
		phf_generator-0.10.0 \
		phf_shared-0.10.0 \
		ppv-lite86-0.2.15 \
		proc-macro2-1.0.32 \
		quote-1.0.10 \
		radium-0.5.3 \
		radix-0.6.0 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		regex-1.4.6 \
		regex-syntax-0.3.9 \
		regex-syntax-0.6.25 \
		rocksdb-0.17.0 \
		rustc-hash-1.1.0 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		shlex-1.1.0 \
		siphasher-0.3.7 \
		smallvec-1.7.0 \
		static_assertions-1.1.0 \
		syn-1.0.81 \
		tap-1.0.1 \
		textwrap-0.11.0 \
		toml-0.5.8 \
		twox-hash-1.6.1 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		utf8-ranges-1.0.4 \
		version_check-0.9.3 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		whatlang-0.12.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0

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
