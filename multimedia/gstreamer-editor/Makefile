# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-editor/
PKGNAMESUFFIX=	-editor
DISTNAME=	gst-editor-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Provide View and Controller counterparts to GStreamer's Model

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gstreamer-0.8.4:${PORTSDIR}/multimedia/gstreamer \
		popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	gst-visualise-0.8:${PORTSDIR}/multimedia/gstreamer-plugins

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix \
		gconf2 \
		libglade2 \
		libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG}
PLIST_SUB=	\
	VERSION="${PORTVERSION}"
INSTALLS_SHLIB=	yes

MAN1=		gst-editor.1 gst-inspect-gui.1 gst-launch-gui.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"

.include <bsd.port.mk>
