PORTNAME=	comrak
DISTVERSION=	0.9.1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CommonMark + GFM compatible Markdown parser and renderer
WWW=		https://docs.rs/comrak/latest/comrak/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	kivikakk

CARGO_CRATES=	aho-corasick-0.7.20 \
		ansi_term-0.12.1 \
		atom-0.3.6 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		block-buffer-0.10.3 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		cpufeatures-0.2.5 \
		crypto-common-0.1.6 \
		digest-0.10.6 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		entities-1.0.1 \
		generic-array-0.14.6 \
		getrandom-0.2.8 \
		hermit-abi-0.1.19 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		memchr-2.5.0 \
		once_cell-1.17.0 \
		pest-2.5.2 \
		pest_derive-2.5.2 \
		pest_generator-2.5.2 \
		pest_meta-2.5.2 \
		proc-macro2-1.0.49 \
		pulse-0.5.3 \
		quote-1.0.23 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.0 \
		regex-syntax-0.6.28 \
		serde-1.0.152 \
		sha1-0.10.5 \
		shell-words-1.1.0 \
		strsim-0.8.0 \
		syn-1.0.107 \
		textwrap-0.11.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		time-0.1.45 \
		time-0.3.17 \
		time-core-0.1.0 \
		timebomb-0.1.2 \
		twoway-0.2.2 \
		typed-arena-1.7.0 \
		typenum-1.16.0 \
		ucd-trie-0.1.5 \
		unchecked-index-0.2.2 \
		unicode-ident-1.0.6 \
		unicode-width-0.1.10 \
		unicode_categories-0.1.1 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xdg-2.4.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
