PORTNAME=	mdq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
PORTREVISION=	3
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
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.7 \
		block-buffer-0.10.4 \
		cfg-if-1.0.0 \
		clap-4.5.32 \
		clap_builder-4.5.32 \
		clap_derive-4.5.32 \
		clap_lex-0.7.4 \
		colorchoice-1.0.3 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.6 \
		diff-0.1.13 \
		digest-0.10.7 \
		equivalent-1.0.2 \
		generic-array-0.14.7 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		indexmap-2.8.0 \
		indoc-2.0.6 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.15 \
		lazy_static-1.5.0 \
		libc-0.2.171 \
		markdown-1.0.0-alpha.23 \
		memchr-2.7.4 \
		once_cell-1.21.1 \
		paste-1.0.15 \
		pest-2.8.0 \
		pest_derive-2.8.0 \
		pest_generator-2.8.0 \
		pest_meta-2.8.0 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.94 \
		quote-1.0.40 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		ryu-1.0.20 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.140 \
		serde_spanned-0.6.8 \
		sha2-0.10.8 \
		strsim-0.11.1 \
		syn-2.0.100 \
		thiserror-2.0.12 \
		thiserror-impl-2.0.12 \
		toml-0.8.20 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.24 \
		typenum-1.18.0 \
		ucd-trie-0.1.7 \
		unicode-id-0.3.5 \
		unicode-ident-1.0.18 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.7.4 \
		yansi-1.0.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
