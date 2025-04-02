PORTNAME=	PackageKit-Qt
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	https://www.freedesktop.org/software/PackageKit/releases/
PKGNAMESUFFIX=	6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	DBUS packaging abstraction layer (Qt bindings)
WWW=		https://www.freedesktop.org/software/PackageKit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/dbus-1/interfaces/org.freedesktop.PackageKit.xml:ports-mgmt/packagekit

USES=		cmake cpe pathfix qt:6 tar:xz
CPE_VENDOR=	packagekit_project
USE_LDCONFIG=	yes
USE_QT=		base

CMAKE_ARGS=	-DBUILD_WITH_QT6:BOOL=TRUE

PLIST_SUB=	QT_VER=6

.include <bsd.port.mk>
