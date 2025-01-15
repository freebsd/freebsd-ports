PORTNAME=	oxygen-icons
DISTVERSION=	6.1.0
CATEGORIES=	x11-themes kde
MASTER_SITES=	KDE/stable/${PORTNAME}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The Oxygen icon theme for KDE

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build  # We only install icons.

USE_QT=		tools:build

NO_ARCH=	yes

.include <bsd.port.mk>
