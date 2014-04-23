# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/cheese/Makefile,v 1.63 2010/09/28 08:21:02 kwm Exp $

PORTNAME=	cheese
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photobooth-inspired app for taking pictures and videos from webcam

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libhal.so:${PORTSDIR}/sysutils/hal

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_XORG=	xxf86vm
USE_GNOME=	gnomeprefix intlhack evolutiondataserver librsvg2 \
		gnomedocutils gnomedesktop
USE_GSTREAMER=	gconf good ogg theora v4l2 vorbis
INSTALLS_OMF=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCS=		AUTHORS COPYING ChangeLog NEWS README
GCONF_SCHEMAS=	cheese.schemas

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
