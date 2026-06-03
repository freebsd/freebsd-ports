PORTNAME=	ddh
DISTVERSION=	0.13.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast duplicate file finder
WWW=		https://github.com/darakian/ddh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	darakian

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-4.0.23 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.6 \
		crossbeam-utils-0.8.12 \
		either-1.6.1 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.113 \
		memoffset-0.6.5 \
		nohash-hasher-0.2.0 \
		num_cpus-1.13.1 \
		once_cell-1.16.0 \
		os_str_bytes-6.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		ryu-1.0.9 \
		scopeguard-1.1.0 \
		serde-1.0.135 \
		serde_json-1.0.78 \
		siphasher-0.3.9 \
		strsim-0.10.0 \
		syn-1.0.103 \
		termcolor-1.1.2 \
		unicode-ident-1.0.5 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
