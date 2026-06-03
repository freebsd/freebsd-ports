PORTNAME=	fonttosfnt
DISTVERSION=	1.2.5
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wrap a bitmap font in a sfnt (OpenType) wrapper
WWW=		https://gitlab.freedesktop.org/xorg/app/fonttosfnt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xorgproto fontenc

PLIST_FILES=	bin/fonttosfnt share/man/man1/fonttosfnt.1.gz

.include <bsd.port.mk>
