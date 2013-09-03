# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/eel/Makefile,v 1.90 2010/09/28 09:15:49 kwm Exp $

PORTNAME=	eel
PORTVERSION=	2.26.0
PORTREVISION=	7
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generally useful classes and extensions to GNOME

USES=		gettext gmake pkgconfig
USE_BZIP2=	yes
USE_XORG=	xrender
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gnomedesktop ltverhack intlhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
