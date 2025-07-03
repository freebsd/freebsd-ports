PORTNAME=	csview
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
PORTREVISION=	9
CATEGORIES=	textproc

MAINTAINER=	ruben@verweg.com
COMMENT=	High performance csv viewer with cjk/emoji support
WWW=		https://github.com/wfxr/csview

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	wfxr

CARGO_CRATES=	anstream-0.6.13 \
		anstyle-1.0.6 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		anyhow-1.0.82 \
		bitflags-2.5.0 \
		cc-1.0.94 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_complete-4.5.2 \
		clap_derive-4.5.4 \
		clap_lex-0.7.0 \
		colorchoice-1.0.0 \
		csv-1.3.0 \
		csv-core-0.1.11 \
		either-1.11.0 \
		errno-0.2.8 \
		errno-0.3.8 \
		errno-dragonfly-0.1.2 \
		exitcode-1.1.2 \
		heck-0.5.0 \
		itertools-0.12.1 \
		itertools-0.13.0 \
		itoa-1.0.11 \
		libc-0.2.153 \
		linux-raw-sys-0.4.13 \
		memchr-2.7.2 \
		pager-0.16.1 \
		proc-macro2-1.0.80 \
		quote-1.0.36 \
		rustix-0.38.32 \
		ryu-1.0.17 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		strsim-0.11.1 \
		syn-2.0.59 \
		terminal_size-0.3.0 \
		unicode-ident-1.0.12 \
		unicode-truncate-1.0.0 \
		unicode-width-0.1.12 \
		utf8parse-0.2.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.5

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
