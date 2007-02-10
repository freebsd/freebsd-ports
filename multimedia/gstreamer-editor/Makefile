# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-editor/Makefile,v 1.7 2006/09/10 00:52:59 mezz Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.8.0
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-editor/
PKGNAMESUFFIX=	-editor
DISTNAME=	gst-editor-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Provide View and Controller counterparts to GStreamer's Model

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_AUTOTOOLS=	libtool:15
USE_GSTREAMER80=	core
USE_BZIP2=	yes
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
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes

MAN1=		gst-editor.1 gst-inspect-gui.1 gst-launch-gui.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
