PORTNAME=	gstreamer
DISTVERSION=	${_GST_VERSION}
CATEGORIES=	multimedia python
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer python bindings
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gnome gstreamer meson pkgconfig python tar:xz
CPE_VENDOR=	${PORTNAME}_project
USE_GNOME=	pygobject3
USE_GSTREAMER=	bad rtsp-server webrtc
USE_PYTHON=	flavors

BINARY_ALIAS=	python3=${PYTHON_VERSION}
PORTSCOUT=	limitw:1,even

post-install:
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
