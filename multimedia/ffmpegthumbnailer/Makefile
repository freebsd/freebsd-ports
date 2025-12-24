PORTNAME=	ffmpegthumbnailer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	multimedia graphics

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Lightweight video thumbnailer that can be used by file managers
WWW=		https://github.com/dirkvdb/ffmpegthumbnailer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libpng.so:graphics/png

USES=		cmake:testing compiler:c++14-lang gnome jpeg localbase \
		pkgconfig tar:bz2
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	dirkvdb
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_GIO
CMAKE_OFF=	ENABLE_TESTS
CMAKE_TESTING_ON=	ENABLE_TESTS

EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

OPTIONS_DEFINE=		AUDIO_THUMBNAILER THUMBNAILER
OPTIONS_DEFAULT=	AUDIO_THUMBNAILER THUMBNAILER
OPTIONS_SUB=		yes

AUDIO_THUMBNAILER_DESC=	Register as a system thumbnailer for audio files
THUMBNAILER_DESC=	Register as a system thumbnailer for video files

AUDIO_THUMBNAILER_CMAKE_BOOL=	ENABLE_AUDIO_THUMBNAILER
THUMBNAILER_CMAKE_BOOL=		ENABLE_THUMBNAILER

.include <bsd.port.mk>
