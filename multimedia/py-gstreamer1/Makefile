# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer
DISTVERSION=	1.16.3
CATEGORIES=	multimedia python
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer python bindings

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gnome meson pkgconfig python:3.6+ tar:xz
USE_GNOME=	pygobject3
USE_PYTHON=	flavors py3kplist
USE_GSTREAMER1=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
BINARY_ALIAS=	python3=${PYTHON_VERSION}

post-install:
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
