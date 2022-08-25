PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.5
CATEGORIES=	textproc

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Fast, lightweight, and schema-less search backend

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	valeriansaliou
USE_RC_SUBR=	sonic

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bindgen-0.59.2 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cc-1.0.73 \
		cedarwood-0.4.5 \
		cexpr-0.6.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.3.3 \
		clap-3.2.8 \
		clap_lex-0.2.4 \
		fs_extra-1.2.0 \
		fst-0.3.5 \
		fst-levenshtein-0.3.0 \
		fst-regex-0.3.0 \
		fxhash-0.2.1 \
		getrandom-0.2.7 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		hashbrown-0.12.2 \
		hermit-abi-0.1.19 \
		indexmap-1.9.1 \
		jieba-rs-0.6.6 \
		jobserver-0.1.24 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.126 \
		libloading-0.7.3 \
		librocksdb-sys-6.20.3 \
		linked-hash-map-0.5.6 \
		linked_hash_set-0.1.4 \
		log-0.4.17 \
		memchr-2.5.0 \
		memmap-0.6.2 \
		minimal-lexical-0.2.1 \
		nix-0.18.0 \
		nom-7.1.1 \
		once_cell-1.13.0 \
		os_str_bytes-6.1.0 \
		peeking_take_while-0.1.2 \
		phf-0.10.1 \
		phf_codegen-0.10.0 \
		phf_generator-0.10.0 \
		phf_shared-0.10.0 \
		ppv-lite86-0.2.16 \
		proc-macro2-1.0.40 \
		quote-1.0.20 \
		radix-0.6.0 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		regex-1.6.0 \
		regex-syntax-0.3.9 \
		regex-syntax-0.6.27 \
		rocksdb-0.17.0 \
		rustc-hash-1.1.0 \
		serde-1.0.138 \
		serde_derive-1.0.138 \
		shlex-1.1.0 \
		siphasher-0.3.10 \
		smallvec-1.9.0 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.98 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		tikv-jemalloc-sys-0.4.3+5.2.1-patched.2 \
		tikv-jemallocator-0.4.3 \
		toml-0.5.9 \
		twox-hash-1.6.3 \
		unicode-ident-1.0.1 \
		unicode-segmentation-1.9.0 \
		utf8-ranges-1.0.5 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		whatlang-0.16.0 \
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
