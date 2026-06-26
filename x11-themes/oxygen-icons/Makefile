PORTNAME=	oxygen-icons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks
PKGNAMEPREFIX=	# override kde.mk

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The Oxygen icon theme for KDE

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build  # We only install icons.

USE_QT=		tools:build

NO_ARCH=	yes

.include <bsd.port.mk>
