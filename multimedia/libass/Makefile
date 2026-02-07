PORTNAME=	libass
DISTVERSION=	0.17.4
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

USES=		compiler:c11 cpe iconv libtool pathfix pkgconfig tar:xz
CPE_VENDOR=	libass_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE=		UNIBREAK
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	UNIBREAK
OPTIONS_DEFAULT_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_CONFIGURE_ENABLE=	asm

UNIBREAK_DESC=			Unicode Line Breaking Algorithm support
UNIBREAK_LIB_DEPENDS=		libunibreak.so:textproc/libunibreak
UNIBREAK_CONFIGURE_ENABLE=	libunibreak

.include <bsd.port.mk>
