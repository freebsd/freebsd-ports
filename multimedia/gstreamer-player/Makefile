# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	multimedia audio gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-player/
PKGNAMESUFFIX=	-player
DISTNAME=	gst-player-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Simple yet functional mediaplayer written with GStreamer

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomeprefix \
		gnomedesktop \
		gstreamerplugins
USE_INC_LIBTOOL_VER=13
GNOME_DESKTOP_VERSION=2
WANT_GNOME=	yes
PLIST_SUB=	\
	VERSION="${PORTVERSION}" \
	SHLIB_VERSION="${SHLIB_VERSION}"
INSTALLS_SHLIB=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gst-player.1

# library minor number
SHLIB_VERSION=	0

pre-su-install:
# required for PREFIX safeness, the dir might not exist under PREFIX
	@${MKDIR} ${PREFIX}/etc/gconf/

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mnautilus2}!=""
USE_GNOME+=	nautilus2
PLIST_SUB+=	GST_PLAYER_VIEW=""
.else
PLIST_SUB+=	GST_PLAYER_VIEW="@comment "
.endif

.include <bsd.port.post.mk>
