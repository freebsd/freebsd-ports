# New ports collection makefile for:	gnomemc
# Version required:	4.5.30
# Date created:		26 January 1999
# Whom:			Jeremy Lea <reg@shale.csir.co.za>
#
# $Id: Makefile,v 1.4 1999/04/08 18:08:38 steve Exp $
#

DISTNAME=	mc-4.5.30
PKGNAME=	gnomemc-4.5.30
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/mc

MAINTAINER=	reg@shale.csir.co.za

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

# implicit dependencies:
# gettext, glib12, xpm, gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--without-edit -with-ncurses
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		MAKE="gmake" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

.include <bsd.port.mk>
