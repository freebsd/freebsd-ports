# New ports collection makefile for:	gnomepilot
# Version required:	0.1.48
# Date created:		28th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$

DISTNAME=	gnome-pilot-0.1.48
PKGNAME=	gnomepilot-0.1.48
CATEGORIES=	palm comms gnome
MASTER_SITES=	http://www.gnome.org/gnome-pilot/download/

MAINTAINER=	ade@FreeBSD.org

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
		CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
