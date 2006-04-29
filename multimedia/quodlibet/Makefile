# New ports collection makefile for:	quodlibet
# Date created:			19 December 2005
# Whom:				Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	quodlibet
PORTVERSION=	0.17.1
PORTREVISION=	1
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	http://www.sacredchao.net/~piman/software/

MAINTAINER=	changbom.yoon@gmail.com
COMMENT=	A GTK+-based audio player written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer80
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer80

USE_PYTHON=	2.3+
USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GSTREAMER80=	gconf

MAN1=		exfalso.1 quodlibet.1

# Supported formats: ogg vorbis mad flac remote
QUODLIBET_FORMATS?=	ogg vorbis mad flac remote
.for format in ${QUODLIBET_FORMATS}
WANT_QUODLIBET_${format:U}=	yes
.endfor

.if defined(WANT_QUODLIBET_OGG)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/_ogg.so:${PORTSDIR}/audio/py-ogg
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/_ogg.so:${PORTSDIR}/audio/py-ogg
USE_GSTREAMER80+=	ogg
.endif

.if defined(WANT_QUODLIBET_VORBIS)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
USE_GSTREAMER80+=	vorbis
.endif

.if defined(WANT_QUODLIBET_MAD)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
RUN_DEPNDS+=	${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
USE_GSTREAMER80+=	mad
.endif

.if defined(WANT_QUODLIBET_FLAC)
USE_GSTREAMER80+=	flac
.endif

.if defined(WANT_QUODLIBET_REMOTE)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
USE_GSTREAMER80+=	gnomevfs
.endif

.if defined(WITH_EXTENSIONS)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/egg/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome-extras
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/egg/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome-extras
PLIST_SUB+=	EXTENSIONS:=""
.else
PLIST_SUB+=	EXTENSIONS:="@comment "
.endif

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		is unsupported on FreeBSD 4.x
.endif

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
BROKEN=		"Does not configure"
.endif

do-configure:
	@${PYTHON_CMD} ${WRKSRC}/check.py

do-build:
.if defined(WITH_EXTENSIONS)
	@cd ${WRKSRC}/po && ${GMAKE} po
	@cd ${WRKSRC} && ${GMAKE} extensions
.else
	@cd ${WRKSRC}/po && ${GMAKE} po
.endif

pre-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/applications

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/plugins
	@${INSTALL_DATA} ${FILESDIR}/qlscrobbler.py ${PREFIX}/share/${PORTNAME}/plugins

.include <bsd.port.post.mk>
