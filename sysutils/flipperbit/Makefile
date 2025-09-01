PORTNAME=	flipperbit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	16
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Corrupted files generator, random bits flipper
WWW=		https://github.com/0xor0ne/flipperbit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	0xor0ne

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.1.18 \
		clap_derive-3.1.18 \
		clap_lex-0.2.0 \
		const-random-0.1.13 \
		const-random-macro-0.1.13 \
		crunchy-0.2.2 \
		debugoff-0.2.1 \
		getrandom-0.2.6 \
		goldberg-0.1.0 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.8.1 \
		lazy_static-1.4.0 \
		libc-0.2.125 \
		moisture-0.1.0 \
		os_str_bytes-6.0.0 \
		ppv-lite86-0.2.16 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.38 \
		quote-1.0.18 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		simple-error-0.2.3 \
		strsim-0.10.0 \
		syn-1.0.93 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		tiny-keccak-2.0.2 \
		unicode-xid-0.2.3 \
		unroll-0.1.5 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
