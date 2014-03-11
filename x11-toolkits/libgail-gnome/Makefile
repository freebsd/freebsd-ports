# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-stable/x11-toolkits/libgail-gnome/Makefile,v 1.1 2010/06/23 12:27:01 kwm Exp $

PORTNAME=	libgail-gnome
PORTVERSION=	1.20.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the ATK interfaces for GNOME widgets

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel libgnomeui atspi
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	lib/gtk-2.0/modules/libgail-gnome.la \
		lib/gtk-2.0/modules/libgail-gnome.so \
		libdata/pkgconfig/libgail-gnome.pc
GCONF_SCHEMAS=	libgail-gnome.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
