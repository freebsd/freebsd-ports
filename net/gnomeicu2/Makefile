# Ports collection Makefile for:	GnomeICU
# Version required:			0.62a
# Date created:				03/16/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.1.1.1 1999/03/16 08:59:57 nectar Exp $
#

DISTNAME=		gnomeicu-0.62a
CATEGORIES=		net gnome
MASTER_SITES=		ftp://gnomeicu.gdev.net/pub/gnomeicu/          \
			http://www.nectar.com/distfiles/

LIB_DEPENDS=		gnome.1:${PORTSDIR}/x11/gnomelibs              \
			gdk_imlib.3:${PORTSDIR}/graphics/imlib

MAINTAINER=		nectar@FreeBSD.ORG

USE_X_PREFIX=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV=		GTK_CONFIG="${X11BASE}/bin/gtk12-config"
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>
