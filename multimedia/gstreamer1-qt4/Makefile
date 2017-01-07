# $FreeBSD$

PORTNAME=	gstreamer1-qt
PORTVERSION=	1.2.0
PORTREVISION?=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/qt-gstreamer/
PKGNAMESUFFIX?=	4
DISTNAME=	qt-gstreamer-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ${PKGNAMESUFFIX} bindings for GStreamer 1.x multimedia library

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgstreamer-1.0.so:multimedia/gstreamer1

CONFLICTS_INSTALL=	gstreamer-qt${PKGNAMESUFFIX}-*

USES=		bison cmake:outsource pathfix pkgconfig tar:xz
USE_GSTREAMER1=	yes

USE_GL=		gl
USE_GNOME=	glib20
.  if ${PKGNAMESUFFIX:M4}
USE_QT4=	corelib gui opengl declarative script \
		qmake_build moc_build rcc_build uic_build qtestlib_build
PLIST_SUB=	QT4_ONLY="" QT5_ONLY="@comment "
.  else
USE_QT5=	buildtools_build qmake_build core gui network opengl \
		qml quick testlib widgets
QTVER_SUFFIX=	5
PLIST_SUB=	QT4_ONLY="@comment " QT5_ONLY=""
.  endif

USE_LDCONFIG=	yes
CMAKE_ARGS=	-DUSE_GST_PLUGIN_DIR=off \
		-DUSE_QT_PLUGIN_DIR=off \
		-DQT_VERSION=${PKGNAMESUFFIX}

PLIST_SUB+=	SHLIB_VER="${PORTVERSION}" \
		QTVER_SUFFIX="${QTVER_SUFFIX}"

.include <bsd.port.mk>
