# New ports collection makefile for:	quodlibet
# Date created:			19 December 2005
# Whom:				Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	quodlibet
PORTVERSION=	0.15
CATEGORIES=	multimedia audio python
MASTER_SITES=	http://www.sacredchao.net/~piman/software/

MAINTAINER=	bh@izb.knu.ac.kr
COMMENT=	A GTK+-based audio player written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/ogg/_ogg.so:${PORTSDIR}/audio/py-ogg \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/ogg/_ogg.so:${PORTSDIR}/audio/py-ogg \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad

USE_PYTHON=	2.3+
USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GSTREAMER=	ogg vorbis mad

MAN1=		exfalso.1 quodlibet.1

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif

.if defined(WITH_EXTENSIONS)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/egg/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome-extras
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/egg/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome-extras
PLIST_SUB+=	EXTENSIONS:=""
.else
PLIST_SUB+=	EXTENSIONS:="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		is unsupported on FreeBSD 4.x
.endif

do-configure:
	@${PYTHON_CMD} ${WRKSRC}/check.py

do-build:
.if defined(WITH_EXTENSIONS)
	@cd ${WRKSRC} && ${GMAKE} extensions
.else
	@${ECHO_MSG} "Build done."
.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/applications

post-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/plugins
	@${INSTALL_DATA} ${FILESDIR}/qlscrobbler.py ${PREFIX}/lib/${PORTNAME}/plugins

.include <bsd.port.post.mk>
