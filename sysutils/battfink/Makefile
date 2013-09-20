# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	battfink
PORTVERSION=	0.6.2
PORTREVISION=	14
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An energy saving preferences app for GNOME

USE_BZIP2=	yes
USE_XORG=	x11
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	battfink.schemas

NO_STAGE=	yes
.include <bsd.port.mk>
