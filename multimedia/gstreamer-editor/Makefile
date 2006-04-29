# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-editor/
PKGNAMESUFFIX=	-editor
DISTNAME=	gst-editor-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide View and Controller counterparts to GStreamer's Model

LIB_DEPENDS=	gstreamer-0.8.5:${PORTSDIR}/multimedia/gstreamer80 \
		popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	gst-visualise-0.8:${PORTSDIR}/multimedia/gstreamer-plugins80

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack \
		gnomehier \
		gnomeprefix \
		pkgconfig \
		gconf2 \
		libglade2 \
		libgnomeui
PLIST_SUB=	\
	VERSION="${PORTVERSION}"
INSTALLS_SHLIB=	yes
INSTALLS_OMF=	yes

MAN1=		gst-editor.1 gst-inspect-gui.1 gst-launch-gui.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
