# Created by: Javad Kouhi <javad.kouhi@gmail.com>
# $FreeBSD$

PORTNAME=	gkmap
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/gkmap/gkmap/gkmap-${PORTVERSION}/

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Simplification of Boolean Functions using Karnaugh Map

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig dos2unix
USE_GNOME=	cairo gdkpixbuf2 gtk20 libglade2 libxml2

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
