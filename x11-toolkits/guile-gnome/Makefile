# New ports collection makefile for:	guile-gnome
# Date created:        			9th June 2000
# Whom:                			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guile-gnome
PORTVERSION=	0.10
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-guile
DISTNAME=	gnome-guile-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile \
		guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk \
		glade.4:${PORTSDIR}/devel/libglade

USE_LIBTOOL=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--without-bonobo --without-gtkhtml --with-libglade
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
