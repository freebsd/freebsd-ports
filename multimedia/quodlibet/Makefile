# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	quodlibet
PORTVERSION=	3.6.2
PORTREVISION=	2
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	http://bitbucket.org/lazka/${PORTNAME}-files/raw/default/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	GTK+-based audio player written in Python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0.4:audio/py-musicbrainzngs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${FLAVOR} \
		${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USE_PYTHON=	distutils autoplist
USE_GNOME=	gtk30 intltool pygobject3
USES=		desktop-file-utils display gettext python:2.7
PYDISTUTILS_INSTALLNOSINGLE=	yes

USE_GSTREAMER1=	good

OPTIONS_DEFINE=		AAC DBUS FLAC MP3 OGG REMOTE SPEEX VORBIS WAVPACK
OPTIONS_DEFINE_i386=	SPC
OPTIONS_DEFAULT=	AAC DBUS FLAC MP3 OGG REMOTE SPEEX VORBIS WAVPACK
OPTIONS_DEFAULT_i386=	SPC

SPC_DESC=	SPC (SNES ROM audio) support on i386
SPEEX_DESC=	OGG/Speex audio support
REMOTE_DESC=	Enable remote playback

OGG_USE=	GSTREAMER1=ogg
VORBIS_USE=	GSTREAMER1=vorbis
SPC_USE=	GSTREAMER1=spc
SPEEX_USE=	GSTREAMER1=speex
MP3_USE=	GSTREAMER1=mpg123
FLAC_USE=	GSTREAMER1=flac

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_USE=		GSTREAMER1=wavpack

AAC_LIB_DEPENDS=	libmp4v2.so:multimedia/mp4v2
AAC_USE=		GSTREAMER1=faad

DBUS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${FLAVOR}

REMOTE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${FLAVOR}
REMOTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${FLAVOR}

.include <bsd.port.mk>
