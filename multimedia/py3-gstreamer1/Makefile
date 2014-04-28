# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/py3-gstreamer1/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	gstreamer1
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	multimedia python gnome
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python3 bindings for gstreamer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pathfix pkgconfig tar:bzip2
USE_GNOME=	py3gobject3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	3
PLIST_SUB=	VERSION="${GST_VERSION}" PYTVER=${PYTHON_VER:S/.//}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE} ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|import _gi_gst|from . import _gi_gst|g' \
		${WRKSRC}/gi/overrides/Gst.py

.include <bsd.port.mk>
