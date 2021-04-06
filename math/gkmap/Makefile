# Created by: Javad Kouhi <javad.kouhi@gmail.com>

PORTNAME=	gkmap
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/gkmap/gkmap/gkmap-${PORTVERSION}/

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Simplification of Boolean Functions using Karnaugh Map

LICENSE=	GPLv2

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: cell_array
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: cell_array

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gnome pkgconfig dos2unix
USE_GNOME=	cairo gdkpixbuf2 gtk20 libglade2 libxml2

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
