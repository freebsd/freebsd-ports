# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-backgrounds/Makefile,v 1.49 2010/09/27 19:52:50 kwm Exp $

PORTNAME=	gnome-backgrounds
PORTVERSION=	2.32.0
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for GNOME 2

USES=		gettext gmake pathfix tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
