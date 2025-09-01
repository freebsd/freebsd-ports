PORTNAME=	ttynt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.1
PORTREVISION=	10
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Text coloring in your terminal
WWW=		https://github.com/kryksyh/ttynt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	kryksyh

CARGO_CRATES=	aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		clap-2.34.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		lazy_static-1.4.0 \
		libc-0.2.155 \
		memchr-2.7.3 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.85 \
		quote-1.0.36 \
		regex-1.10.5 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		syn-1.0.109 \
		termcolor-1.4.1 \
		textwrap-0.11.0 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.13 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
