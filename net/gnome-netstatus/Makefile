# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/gnome-netstatus/Makefile,v 1.58 2010/09/29 12:35:14 kwm Exp $

PORTNAME=	gnome-netstatus
PORTVERSION=	2.28.2
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME applet that shows network status

INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	intlhack gnomeprefix libgnome gnomepanel gnomedocutils
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	netstatus.schemas

.include <bsd.port.mk>
