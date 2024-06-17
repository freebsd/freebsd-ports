PORTNAME=	PackageKit-Qt
PORTVERSION=	1.1.2
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	https://www.freedesktop.org/software/PackageKit/releases/
PKGNAMESUFFIX=	${FLAVOR:S/qt//}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	DBUS packaging abstraction layer (Qt bindings)
WWW=		https://www.freedesktop.org/software/PackageKit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/dbus-1/interfaces/org.freedesktop.PackageKit.xml:ports-mgmt/packagekit

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake cpe pathfix qt:${FLAVOR:S/qt//} tar:xz
CPE_VENDOR=	packagekit_project
USE_LDCONFIG=	yes
_USE_QT_qt5=	core dbus buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

_CMAKE_ARGS_qt5=	-DBUILD_WITH_QT6:BOOL=FALSE
_CMAKE_ARGS_qt6=	-DBUILD_WITH_QT6:BOOL=TRUE
CMAKE_ARGS=		${_CMAKE_ARGS_${FLAVOR}}

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//}

.include <bsd.port.mk>
