PORTNAME=	kguiaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

COMMENT=	Utilities for graphical user interfaces
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake desktop-file-utils gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	ecm:build plasma-wayland-protocols:build
USE_QT=		base wayland tools:build
USE_XORG=	x11 xcb

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
