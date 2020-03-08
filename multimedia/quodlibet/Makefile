# Created by: Byung-Hee HWANG <bh@izb.knu.ac.kr>
# $FreeBSD$

PORTNAME=	quodlibet
PORTVERSION=	3.6.2
PORTREVISION=	5
CATEGORIES=	multimedia audio python gnome
MASTER_SITES=	http://bitbucket.org/lazka/${PORTNAME}-files/raw/default/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	GTK+-based audio player written in Python

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0.4:audio/py-musicbrainzngs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		desktop-file-utils display gettext gnome python:2.7 shebangfix
SHEBANG_FILES=	exfalso.py operon.py quodlibet.py
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtk30 intltool pygobject3
PYDISTUTILS_INSTALLNOSINGLE=	yes
NO_ARCH=	yes

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

DBUS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

REMOTE_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR}
REMOTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR}

.include <bsd.port.mk>
