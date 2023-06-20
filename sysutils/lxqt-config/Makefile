PORTNAME=	lxqt-config
PORTVERSION=	1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT
DIST_SUBDIR=	lxqt

#PATCH_SITES=	https://github.com/lxqt/lxqt-config/commit/
#PATCHFILES=	6add4e4f0040693e7c4242fbae48c9d32007686c.patch:-p1

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt system settings center
WWW=		https://lxqt-project.org

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/lib/xorg/modules/input/libinput_drv.so:x11-drivers/xf86-input-libinput
LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=	cmake compiler:c++17-lang kde:5 localbase:ldflags lxqt qt:5 \
	pkgconfig tar:xz xorg gnome
USE_QT=	buildtools:build qmake:build concurrent core dbus \
	gui linguisttools svg widgets x11extras xml
USE_KDE=	libkscreen windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt
USE_XORG=	ice sm x11 xcb xcursor xext xfixes xrandr xi
USE_LDCONFIG=	yes

# Override default of c++14 set by lxqt-buildtools
# This is needed as KScreen introduced code requiring c++17
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_EXTENSIONS=OFF

.include <bsd.port.mk>
