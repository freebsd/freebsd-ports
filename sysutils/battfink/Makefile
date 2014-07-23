# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	battfink
PORTVERSION=	0.6.2
PORTREVISION=	14
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Energy saving preferences app for GNOME

USE_XORG=	x11
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix libgnomeui
USES=		gettext gmake pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	battfink.schemas

.include <bsd.port.mk>
