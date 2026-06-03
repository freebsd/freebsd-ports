PORTNAME=	networkmanager-qt
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	net-mgmt kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt wrapper for NetworkManager API

LIB_DEPENDS=	libnm.so:net-mgmt/networkmanager-shim

USES=		cmake gettext-runtime kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base declarative

CMAKE_ARGS=	-DKF_IGNORE_PLATFORM_CHECK=true

.include <bsd.port.mk>
