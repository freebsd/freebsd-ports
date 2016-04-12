# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	quodlibet
PORTVERSION=	2.6.3
PORTREVISION=	3
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	http://bitbucket.org/lazka/${PORTNAME}-files/raw/default/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	GTK+-based audio player written in Python

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen

USE_PYTHON=	distutils autoplist
USE_GNOME=	intltool pygtk2
USES=		display gettext python
PYDISTUTILS_INSTALLNOSINGLE=	yes

EXTRA_PATCHES=	${FILESDIR}/extra-patch-pydistutils

USE_GSTREAMER=	gconf good python

OPTIONS_DEFINE=		FLAC MP3 AAC MUSEPACK OGG SPEEX VORBIS WAVPACK DBUS REMOTE
OPTIONS_DEFINE_i386=	SPC
OPTIONS_DEFAULT=	FLAC MP3 AAC MUSEPACK OGG SPEEX VORBIS WAVPACK DBUS REMOTE
OPTIONS_DEFAULT_i386=	SPC

SPC_DESC=	SPC (SNES ROM audio) support on i386
SPEEX_DESC=	OGG/Speex audio support
REMOTE_DESC=	Enable remote playback

OGG_USE=	GSTREAMER=ogg
VORBIS_USE=	GSTREAMER=vorbis
SPC_USE=	GSTREAMER=spc
SPEEX_USE=	GSTREAMER=speex
MP3_USE=	GSTREAMER=mp3
FLAC_USE=	GSTREAMER=flac

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack
MUSEPACK_USE=		GSTREAMER=musepack

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_USE=		GSTREAMER=wavpack

AAC_LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2
AAC_USE=		GSTREAMER=faad

DBUS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus

REMOTE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser
REMOTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser
REMOTE_USE=		GSTREAMER=gnomevfs

.include <bsd.port.mk>
