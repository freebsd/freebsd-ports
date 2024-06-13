PORTNAME=	lxqt-qtplugin
PORTVERSION=	1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt system integration plugin for Qt
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt@qt5 \
		libexif.so:graphics/libexif

USES=	cmake compiler:c++17-lang gnome kde:5 lxqt:1 pkgconfig tar:xz qt:5 \
	gettext-runtime xorg

USE_XORG=xcb
USE_GNOME=glib20
USE_QT=		buildtools:build qmake:build core dbus gui svg widgets \
		x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools qtxdg libfmqt
USE_LDCONFIG=	yes

PLIST_FILES=	${QT_PLUGINDIR}/platformthemes/libqtlxqt.so

.include <bsd.port.mk>
