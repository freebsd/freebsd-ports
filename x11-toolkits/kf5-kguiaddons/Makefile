PORTNAME=	kguiaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtGui

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++11-lib desktop-file-utils kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_KDE=	plasma-wayland-protocols \
		ecm:build
USE_QT=		core gui wayland widgets x11extras \
		buildtools:build qmake:build testlib:build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
