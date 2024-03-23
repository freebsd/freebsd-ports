PORTNAME=	lxqt-config
PORTVERSION=	1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT
DIST_SUBDIR=	lxqt

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt system settings center
WWW=		https://lxqt-project.org

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	lxqt-menu-data>=1.4.1:x11/lxqt-menu-data \
		${LOCALBASE}/lib/xorg/modules/input/libinput_drv.so:x11-drivers/xf86-input-libinput
RUN_DEPENDS=	lxqt-menu-data>=1.4.1:x11/lxqt-menu-data

LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang kde:5 localbase:ldflags \
		lxqt qt:5 perl5 pkgconfig tar:xz xorg gnome
USE_QT=		buildtools:build core dbus gui linguisttools svg qmake:build widgets x11extras xml
USE_KDE=	libkscreen windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt
USE_PERL5=	build
USE_XORG=	ice sm x11 xcb xcursor xext xfixes xrandr xi
USE_LDCONFIG=	yes

.include <bsd.port.mk>
