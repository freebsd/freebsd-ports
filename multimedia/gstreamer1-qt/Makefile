# $FreeBSD$

PORTNAME=	gstreamer1
PORTVERSION=	1.2.0
PORTREVISION=	23
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/qt-gstreamer/
PKGNAMESUFFIX=	-qt5
DISTNAME=	qt-gstreamer-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ${FLAVOR:C/qt//} bindings for GStreamer 1.x multimedia library

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgstreamer-1.0.so:multimedia/gstreamer1

CONFLICTS_INSTALL=	gstreamer${PKGNAMESUFFIX}-*

USES=		bison cmake compiler:c++11-lang gl gnome pathfix pkgconfig qt:5 tar:xz
USE_GSTREAMER1=	yes
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		buildtools_build qmake_build core declarative gui network opengl \
		testlib widgets

USE_LDCONFIG=	yes
CMAKE_OFF=	USE_GST_PLUGIN_DIR USE_QT_PLUGIN_DIR
CMAKE_ARGS=	-DQT_VERSION=5

PLIST_SUB=	SHLIB_VER="${PORTVERSION}"

.include <bsd.port.mk>
