# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.5.0
CATEGORIES=	multimedia audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-player
DISTNAME=	gst-player-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Simple yet functional mediaplayer written with GStreamer

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.200:${PORTSDIR}/devel/glib20 \
		gconf-2.5:${PORTSDIR}/devel/gconf2 \
		glade-2.0.0:${PORTSDIR}/devel/libglade2 \
		gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui \
		gstreamer-0.6.0:${PORTSDIR}/multimedia/gstreamer \
		gstplay-0.6.0:${PORTSDIR}/multimedia/gstreamer-plugins \
		gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		pango-1.0.200:${PORTSDIR}/x11-toolkits/pango \
		popt.0:${PORTSDIR}/devel/popt \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG}
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

.include <bsd.port.mk>
