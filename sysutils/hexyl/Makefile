# $FreeBSD$

PORTNAME=	hexyl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
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
		atty-0.2.14 \
		bitflags-1.2.1 \
		clap-2.33.1 \
		hermit-abi-0.1.13 \
		libc-0.2.71 \
		strsim-0.8.0 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		unicode-width-0.1.7 \
		vec_map-0.8.2 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/hexyl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexyl

.include <bsd.port.mk>
