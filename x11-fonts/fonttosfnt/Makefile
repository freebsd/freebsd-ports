# $FreeBSD$

PORTNAME=	fonttosfnt
PORTVERSION=	1.1.0
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wrap a bitmap font in a sftn wrapper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		xorg xorg-cat:app
USE_XORG=	xorgproto fontenc

PLIST_FILES=	bin/fonttosfnt man/man1/fonttosfnt.1.gz

.include <bsd.port.mk>
