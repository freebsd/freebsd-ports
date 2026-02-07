PORTNAME=	fonttosfnt
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wrap a bitmap font in a sftn wrapper
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		xorg xorg-cat:app
USE_XORG=	xorgproto fontenc

GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/fonttosfnt share/man/man1/fonttosfnt.1.gz

.include <bsd.port.mk>
