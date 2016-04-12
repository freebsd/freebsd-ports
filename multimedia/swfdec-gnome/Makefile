# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/swfdec-gnome/Makefile,v 1.29 2010/09/29 14:04:43 kwm Exp $

PORTNAME=	swfdec-gnome
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk flash player and thumbnailer

LIB_DEPENDS=	libswfdec-0.8.so:graphics/swfdec

USE_GNOME=	gnomeprefix gtk20 intlhack gconf2
INSTALLS_ICONS=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	swfdec-thumbnailer.schemas

.include <bsd.port.mk>
