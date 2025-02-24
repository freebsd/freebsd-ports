PORTNAME=	mdq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
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
		clap-4.5.26 \
		clap_builder-4.5.26 \
		clap_derive-4.5.24 \
		clap_lex-0.7.4 \
		colorchoice-1.0.3 \
		equivalent-1.0.1 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		indexmap-2.7.0 \
		indoc-2.0.5 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.14 \
		lazy_static-1.5.0 \
		libc-0.2.169 \
		markdown-1.0.0-alpha.21 \
		memchr-2.7.4 \
		once_cell-1.20.2 \
		paste-1.0.15 \
		proc-macro2-1.0.93 \
		quote-1.0.38 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		ryu-1.0.18 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.136 \
		serde_spanned-0.6.8 \
		strsim-0.11.1 \
		syn-2.0.96 \
		termsize-0.1.9 \
		toml-0.8.19 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.22 \
		unicode-id-0.3.5 \
		unicode-ident-1.0.14 \
		utf8parse-0.2.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
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
		winnow-0.6.24

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
