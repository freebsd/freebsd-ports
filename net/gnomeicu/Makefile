# Ports collection Makefile for:	GnomeICU
# Version required:			0.62a
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.9 1999/04/07 16:23:52 nectar Exp $
#

DISTNAME=		gnomeicu-0.64
CATEGORIES=		net gnome
MASTER_SITES=		ftp://gnomeicu.gdev.net/pub/gnomeicu/          \
			http://www.nectar.com/distfiles/

MAINTAINER=		nectar@FreeBSD.ORG

LIB_DEPENDS=		panel_applet.1:${PORTSDIR}/x11/gnomecore       \
			gdk_imlib.3:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		GTK_CONFIG="${X11BASE}/bin/gtk12-config"
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>
