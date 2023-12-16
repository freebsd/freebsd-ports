PORTNAME=	polkit-qt-1
DISTVERSION=	0.175.0
CATEGORIES=	sysutils
MASTER_SITES=	KDE/unstable/${PORTNAME}/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt wrapper around Polkit libraries
WWW=		https://projects.kde.org/projects/kdesupport/polkit-qt-1

LICENSE=	LGPL21

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit

USES=		cmake compiler:c++11-lang gnome pkgconfig qt:${FLAVOR:C/qt//} \
		tar:xz
USE_GNOME=	glib20
USE_QT=		${_USE_QT_${FLAVOR}}
CMAKE_OFF=	BUILD_EXAMPLES BUILD_TEST
CMAKE_ARGS=	-DQT_MAJOR_VERSION=${FLAVOR:C/qt//}
_USE_QT_qt5=	core dbus gui widgets buildtools:build qmake:build
_USE_QT_qt6=	base

USE_LDCONFIG=	yes
PLIST_SUB=	QT_VER=${FLAVOR:C/qt//}

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_DESTINATION}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
