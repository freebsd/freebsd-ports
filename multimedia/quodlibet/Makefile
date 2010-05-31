# New ports collection makefile for:	quodlibet
# Date created:			19 December 2005
# Whom:				Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	quodlibet
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	A GTK+-based audio player written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen

USE_PYTHON=	2.4+
USE_GNOME=	pygtk2
USE_GETTEXT=	yes
USE_PYDISTUTILS=	yes
USE_DISPLAY=	yes
USE_GSTREAMER=	gconf good python

MAN1=		exfalso.1 quodlibet.1

OPTIONS=	FLAC "Flac audio support" on
OPTIONS+=	MP3 "MP3 audio support" on
OPTIONS+=	MPEG4IP "AAC/mp4 support with MPEG4IP" on
OPTIONS+=	MUSEPACK "Musepack (MPC, musicpd, libmpcdec) support" on
OPTIONS+=	OGG "OGG multimedia container support" on
OPTIONS+=	SPC "SPC (SNES ROM audio) support" on
OPTIONS+=	SPEEX "OGG/Speex audio support" on
OPTIONS+=	VORBIS "OGG/Vorbis audio support" on
OPTIONS+=	WAVPACK "Wavpack support" on
OPTIONS+=	DBUS "Enable dbus (iPod, storage) support" on
OPTIONS+=	REMOTE "Enable remote playback" on
OPTIONS+=	EXTENSIONS "Enable extensions" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OGG)
USE_GSTREAMER+=	ogg
.endif

.if !defined(WITHOUT_VORBIS)
USE_GSTREAMER+=	vorbis
.endif

.if !defined(WITHOUT_SPC)
USE_GSTREAMER+=	spc
.endif

.if !defined(WITHOUT_SPEEX)
USE_GSTREAMER+=	speex
.endif

.if !defined(WITHOUT_MP3)
USE_GSTREAMER+=	mp3
.endif

.if !defined(WITHOUT_FLAC)
USE_GSTREAMER+=	flac
.endif

.if !defined(WITHOUT_MUSEPACK) || !defined(WITHOUT_WAVPACK) \
		|| !defined(WITHOUT_MPEG4IP)
BUILD_DEPENDS+=	${PYCTYPES}
RUN_DEPENDS+=	${PYCTYPES}
.endif

.if !defined(WITHOUT_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
USE_GSTREAMER+=	musepack
.endif

.if !defined(WITHOUT_WAVPACK)
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
USE_GSTREAMER+=	wavpack
.endif

.if !defined(WITHOUT_MPEG4IP)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
USE_GSTREAMER+=	faad
.endif

.if !defined(WITHOUT_DBUS)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
.endif

.if !defined(WITHOUT_REMOTE)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
USE_GSTREAMER+=	gnomevfs
.endif

.if defined(WITH_EXTENSIONS)
USE_GNOME+=	pygnomeextras
PLIST_SUB+=	EXTENSIONS=""
.else
PLIST_SUB+=	EXTENSIONS="@comment "
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
