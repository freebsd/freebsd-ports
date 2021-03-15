# Created by: johans
# $FreeBSD$

PORTNAME=	paps
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UTF-8 to PostScript converter using Pango

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gettext gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dov
USE_GNOME=	cairo intltool pango
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/paps man/man1/paps.1.gz

.include <bsd.port.mk>
