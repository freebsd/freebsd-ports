# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	totem
PORTVERSION=	0.99.8
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/..$//}
DIST_SUBDIR=	gnome2

MAINTAINER=	hendrik@scholz.net
COMMENT=	A Xine-based video player for the Gnome 2 Desktop

LIB_DEPENDS=	xine.9:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomedesktop
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lXrandr"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libdvdnav.so)
WITH_DVDNAV=	yes
.endif

.if defined(WITH_DVDNAV)
LIB_DEPENDS+=	dvdnav.1:${PORTSDIR}/multimedia/libdvdnav
.endif

.if !defined(WITH_DVDNAV)
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can enable DVD support by defining WITH_DVDNAV"
.endif

.include <bsd.port.post.mk>
