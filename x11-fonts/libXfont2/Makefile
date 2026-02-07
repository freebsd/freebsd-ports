PORTNAME=	libXfont2
PORTVERSION=	2.0.6
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X font library
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		tar:xz xorg xorg-cat:lib
USE_XORG=	xorgproto xtrans fontenc
INSTALL_TARGET=	install-strip
#USES+=	cpe
#CPE_PRODUCT=	libxfont
#CPE_VENDOR=	x

CONFIGURE_ARGS=--without-xmlto --disable-devel-docs --without-fop

.include <bsd.port.mk>
