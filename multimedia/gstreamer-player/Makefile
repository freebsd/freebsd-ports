# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	multimedia audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-player
DISTNAME=	gst-player-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Simple yet functional mediaplayer written with GStreamer

LIB_DEPENDS=	gstreamer-0.6.1:${PORTSDIR}/multimedia/gstreamer \
		gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins \
		popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomeprefix \
		gnomedesktop
USE_LIBTOOL=	yes
USE_SIZE=	yes
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

pre-install:
# required for PREFIX safeness, the dir might not exist under PREFIX
	@${MKDIR} ${PREFIX}/etc/gconf/

.if defined(WITH_MOZILLA_PLUGIN)
BUILD_DEPENDS+=	${X11BASE}/include/mozilla${HEADERS_SUFX}/plugin/npapi.h:${PORTSDIR}/www/mozilla-headers${HEADERS_SUFX} \
		${X11BASE}/lib/${MOZILLA}/mozilla-config:${PORTSDIR}/www/${MOZILLA}

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	${WITH_MOZILLA}
HEADERS_SUFX=	-devel
.else
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.endif
.endif

CONFIGURE_ENV+=	MOZILLA_CONFIG="${X11BASE}/lib/${MOZILLA}/mozilla-config"
PLIST_SUB+=	MOZILLA_PLUGIN=""
.else
CONFIGURE_ENV+=	MOZILLA_CONFIG="no"
PLIST_SUB+=	MOZILLA_PLUGIN="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mnautilus2}!=""
USE_GNOME+=	nautilus2
PLIST_SUB+=	GST_PLAYER_VIEW=""
.else
PLIST_SUB+=	GST_PLAYER_VIEW="@comment "
.endif

pre-everything::
.ifndef (WITH_MOZILLA_PLUGIN)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> Define WITH_MOZILLA_PLUGIN to compile the Mozilla plugin."
.endif

.include <bsd.port.post.mk>
