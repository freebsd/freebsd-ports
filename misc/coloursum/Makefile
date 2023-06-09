PORTNAME=	coloursum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Colourise your checksum output
WWW=		https://github.com/ticky/coloursum

LICENSE=	MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ticky

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		bitflags-1.0.4 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		ecoji-1.0.0 \
		either-1.5.1 \
		fuchsia-cprng-0.1.1 \
		heck-0.3.1 \
		indoc-0.3.3 \
		indoc-impl-0.3.3 \
		itertools-0.8.0 \
		libc-0.2.50 \
		phf-0.7.24 \
		phf_codegen-0.7.24 \
		phf_generator-0.7.24 \
		phf_shared-0.7.24 \
		proc-macro-hack-0.5.5 \
		proc-macro2-0.4.27 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		siphasher-0.2.3 \
		strsim-0.7.0 \
		structopt-0.2.15 \
		structopt-derive-0.2.15 \
		syn-0.15.29 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unindent-0.1.3 \
		vec_map-0.8.1 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
