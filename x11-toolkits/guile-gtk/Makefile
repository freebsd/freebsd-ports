# New ports collection makefile for:   guile-gtk
# Date created:        1 January 2000
# Whom:                Matt Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	guile-gtk
PORTVERSION=	0.19
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.ping.de/sites/zagadka/guile-gtk/download/
MASTER_SITE_SUBDIR=	unstable/sources/gnome-guile

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile

USE_GTK=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
