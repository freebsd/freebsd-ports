# $FreeBSD$

PORTNAME=	hexyl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Command-line hex viewer

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		atty-0.2.13 \
		bitflags-1.2.0 \
		cc-1.0.45 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		ctrlc-3.1.3 \
		kernel32-sys-0.2.2 \
		libc-0.2.62 \
		nix-0.14.1 \
		strsim-0.8.0 \
		term_size-0.3.1 \
		textwrap-0.11.0 \
		unicode-width-0.1.6 \
		vec_map-0.8.1 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/hexyl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexyl

.include <bsd.port.mk>
