PORTNAME=	olive
DISTVERSION=	0.1.2-20230320
PORTREVISION=	5
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-video-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non-linear video editor
WWW=		https://olivevideoeditor.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	frei0r>0:graphics/frei0r
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libImath-3_1.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR-3_1.so:graphics/openexr \
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
GH_TAGNAME=	8ca1672
GH_TUPLE=	olive-editor:core:2777928:core/ext/core \
		KDAB:KDDockWidgets:8d2d0a5:KDDockWidgets/ext/KDDockWidgets

PORTSCOUT=	limit:^.*[1-9]\..* # prevent tags like 20181223

CONFLICTS_BUILD=	opentimelineio # fails to build with the opentimelineio optional dependency, see https://github.com/olive-editor/olive/issues/2201

.include <bsd.port.mk>
