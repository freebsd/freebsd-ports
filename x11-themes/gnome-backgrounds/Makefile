# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-backgrounds/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-backgrounds
PORTVERSION=	3.6.1
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for GNOME

NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
