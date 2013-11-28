# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$
#    $MCom: ports/multimedia/py-gstreamer/Makefile,v 1.20 2008/07/26 17:21:38 marcus Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.10.22
PORTREVISION=	1
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python bindings for gstreamer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

USES=		gmake pathfix pkgconfig
USE_PYTHON=	-2.7
USE_BZIP2=	yes
USE_GNOME=	pygobject
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE} ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|DLFCN|dl|g' ${WRKSRC}/gst/__init__.py
	@${REINPLACE_CMD} -e 's|alsasink|osssink|g' -e 's|alsasrc|osssrc|g' \
		${WRKSRC}/gst/extend/jukebox.py \
		${WRKSRC}/common/m4/gst-default.m4
.for d in audio-controller.py decodebin.py mixer.py vumeter.py
	@${REINPLACE_CMD} -e 's|alsasink|osssink|g' -e 's|alsasrc|osssrc|g' \
		${WRKSRC}/examples/${d}
.endfor

post-install:
	${SETENV} PYTHON=${PYTHON_CMD} ${SH} ${WRKSRC}/py-compile --destdir ${STAGEDIR} \
		--basedir ${PYTHON_SITELIBDIR} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pygst.py
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gst-0.10/gst/*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-0.10/libgstpython.so

.include <bsd.port.mk>
