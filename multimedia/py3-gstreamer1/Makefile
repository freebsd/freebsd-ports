# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	1.12.3
CATEGORIES=	multimedia python
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer python 3 bindings

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gmake libtool localbase pathfix pkgconfig python:3.6+ tar:xz
USE_GNOME=	py3gobject3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
