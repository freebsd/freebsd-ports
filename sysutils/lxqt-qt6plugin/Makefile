PORTNAME=	lxqt-qt6plugin
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt system integration plugin for Qt6
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

LIB_DEPENDS=	libdbusmenu-lxqt.so:devel/libdbusmenu-lxqt \
		libexif.so:graphics/libexif

USES=		cmake compiler:c++20-lang gnome kde:6 lxqt:2 pkgconfig tar:xz \
		qt:6 gettext-runtime xorg

USE_XORG=	xcb
USE_GNOME=	glib20
USE_QT=		base:run tools:build svg
USE_KDE=	windowsystem
USE_LDCONFIG=	yes
USE_LXQT=	buildtools2 qt6xdg libfmqt6

PLIST_FILES=	${QT_PLUGINDIR}/platformthemes/libqtlxqt.so

.include <bsd.port.mk>
