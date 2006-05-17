# New ports collection makefile for:	gstreamer-python
# Date created:		Fri Apr  9 16:24:13 CEST 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.4
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for gstreamer

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2 \
		gnomehack \
		pkgconfig
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}"

post-patch:
	@${REINPLACE_CMD} -e 's|DLFCN|dl|g' ${WRKSRC}/gst/__init__.py

.include <bsd.port.mk>
