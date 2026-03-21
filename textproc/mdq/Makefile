PORTNAME=	mdq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
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

CARGO_CRATES=	aho-corasick-1.1.3 \
		anstream-0.6.20 \
		anstyle-1.0.11 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.4 \
		anstyle-wincon-3.0.10 \
		bit-set-0.8.0 \
		bit-vec-0.8.0 \
		block-buffer-0.10.4 \
		cfg-if-1.0.1 \
		clap-4.5.45 \
		clap_builder-4.5.44 \
		clap_derive-4.5.45 \
		clap_lex-0.7.5 \
		colorchoice-1.0.4 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.6 \
		darling-0.20.11 \
		darling_core-0.20.11 \
		darling_macro-0.20.11 \
		derive_builder-0.20.2 \
		derive_builder_core-0.20.2 \
		derive_builder_macro-0.20.2 \
		digest-0.10.7 \
		equivalent-1.0.2 \
		fancy-regex-0.16.1 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		hashbrown-0.15.5 \
		heck-0.5.0 \
		ident_case-1.0.1 \
		indexmap-2.10.0 \
		indoc-2.0.6 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.15 \
		lazy_static-1.5.0 \
		libc-0.2.175 \
		markdown-1.0.0 \
		memchr-2.7.5 \
		once_cell_polyfill-1.70.1 \
		paste-1.0.15 \
		pest-2.8.1 \
		pest_derive-2.8.1 \
		pest_generator-2.8.1 \
		pest_meta-2.8.1 \
		proc-macro2-1.0.101 \
		quote-1.0.40 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		ryu-1.0.20 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.142 \
		serde_spanned-1.0.0 \
		sha2-0.10.9 \
		strsim-0.11.1 \
		syn-2.0.106 \
		thiserror-2.0.15 \
		thiserror-impl-2.0.15 \
		toml-0.9.5 \
		toml_datetime-0.7.0 \
		toml_parser-1.0.2 \
		toml_writer-1.0.2 \
		typenum-1.18.0 \
		ucd-trie-0.1.7 \
		unicode-id-0.3.5 \
		unicode-ident-1.0.18 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		windows-link-0.1.3 \
		windows-sys-0.60.2 \
		windows-targets-0.53.3 \
		windows_aarch64_gnullvm-0.53.0 \
		windows_aarch64_msvc-0.53.0 \
		windows_i686_gnu-0.53.0 \
		windows_i686_gnullvm-0.53.0 \
		windows_i686_msvc-0.53.0 \
		windows_x86_64_gnu-0.53.0 \
		windows_x86_64_gnullvm-0.53.0 \
		windows_x86_64_msvc-0.53.0 \
		winnow-0.7.12

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
