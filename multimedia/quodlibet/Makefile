# New ports collection makefile for:	quodlibet
# Date created:			19 December 2005
# Whom:				Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	quodlibet
PORTVERSION=	0.21.1
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	http://www.sacredchao.net/~piman/software/

MAINTAINER=	changbom.yoon@gmail.com
COMMENT=	A GTK+-based audio player written in Python

BROKEN=		fails to install/deinstall cleanly

INITIAL_DEP=	${PYTHON_SITELIBDIR}/gst-0.10/gst/__init__.py:${PORTSDIR}/multimedia/py-gstreamer \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
BUILD_DEPENDS=	${INITIAL_DEP}
RUN_DEPENDS=	${INITIAL_DEP}

USE_PYTHON=	2.3+
USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GSTREAMER=	yes
USE_GSTREAMER+=	gconf

MAN1=		exfalso.1 quodlibet.1

QUODLIBET_FORMATS?=	ogg vorbis mp3 flac musepack wavpack aac remote
.for format in ${QUODLIBET_FORMATS}
WANT_QUODLIBET_${format:U}=	yes
.endfor

.if defined(WANT_QUODLIBET_OGG)
USE_GSTREAMER+=	ogg
.endif

.if defined(WANT_QUODLIBET_VORBIS)
USE_GSTREAMER+=	vorbis
.endif

.if defined(WANT_QUODLIBET_MP3)
USE_GSTREAMER+=	mad
.endif

.if defined(WANT_QUODLIBET_FLAC)
USE_GSTREAMER+=	flac
.endif

.if defined(WANT_QUODLIBET_MUSEPACK) || defined(WANT_QUODLIBET_WAVPACK) \
    || defined(WANT_QUODLIBET_AAC)
CTYPES_DEP=	${PYTHON_SITELIBDIR}/ctypes/__init__.py:${PORTSDIR}/devel/py-ctypes
BUILD_DEPENDS+=	${CTYPES_DEP}
RUN_DEPENDS+=	${CTYPES_DEP}
.endif

.if defined(WANT_QUODLIBET_MUSEPACK)
USE_GSTREAMER+=	musepack
.endif

.if defined(WANT_QUODLIBET_WAVPACK)
USE_GSTREAMER+=	wavpack
.endif

.if defined(WANT_QUODLIBET_AAC)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
USE_GSTREAMER+=	faad
.endif

.if defined(WANT_QUODLIBET_REMOTE)
FEEDPARSER_DEP=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
BUILD_DEPENDS+=	${FEEDPARSER_DEP}
RUN_DEPENDS+=	${FEEDPARSER_DEP}
USE_GSTREAMER+=	gnomevfs
.endif

.if defined(WITH_EXTENSIONS)
EXTRAS_DEP=	${PYTHON_SITELIBDIR}/gtk-2.0/egg/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome-extras
BUILD_DEPENDS+=	${EXTRAS_DEP}
RUN_DEPENDS+=	${EXTRAS_DEP}
PLIST_SUB+=	EXTENSIONS=""
.else
PLIST_SUB+=	EXTENSIONS="@comment "
.endif

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	is unsupported on FreeBSD 4.x
.endif

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
BROKEN= Does not configure
.endif

do-configure:
	@${PYTHON_CMD} ${WRKSRC}/check.py

do-build:
	@cd ${WRKSRC}/po && ${GMAKE} po
.if defined(WITH_EXTENSIONS)
	@cd ${WRKSRC} && ${GMAKE} extensions
.endif

pre-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/applications

post-install:
	@${MKDIR} ${DATADIR}/plugins
	@${MKDIR} ${DATADIR}/plugins/events
	@${INSTALL_DATA} ${FILESDIR}/qlscrobbler.py ${DATADIR}/plugins/events

.include <bsd.port.post.mk>
