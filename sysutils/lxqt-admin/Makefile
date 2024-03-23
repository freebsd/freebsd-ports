PORTNAME=	lxqt-admin
PORTVERSION=	1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	System administration tool for the LXQt desktop
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lang gnome kde:5 localbase \
		lxqt perl5 pkgconfig tar:xz qt:5 xorg
USE_PERL5=	build
USE_QT=		buildtools:build qmake:build core dbus gui svg \
		widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt
USE_XORG=	x11

.include <bsd.port.mk>
