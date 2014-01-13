# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	quodlibet
PORTVERSION=	2.2
PORTREVISION=	7
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	A GTK+-based audio player written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USES=		gettext
USE_PYDISTUTILS=	yes
USE_DISPLAY=	yes
USE_GSTREAMER=	gconf good python

MAN1=		exfalso.1 quodlibet.1

OPTIONS_DEFINE=	FLAC MP3 AAC MUSEPACK OGG SPC SPEEX VORBIS WAVPACK DBUS REMOTE EXTENSIONS
SPC_DESC=	SPC (SNES ROM audio) support
SPEEX_DESC=	OGG/Speex audio support
REMOTE_DESC=	Enable remote playback
EXTENSIONS_DESC=	Enable extensions

OPTIONS_DEFAULT=	FLAC MP3 AAC MUSEPACK OGG SPC SPEEX VORBIS WAVPACK DBUS REMOTE

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOGG}
USE_GSTREAMER+=	ogg
.endif

.if ${PORT_OPTIONS:MVORBIS}
USE_GSTREAMER+=	vorbis
.endif

.if ${PORT_OPTIONS:MSPC}
USE_GSTREAMER+=	spc
.endif

.if ${PORT_OPTIONS:MSPEEX}
USE_GSTREAMER+=	speex
.endif

.if ${PORT_OPTIONS:MMP3}
USE_GSTREAMER+=	mp3
.endif

.if ${PORT_OPTIONS:MFLAC}
USE_GSTREAMER+=	flac
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	mpcdec.7:${PORTSDIR}/audio/musepack
USE_GSTREAMER+=	musepack
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
USE_GSTREAMER+=	wavpack
.endif

.if ${PORT_OPTIONS:MAAC}
LIB_DEPENDS+=	mp4v2.10:${PORTSDIR}/multimedia/mp4v2
USE_GSTREAMER+=	faad
.endif

.if ${PORT_OPTIONS:MDBUS}
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
.endif

.if ${PORT_OPTIONS:MREMOTE}
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/feedparser.py:${PORTSDIR}/textproc/py-feedparser
USE_GSTREAMER+=	gnomevfs
.endif

.if ${PORT_OPTIONS:MEXTENSIONS}
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
