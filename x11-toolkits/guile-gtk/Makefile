# New ports collection makefile for:   guile-gtk
# Date created:        1 January 2000
# Whom:                Matt Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	guile-gtk
PORTVERSION= 	0.18
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gnome-guile
DISTNAME=	gnome-guile-0.10

MAINTAINER=	mab@red-bean.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		guile.6:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${DISTNAME}/guile-gtk

.include <bsd.port.mk>
