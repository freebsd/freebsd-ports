# $FreeBSD$

PORTNAME=	libass
DISTVERSION=	0.14.0
CATEGORIES=	multimedia devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf iconv libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE=	HARFBUZZ
OPTIONS_DEFAULT=HARFBUZZ
OPTIONS_EXCLUDE_armv6=HARFBUZZ
OPTIONS_EXCLUDE_armv7=HARFBUZZ
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=nasm:devel/nasm
ASM_CONFIGURE_ENABLE=asm

HARFBUZZ_LIB_DEPENDS=libharfbuzz.so:print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=harfbuzz
HARFBUZZ_DESC?=	Font shaping via HarfBuzz

.include <bsd.port.mk>
