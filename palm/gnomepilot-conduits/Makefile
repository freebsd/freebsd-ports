# New ports collection makefile for:	gnomepilot-conduits
# Date created:		16th March 2000
# Whom:			Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot-conduits
PORTVERSION= 	0.2
CATEGORIES=	palm comms gnome
MASTER_SITES=	http://www.gnome.org/gnome-pilot/download/
DISTNAME=	gnome-pilot-conduits-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	gnome-pilot-config:${PORTSDIR}/palm/gnomepilot
LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link \
		capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure mal-conduit/configure
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" GLIB_CONFIG="${GLIB_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/pilot/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/pilot/lib"

.include <bsd.port.mk>
