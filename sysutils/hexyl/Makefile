# $FreeBSD$

PORTNAME=	hexyl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Command-line hex viewer

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cc-1.0.28 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		ctrlc-3.1.1 \
		kernel32-sys-0.2.2 \
		libc-0.2.49 \
		nix-0.11.0 \
		redox_syscall-0.1.50 \
		redox_termios-0.1.1 \
		strsim-0.7.0 \
		term_size-0.3.1 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		unicode-width-0.1.5 \
		vec_map-0.8.1 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/hexyl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexyl

.include <bsd.port.mk>
