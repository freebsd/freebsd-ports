PORTNAME=	olive
DISTVERSION=	0.2.0
DISTVERSIONSUFFIX=	-nightly
PORTREVISION=	5
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-video-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non-linear video editor
WWW=		https://olivevideoeditor.org/ \
		https://github.com/olive-editor/olive

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_armv7=	compilation fails: error: unknown type name '__m128'
BROKEN_i386=	compilation fails, see https://github.com/olive-editor/olive/issues/2364
BROKEN_powerpc=compilation fails, see https://github.com/olive-editor/olive/issues/2364

BUILD_DEPENDS=	frei0r>0:graphics/frei0r
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libportaudio.so:audio/portaudio \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	frei0r>0:graphics/frei0r
#		libopentimelineio.so:multimedia/opentimelineio

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig qt:6 shared-mime-info
USE_QT=		base multimedia svg \
		tools:build
USE_GL=		gl

CMAKE_ON=	BUILD_QT6

USE_GITHUB=	yes
GH_ACCOUNT=	olive-editor
GH_TUPLE=	olive-editor:core:2777928:core/ext/core \
		KDAB:KDDockWidgets:8d2d0a5:KDDockWidgets/ext/KDDockWidgets

CXXFLAGS_i386=	-msse -msse2

PORTSCOUT=	limit:^.*[1-9]\..* # prevent tags like 20181223

CONFLICTS_BUILD=	opentimelineio # fails to build with the opentimelineio optional dependency, see https://github.com/olive-editor/olive/issues/2201

.include <bsd.port.mk>
