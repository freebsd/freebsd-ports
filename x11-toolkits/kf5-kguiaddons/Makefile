PORTNAME=	kguiaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtGui

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	plasma-wayland-protocols \
		ecm_build
USE_QT=		core gui wayland widgets x11extras \
		buildtools_build qmake_build testlib_build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
