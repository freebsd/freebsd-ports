PORTNAME=	libass
DISTVERSION=	0.15.1
CATEGORIES=	multimedia devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf compiler:c11 iconv libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=nasm:devel/nasm
ASM_CONFIGURE_ENABLE=asm

.include <bsd.port.mk>
