# $FreeBSD$

PORTNAME=	gstreamer1
PORTVERSION=	1.2.0
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/qt-gstreamer/
PKGNAMESUFFIX=	-${FLAVOR}
DISTNAME=	qt-gstreamer-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt ${FLAVOR:C/qt//} bindings for GStreamer 1.x multimedia library

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgstreamer-1.0.so:multimedia/gstreamer1

FLAVORS=	qt4 qt5
FLAVOR?=	${FLAVORS:[1]}

CONFLICTS_INSTALL=	gstreamer${PKGNAMESUFFIX}-*

USES=		bison cmake:outsource pathfix pkgconfig tar:xz
USE_GSTREAMER1=	yes

USE_GL=		gl
USE_GNOME=	glib20

USE_LDCONFIG=	yes
CMAKE_OFF=	USE_GST_PLUGIN_DIR USE_QT_PLUGIN_DIR
CMAKE_ARGS=	-DQT_VERSION=${FLAVOR:C/qt//}

.  if ${FLAVOR} == qt4
USES+=		qt:4
USE_QT=		corelib gui opengl declarative script \
		qmake_build moc_build rcc_build uic_build qtestlib_build
PLIST_SUB=	QT4_ONLY="" QT5_ONLY="@comment "
.  else
USES+=		qt:5
USE_QT=		buildtools_build qmake_build core gui network opengl \
		qml quick testlib widgets
QTVER_SUFFIX=	5
PLIST_SUB=	QT4_ONLY="@comment " QT5_ONLY=""
.  endif

PLIST_SUB+=	SHLIB_VER="${PORTVERSION}" \
		QTVER_SUFFIX="${QTVER_SUFFIX}"

.include <bsd.port.mk>
