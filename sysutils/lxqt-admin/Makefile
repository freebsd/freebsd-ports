# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-admin
PORTVERSION=	0.13.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	System administration tool for the LXQt desktop

LICENSE=	LGPL21+

USES=	cmake compiler:c++11-lang gnome kde:5 localbase \
	lxqt pkgconfig tar:xz qt:5
USE_QT=	buildtools_build qmake_build core dbus gui svg \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt

PLIST_FILES=	bin/lxqt-admin-user \
		bin/lxqt-admin-user-helper \
		share/applications/lxqt-admin-user.desktop \
		share/polkit-1/actions/org.lxqt.lxqt-admin-user.policy

.include <bsd.port.mk>
