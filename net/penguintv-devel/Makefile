# New ports collection makefile for:	PenguinTV-devel
# Date created:				14 March 2006
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	PenguinTV
PORTVERSION=	2.80
CATEGORIES=	net audio multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	penguintv
PKGNAMESUFFIX=	-devel
WRKSRC=		${WRKDIR}/PenguinTV-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Graphical RSS feed reader with incorperated playback functions - development version

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite21 \
		${PYTHON_SITELIBDIR}/pycurl.so:${PORTSDIR}/ftp/py-curl \
		${PYXML}
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+= Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	MOZILLA	"Use Mozilla rendered (experimental)" OFF \
		PYLUCENE "Use Lucene search engine" ON \
		GSTREAMER "Use GStreamer engine" ON

USE_GNOME=	pygnomeextras pygnome2
USE_PYTHON=	yes

CONFLICTS=	PenguinTV-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_GSTREAMER)
RUN_DEPENDS+=	${LOCALBASE}/lib/python2.4/site-packages/pygst.py:${PORTSDIR}/multimedia/py-gstreamer
.endif

.if defined(WITHOUT_PYLUCENE)
#BROKEN=		Cannot be run without PyLucene
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/python2.4/site-packages/PyLucene.py:${PORTSDIR}/textproc/py-lucene
.endif

.if defined(WITH_MOZILLA)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/Pyrex/__init__.py:${PORTSDIR}/devel/pyrex \
		mozilla-config:${PORTSDIR}/www/mozilla
PLIST_SUB+=	WITH_MOZILLA=""
.else
PLIST_SUB+=	WITH_MOZILLA="@comment "
.endif

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install

.include <bsd.port.post.mk>
