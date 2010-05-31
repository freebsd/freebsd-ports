# New ports collection makefile for:	cheese
# Date created:				13 January 2008
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/cheese/Makefile,v 1.58 2010/04/27 15:51:59 kwm Exp $
#

PORTNAME=	cheese
PORTVERSION=	2.30.1
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		hal.1:${PORTSDIR}/sysutils/hal

USE_XORG=	xxf86vm
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack evolutiondataserver librsvg2 \
		gnomedocutils gnomedesktop
USE_GETTEXT=	yes
USE_GSTREAMER=	good v4l2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GCONF_SCHEMAS=	cheese.schemas

post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
