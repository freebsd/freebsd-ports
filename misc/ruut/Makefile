PORTNAME=	ruut
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	15
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Print arbitrary trees on the command line
WWW=		https://github.com/HarrisonB/ruut

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	HarrisonB

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		clap-2.33.0 \
		digest-0.8.1 \
		either-1.5.3 \
		exitcode-1.1.2 \
		fake-simd-0.1.2 \
		generic-array-0.12.3 \
		heck-0.3.1 \
		hermit-abi-0.1.6 \
		itertools-0.8.2 \
		itoa-0.4.5 \
		json5-0.2.5 \
		libc-0.2.66 \
		maplit-1.0.2 \
		opaque-debug-0.2.3 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.2 \
		pest_meta-2.1.3 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.9 \
		quote-0.6.13 \
		quote-1.0.3 \
		render_as_tree-0.2.0 \
		ryu-1.0.2 \
		serde-1.0.104 \
		serde_json-1.0.47 \
		sha-1-0.8.2 \
		strsim-0.8.0 \
		structopt-0.2.18 \
		structopt-derive-0.2.18 \
		syn-0.15.44 \
		syn-1.0.16 \
		textwrap-0.11.0 \
		typenum-1.11.2 \
		ucd-trie-0.1.2 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
