PORTNAME=	PackageKit-Qt
PORTVERSION=	1.1.1
PORTREVISION=	2
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

USES=		cmake cpe qt:${FLAVOR:S/qt//} tar:xz
_CMAKE_ARGS_qt5=	-DBUILD_WITH_QT6:BOOL=FALSE
_CMAKE_ARGS_qt6=	-DBUILD_WITH_QT6:BOOL=TRUE
CMAKE_ARGS=	${_CMAKE_ARGS_${FLAVOR}}
_USE_QT_qt5=	core dbus buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

USE_LDCONFIG=	yes

CPE_VENDOR=	packagekit_project

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//}

.include <bsd.port.mk>
