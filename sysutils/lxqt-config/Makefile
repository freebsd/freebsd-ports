PORTNAME=	lxqt-config
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
DIST_SUBDIR=	lxqt

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt system settings center
WWW=		https://lxqt-project.org

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	lxqt-menu-data>=2.0.0:x11/lxqt-menu-data \
		${LOCALBASE}/lib/xorg/modules/input/libinput_drv.so:x11-drivers/xf86-input-libinput
RUN_DEPENDS=	lxqt-menu-data>=2.0.0:x11/lxqt-menu-data

LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++20-lang kde:6 localbase:ldflags lxqt:2 \
		qt:6 perl5 pkgconfig tar:xz xorg gnome
USE_QT=		base:run tools:build svg
USE_KDE=	libkscreen windowsystem
USE_GNOME=	glib20
USE_PERL5=	build
USE_XORG=	ice sm x11 xcb xcursor xext xfixes xrandr xi
USE_LDCONFIG=	yes
USE_LXQT=	buildtools2 lxqt

CXXFLAGS+=	-Wno-c++11-narrowing

.include <bsd.port.mk>
