PORTNAME=	elfx86exts
DISTVERSIONPREFIX=	${PORTNAME}@
DISTVERSION=	0.6.2
PORTREVISION=	10
CATEGORIES=	sysutils

MAINTAINER=	jamie@catflap.org
COMMENT=	Decode binaries and show which instruction set extensions they use
WWW=		https://github.com/pkgw/elfx86exts

LICENSE=	MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pkgw

CARGO_CRATES=	adler-1.0.2 \
		anstream-0.6.4 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.2 \
		anstyle-query-1.0.0 \
		anstyle-wincon-3.0.1 \
		assert_cmd-2.0.12 \
		bstr-1.7.0 \
		byteorder-1.5.0 \
		capstone-0.11.0 \
		capstone-sys-0.15.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		clap-4.4.6 \
		clap_builder-4.4.6 \
		clap_derive-4.4.2 \
		clap_lex-0.5.1 \
		colorchoice-1.0.0 \
		crc32fast-1.3.2 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.9.0 \
		escargot-0.5.8 \
		flate2-1.0.27 \
		heck-0.4.1 \
		itertools-0.11.0 \
		itoa-1.0.9 \
		libc-0.2.149 \
		log-0.4.20 \
		memchr-2.6.4 \
		memmap-0.7.0 \
		miniz_oxide-0.7.1 \
		object-0.32.1 \
		once_cell-1.18.0 \
		predicates-3.0.4 \
		predicates-core-1.0.6 \
		predicates-tree-1.0.9 \
		proc-macro2-1.0.69 \
		quote-1.0.33 \
		regex-automata-0.4.1 \
		ruzstd-0.4.0 \
		ryu-1.0.15 \
		serde-1.0.188 \
		serde_derive-1.0.188 \
		serde_json-1.0.107 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.109 \
		syn-2.0.38 \
		termtree-0.4.1 \
		thiserror-core-1.0.38 \
		thiserror-core-impl-1.0.38 \
		twox-hash-1.6.3 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		wait-timeout-0.2.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/elfx86exts

.include <bsd.port.mk>
