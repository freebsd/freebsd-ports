PORTNAME=	kguiaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtGui

DEPRECATED=	has its functionality stripped compared to a kf6 variant

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lib desktop-file-utils kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	ecm:build plasma-wayland-protocols:build
USE_QT=		core dbus gui wayland x11extras \
		buildtools:build qmake:build testlib:build
USE_XORG=	ice sm x11 xcb xext

# KF6 coinstallability
CMAKE_OFF=	BUILD_GEO_SCHEME_HANDLER

.include <bsd.port.mk>
