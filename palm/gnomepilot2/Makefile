# New ports collection makefile for:	gnomepilot
# Date created:		28th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	gnomepilot
PORTVERSION=	0.1.52
CATEGORIES=	palm comms gnome
MASTER_SITES=	http://www.gnome.org/gnome-pilot/download/
DISTNAME=	gnome-pilot-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	gob:${PORTSDIR}/x11-toolkits/gob
LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link \
		capplet.1:${PORTSDIR}/sysutils/gnomecontrolcenter

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-pisock=${LOCALBASE}/pilot
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" GLIB_CONFIG="${GLIB_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/pilot/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/pilot/lib"

.include <bsd.port.mk>
