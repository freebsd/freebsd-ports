PORTNAME=	libass
DISTVERSION=	0.17.1
PORTREVISION=	2
CATEGORIES=	multimedia devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer
WWW=		https://github.com/libass/libass

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf compiler:c11 cpe iconv libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS_i386=	-Wl,-znotext
CPE_VENDOR=	libass_project

OPTIONS_DEFINE=	UNIBREAK
OPTIONS_DEFAULT=UNIBREAK
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=nasm:devel/nasm
ASM_CONFIGURE_ENABLE=asm

UNIBREAK_DESC=		Unicode Line Breaking Algorithm support
UNIBREAK_LIB_DEPENDS=	libunibreak.so:textproc/libunibreak
UNIBREAK_CONFIGURE_ENABLE=	libunibreak

.include <bsd.port.mk>
