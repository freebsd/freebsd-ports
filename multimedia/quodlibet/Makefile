# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	quodlibet
PORTVERSION=	2.6.3
PORTREVISION=	2
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	http://bitbucket.org/lazka/${PORTNAME}-files/raw/default/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	GTK+-based audio player written in Python

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen

USE_PYTHON=	distutils autoplist
USE_GNOME=	pygtk2
USES=		display gettext python
PYDISTUTILS_INSTALLNOSINGLE=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-pydistutils

USE_GSTREAMER=	gconf good python

OPTIONS_DEFINE=	FLAC MP3 AAC MUSEPACK OGG SPC SPEEX VORBIS WAVPACK DBUS REMOTE EXTENSIONS

OPTIONS_DEFAULT=	FLAC MP3 AAC MUSEPACK OGG SPC SPEEX VORBIS WAVPACK DBUS REMOTE

SPC_DESC=	SPC (SNES ROM audio) support on i386
SPEEX_DESC=	OGG/Speex audio support
REMOTE_DESC=	Enable remote playback
EXTENSIONS_DESC=	Enable extensions

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOGG}
USE_GSTREAMER+=	ogg
.endif

.if ${PORT_OPTIONS:MVORBIS}
USE_GSTREAMER+=	vorbis
.endif

.if ${PORT_OPTIONS:MSPC} && ${ARCH} == i386
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
LIB_DEPENDS+=	libmpcdec.so:${PORTSDIR}/audio/musepack
USE_GSTREAMER+=	musepack
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	libwavpack.so:${PORTSDIR}/audio/wavpack
USE_GSTREAMER+=	wavpack
.endif

.if ${PORT_OPTIONS:MAAC}
LIB_DEPENDS+=	libmp4v2.so:${PORTSDIR}/multimedia/mp4v2
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
.endif

.include <bsd.port.mk>
