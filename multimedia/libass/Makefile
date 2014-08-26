# $FreeBSD$

PORTNAME=	libass
PORTVERSION=	0.11.2
PORTREVISION=	2
CATEGORIES=	multimedia devel

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfribidi.so:${PORTSDIR}/converters/fribidi

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_COMMIT=	03a9c6c

USES=		libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
AUTOMAKE_ARGS=	--add-missing
PATHFIX_MAKEFILEIN=Makefile.am
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ASM ENCA FONTCONFIG HARFBUZZ
OPTIONS_DEFAULT=ASM ENCA FONTCONFIG HARFBUZZ

ASM_DESC?=	Use optimized ASM routines on x86/amd64

ENCA_LIB_DEPENDS=libenca.so:${PORTSDIR}/converters/enca
ENCA_CONFIGURE_ENABLE=enca
ENCA_DESC?=	Charset conversion via enca

FONTCONFIG_LIB_DEPENDS=libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_ENABLE=fontconfig

HARFBUZZ_LIB_DEPENDS=libharfbuzz.so:${PORTSDIR}/print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=harfbuzz
HARFBUZZ_DESC?=	Font shaping via HarfBuzz

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
.if ${PORT_OPTIONS:MASM}
CONFIGURE_ARGS+=	--enable-asm
BUILD_DEPENDS+=	${LOCALBASE}/bin/yasm:${PORTSDIR}/devel/yasm
.else
CONFIGURE_ARGS+=	--disable-asm
.endif
.endif

.include <bsd.port.post.mk>
