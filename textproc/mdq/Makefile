PORTNAME=	mdq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Like jq but for Markdown: find specific elements in a md doc
WWW=		https://github.com/yshavit/mdq

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	yshavit

CARGO_CRATES=	aho-corasick-1.1.4 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		bit-set-0.8.0 \
		bit-vec-0.8.0 \
		block-buffer-0.10.4 \
		cfg-if-1.0.4 \
		clap-4.6.0 \
		clap_builder-4.6.0 \
		clap_derive-4.6.0 \
		clap_lex-1.1.0 \
		colorchoice-1.0.5 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.7 \
		darling-0.20.11 \
		darling_core-0.20.11 \
		darling_macro-0.20.11 \
		derive_builder-0.20.2 \
		derive_builder_core-0.20.2 \
		derive_builder_macro-0.20.2 \
		digest-0.10.7 \
		equivalent-1.0.2 \
		fancy-regex-0.17.0 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		ident_case-1.0.1 \
		indexmap-2.13.0 \
		indoc-2.0.7 \
		is_terminal_polyfill-1.70.2 \
		itoa-1.0.17 \
		lazy_static-1.5.0 \
		libc-0.2.183 \
		markdown-1.0.0 \
		memchr-2.8.0 \
		once_cell_polyfill-1.70.2 \
		paste-1.0.15 \
		pest-2.8.6 \
		pest_derive-2.8.6 \
		pest_generator-2.8.6 \
		pest_meta-2.8.6 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustversion-1.0.22 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		serde_spanned-1.0.4 \
		sha2-0.10.9 \
		strsim-0.11.1 \
		syn-2.0.117 \
		toml-1.0.6+spec-1.1.0 \
		toml_datetime-1.0.0+spec-1.1.0 \
		toml_parser-1.0.9+spec-1.1.0 \
		toml_writer-1.0.6+spec-1.1.0 \
		typenum-1.19.0 \
		ucd-trie-0.1.7 \
		unicode-id-0.3.6 \
		unicode-ident-1.0.24 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-0.7.15 \
		zmij-1.0.21

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
