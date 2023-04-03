PORTNAME=	PackageKit-Qt
PORTVERSION=	1.1.1
CATEGORIES=	ports-mgmt sysutils
MASTER_SITES=	https://www.freedesktop.org/software/PackageKit/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	DBUS packaging abstraction layer (Qt bindings)
WWW=		https://www.freedesktop.org/software/PackageKit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/dbus-1/interfaces/org.freedesktop.PackageKit.xml:ports-mgmt/packagekit

USES=		cmake cpe qt:5 tar:xz

USE_QT=		core dbus buildtools:build qmake:build
USE_LDCONFIG=	yes

CPE_VENDOR=	packagekit_project

.include <bsd.port.mk>
