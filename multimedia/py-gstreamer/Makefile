# New ports collection makefile for:	gstreamer-python
# Date created:		Fri Apr  9 16:24:13 CEST 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#    $MCom: ports/multimedia/py-gstreamer/Makefile,v 1.20 2008/07/26 17:21:38 marcus Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.15
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A set of Python bindings for gstreamer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2 gnomehack pkgconfig
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} -e 's|DLFCN|dl|g' ${WRKSRC}/gst/__init__.py
.for d in audio-controller.py decodebin.py pipeline-tester mixer.py vumeter.py
	@${REINPLACE_CMD} -e 's|alsasink|osssink|g' -e 's|alsasrc|osssink|g' \
		${WRKSRC}/examples/${d}
.endfor

post-install:
	@cd ${PYTHONPREFIX_SITELIBDIR} && ${PYTHON_CMD} -OOOO -c 'import pygst' && \
		${PYTHON_CMD} -c 'import pygst'

.include <bsd.port.mk>
