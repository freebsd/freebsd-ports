PORTNAME=	kguiaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits kde kde-frameworks

COMMENT=	Utilities for graphical user interfaces
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake desktop-file-utils gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	ecm:build plasma-wayland-protocols:build
USE_QT=		base wayland
USE_XORG=	x11 xcb

OPTIONS_DEFINE=		KF5COMPAT
KF5COMPAT_DESC=		Allow for co-instability with KF5
KF5COMPAT_CMAKE_BOOL_OFF=	BUILD_GEO_SCHEME_HANDLER
KF5COMPAT_RUN_DEPENDS=	kde-geo-uri-handler:x11-toolkits/kf5-kguiaddons
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=		YES

.include <bsd.port.mk>
