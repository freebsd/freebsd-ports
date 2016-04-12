# $FreeBSD$

PORTNAME=	libass
PORTVERSION=	0.13.2
CATEGORIES=	multimedia devel

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}

USES=		autoreconf iconv libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=Makefile.am
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	HARFBUZZ
OPTIONS_DEFAULT=HARFBUZZ
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=${LOCALBASE}/bin/yasm:devel/yasm
ASM_CONFIGURE_ENABLE=asm

HARFBUZZ_LIB_DEPENDS=libharfbuzz.so:print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=harfbuzz
HARFBUZZ_DESC?=	Font shaping via HarfBuzz

.include <bsd.port.mk>
