# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	0.95.1
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.95
DIST_SUBDIR=	gnome2

MAINTAINER=	hendrik@scholz.net
COMMENT=	A Xine-based video player for the Gnome 2 Desktop

LIB_DEPENDS=	xine.6:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
