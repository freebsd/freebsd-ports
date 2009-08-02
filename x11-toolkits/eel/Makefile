# New ports collection makefile for:    eel2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/eel/Makefile,v 1.84 2009/03/17 13:40:09 kwm Exp $
#

PORTNAME=	eel
PORTVERSION=	2.26.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generally useful classes and extensions to GNOME

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	xrender
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gnomedesktop ltverhack intlhack
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
