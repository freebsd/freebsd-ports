# New ports collection makefile for:	gnomemc
# Version required:	4.5.41
# Date created:		26 January 1999
# Whom:			Jeremy Lea <reg@shale.csir.co.za>
#
# $FreeBSD$
#

DISTNAME=	mc-4.5.41
PKGNAME=	gnomemc-4.5.41
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/mc

MAINTAINER=	reg@shale.csir.co.za

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--without-edit -with-ncurses
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		MAKE="gmake" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
