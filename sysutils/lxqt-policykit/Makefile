PORTNAME=	lxqt-policykit
PORTVERSION=	1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PolicyKit authentication agent

LICENSE=	LGPL21+

LIB_DEPENDS=	libpolkit-qt5-agent-1.so:sysutils/polkit-qt \
		libpolkit-agent-1.so:sysutils/polkit

USES=	cmake compiler:c++14-lang gettext-runtime kde:5 qt:5 gnome \
	localbase:ldflags lxqt pkgconfig tar:xz xorg
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt
USE_GNOME=	glib20
USE_XORG=	x11
.include <bsd.port.mk>
