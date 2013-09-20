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

LIB_DEPENDS=	swfdec-0.8:${PORTSDIR}/graphics/swfdec

USE_GNOME=	gnomehack gnomeprefix gtk20 intlhack gconf2
USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	swfdec-thumbnailer.schemas

MAN1=		swfdec-player.1 swfdec-thumbnailer.1

NO_STAGE=	yes
post-install:
	@-update-desktop-database

.include <bsd.port.mk>
