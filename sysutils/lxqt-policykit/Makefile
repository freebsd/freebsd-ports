# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-policykit
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PolicyKit authentication agent

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt5-agent-1.so:sysutils/polkit-qt@qt5 \
		libpolkit-agent-1.so:sysutils/polkit

USES=	cmake compiler:c++11-lib gettext-runtime kde:5 qt:5 \
	localbase:ldflags lxqt pkgconfig tar:xz
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20

PLIST_FILES=	bin/lxqt-policykit-agent \
		etc/xdg/autostart/lxqt-policykit-agent.desktop

.include <bsd.port.mk>
