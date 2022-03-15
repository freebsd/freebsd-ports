PORTNAME=	hexyl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	7
CATEGORIES=	sysutils

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Command-line hex viewer

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		anyhow-1.0.42 \
		assert_cmd-1.0.7 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.16 \
		clap-2.33.3 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		float-cmp-0.8.0 \
		hermit-abi-0.1.19 \
		itertools-0.10.1 \
		lazy_static-1.4.0 \
		libc-0.2.98 \
		memchr-2.4.0 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.14 \
		predicates-2.0.0 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.2 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		strsim-0.8.0 \
		syn-1.0.73 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		treeline-0.1.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		wait-timeout-0.2.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/hexyl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexyl

.include <bsd.port.mk>
