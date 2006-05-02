# New ports collection makefile for:	PenguinTV-devel
# Date created:				14 March 2006
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$

PORTNAME=	PenguinTV
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	net audio multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	penguintv
PKGNAMESUFFIX=	-devel

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

USE_GNOME=	pygnomeextras pygnome2
USE_PYTHON=	yes

CONFLICTS=	PenguinTV-1.*

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install

.include <bsd.port.mk>
