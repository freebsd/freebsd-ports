# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	1.8.0
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

USES=		gmake libtool pathfix pkgconfig python:3 tar:xz
USE_GNOME=	py3gobject3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>
 
.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

PLIST_SUB+=	PYOEXTENSION=${PYOEXTENSION} \
		PYVER=${PYTHON_VER:S/.//}

.include <bsd.port.post.mk>
