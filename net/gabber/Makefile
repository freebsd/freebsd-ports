# New ports collection makefile for:	gabber
# Date created:				20 Jun 2000
# Whom:				Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	gabber
PORTVERSION=	0.6.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	erich@tacni.net

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtkmm-1.2:${PORTSDIR}/x11-toolkits/gtk-- \
		gnomemm-1.1.2:${PORTSDIR}/x11-toolkits/gnome-- \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		gnet.0:${PORTSDIR}/net/gnet \
		glade.4:${PORTSDIR}/devel/libglade
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" GLIB_CONFIG="${GLIB_CONFIG}" \
		GNOME_LIBCONFIG_PATH="${LOCALBASE}/lib:${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
