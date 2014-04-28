# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-backgrounds/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	gnome-backgrounds
PORTVERSION=	3.12.1
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for GNOME

USES=		gettext gmake pathfix tar:xz
USE_GNOME=	gnomeprefix intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
