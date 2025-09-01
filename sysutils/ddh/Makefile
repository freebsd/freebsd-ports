PORTNAME=	ddh
DISTVERSIONPREFIX=	win
DISTVERSION=	64
PORTREVISION=	24
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast duplicate file finder
WWW=		https://github.com/darakian/ddh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	darakian

CARGO_CRATES=	ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		crossbeam-channel-0.5.6 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.13 \
		crossbeam-utils-0.8.14 \
		either-1.8.0 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		itoa-1.0.5 \
		libc-0.2.139 \
		memoffset-0.7.1 \
		nohash-hasher-0.1.3 \
		num_cpus-1.15.0 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		rayon-1.6.1 \
		rayon-core-1.10.1 \
		ryu-1.0.12 \
		scopeguard-1.1.0 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		serde_json-1.0.91 \
		siphasher-0.3.10 \
		strsim-0.8.0 \
		syn-1.0.107 \
		textwrap-0.11.0 \
		unicode-ident-1.0.6 \
		unicode-width-0.1.10 \
		vec_map-0.8.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
