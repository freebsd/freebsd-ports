PORTNAME=	olive
DISTVERSION=	0.2.0
DISTVERSIONSUFFIX=	-nightly
PORTREVISION=	3
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-video-editor

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	311eeb72944f93f873d1cd1784ee2bf423e1e7c2.patch:-p1 # https://github.com/olive-editor/olive/pull/2294, OpenColorIO 2.3 compatibility

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non-linear video editor
WWW=		https://olivevideoeditor.org/ \
		https://github.com/olive-editor/olive

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error: unknown type name '__m128'
BROKEN_i386=	compilation fails, see https://github.com/olive-editor/olive/issues/2364
BROKEN_powerpc=	compilation fails, see https://github.com/olive-editor/olive/issues/2364

BUILD_DEPENDS=	frei0r>0:graphics/frei0r
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libportaudio.so:audio/portaudio
RUN_DEPENDS=	frei0r>0:graphics/frei0r
#		libopentimelineio.so:multimedia/opentimelineio

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig qt:5 shared-mime-info
USE_QT=		concurrent core dbus gui multimedia network opengl svg widgets x11extras \
		buildtools:build linguisttools:build qmake:build testlib:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	olive-editor
GH_TUPLE=	olive-editor:core:2777928:core/ext/core \
		KDAB:KDDockWidgets:8d2d0a5:KDDockWidgets/ext/KDDockWidgets

CXXFLAGS_i386=	-msse -msse2

PORTSCOUT=	limit:^.*[1-9]\..* # prevent tags like 20181223

CONFLICTS_BUILD=	opentimelineio # fails to build with the opentimelineio optional dependency, see https://github.com/olive-editor/olive/issues/2201

.include <bsd.port.mk>
