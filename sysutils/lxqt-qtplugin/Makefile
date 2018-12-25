# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-qtplugin
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt system integration plugin for Qt

LICENSE=	LGPL21+

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt@qt5 \
		libfm.so:x11/libfm \
		libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif

USES=	cmake compiler:c++11-lib kde:5 lxqt pkgconfig tar:xz qt:5 gettext-runtime

USE_XORG=xcb
USE_GNOME=glib20
USE_QT=	buildtools_build qmake_build core dbus gui svg widgets \
	x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools qtxdg libfmqt
USE_LDCONFIG=	yes
PLIST_FILES=	${QT_PLUGINDIR}/platformthemes/libqtlxqt.so

.include <bsd.port.mk>
