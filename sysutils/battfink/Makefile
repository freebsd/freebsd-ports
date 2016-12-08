# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	battfink
PORTVERSION=	0.6.2
PORTREVISION=	15
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Energy saving preferences app for GNOME

INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix libgnomeui
USES=		gettext gmake pathfix pkgconfig tar:bzip2
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11 -lXext
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	battfink.schemas

.include <bsd.port.mk>
