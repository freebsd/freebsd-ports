# Created by: Olivier Duchateau

PORTNAME=	lxqt-admin
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	System administration tool for the LXQt desktop

LICENSE=	LGPL21+

USES=	cmake compiler:c++11-lang gnome kde:5 localbase \
	lxqt pkgconfig tar:xz qt:5 xorg
USE_QT=	buildtools_build qmake_build core dbus gui svg \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt
USE_XORG=	x11

.include <bsd.port.mk>
