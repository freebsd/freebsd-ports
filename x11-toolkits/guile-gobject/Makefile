# New ports collection makefile for:   guile-gobject
# Date created:        02 May 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guile-gobject
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits scheme
MASTER_SITES=	http://savannah.nongnu.org/download/guile-gtk/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Guile bindings for core GNOME 2 libraries

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_GNOME=	gtk20 libbonobo
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
