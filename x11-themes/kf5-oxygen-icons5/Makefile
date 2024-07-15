PORTNAME=	oxygen-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The Oxygen icon theme for KDE

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	ecm:build  # We only install icons.

USE_QT=		buildtools:build core:build qmake:build

NO_ARCH=	yes

.include <bsd.port.mk>
