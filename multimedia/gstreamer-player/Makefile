# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	multimedia audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-player
DISTNAME=	gst-player-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Simple yet functional mediaplayer written with GStreamer

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gstreamer-0.6.1:${PORTSDIR}/multimedia/gstreamer \
		gstplay-0.6.1:${PORTSDIR}/multimedia/gstreamer-plugins \
		popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix \
		gconf2 \
		libglade2 \
		libgnomeui
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG}
WANT_GNOME=	yes
PLIST_SUB=	\
	VERSION="${PORTVERSION}" \
	SHLIB_VERSION="${SHLIB_VERSION}"
INSTALLS_SHLIB=	yes

MAN1=		gst-player.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"

# library minor number
SHLIB_VERSION=	0

pre-install:
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
