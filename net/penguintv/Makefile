# New ports collection makefile for:	PenguinTV
# Date created:				14 March 2006
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	PenguinTV
PORTVERSION=	4.0.0
PORTREVISION=	3
CATEGORIES=	net audio multimedia
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/4.0

MAINTAINER=	edwin@mavetju.org
COMMENT=	Graphical RSS feed reader with incorperated playback functions - development version

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite21 \
		${PYTHON_SITELIBDIR}/pycurl.so:${PORTSDIR}/ftp/py-curl \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		${PYXML} \
		${PYTHON_SITELIBDIR}/Pyrex/__init__.py:${PORTSDIR}/devel/pyrex \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/PenguinTV-${PORTVERSION}

OPTIONS=	PYLUCENE "Use Lucene search engine" ON \
		GSTREAMER "Use GStreamer engine" ON

USE_GNOME=	pygnomeextras pygnome2
USE_PYTHON=	yes
USE_GECKO=	libxul
USE_DISPLAY=	yes

CONFLICTS=	PenguinTV-devel-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer
.endif

.if defined(WITHOUT_PYLUCENE)
#BROKEN=		Cannot be run without PyLucene
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/lucene/_lucene.so:${PORTSDIR}/textproc/py-lucene
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," \
		${WRKSRC}/penguintv/utils.py

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install

.include <bsd.port.post.mk>
