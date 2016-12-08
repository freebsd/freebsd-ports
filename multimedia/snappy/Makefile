# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/snappy/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	snappy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3
PKGNAMESUFFIX=	player

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open source gstreamer media player

LIB_DEPENDS=	libclutter-gst-2.0.so:multimedia/clutter-gst \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3

USES=		desktop-file-utils gettext gmake pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
