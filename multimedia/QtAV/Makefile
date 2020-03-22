# $FreeBSD$

PORTNAME=		QtAV
DISTVERSIONPREFIX=	v
DISTVERSION=		1.13.0
PORTREVISION=		2
CATEGORIES=		multimedia
DIST_SUBDIR=		KDE

PATCH_SITES=		https://github.com/wang-bin/QtAV/commit/
PATCHFILES=		5abba7f0505e75fceabd4dd8992a7e02bb149d64.patch:-p1

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Cross-platform multimedia framwork based on Qt and ffmpeg

LICENSE=		LGPL21+
LICENSE_FILE=		${WRKSRC}/lgpl-2.1.txt

LIB_DEPENDS=		libass.so:multimedia/libass \
			libavcodec.so:multimedia/ffmpeg

USES=			compiler:c++11-lang gl qmake:outsource qt:5 xorg
USE_GL=			gl
USE_QT=			core declarative gui network opengl sql widgets \
			buildtools_build qmake_build
USE_XORG=		x11 xext xv

OPTIONS_DEFINE=		OPENAL UCHARDET VAAPI PULSEAUDIO
OPTIONS_DEFAULT=	OPENAL UCHARDET VAAPI
OPTIONS_SUB=		yes

OPENAL_LIB_DEPENDS=	libopenal.so:audio/openal-soft
OPENAL_QMAKE_OFF=	CONFIG+=no-openal

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_QMAKE_OFF=	CONFIG+=no-pulseaudio

UCHARDET_DESC=		Guess subtitle encoding via uchardet
UCHARDET_LIB_DEPENDS=	libuchardet.so:textproc/uchardet
UCHARDET_QMAKE_OFF=	CONFIG+=no-uchardet

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_QMAKE_OFF=	CONFIG+=no-vaapi

PLIST_SUB=		QT_VERSION="${_QT_VERSION}"

USE_GITHUB=		yes
GH_ACCOUNT=		wang-bin

# The examples are GLPv3 licencensed and have too generic names, like 'Player',
# so don't install them.
QMAKE_ARGS=		CONFIG+=no-examples

.include <bsd.port.mk>
