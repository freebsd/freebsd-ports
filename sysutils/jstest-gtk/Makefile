PORTNAME=	jstest-gtk
PORTVERSION=	20260729
CATEGORIES=	sysutils

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Simple joystick tester based on Gtk+
WWW=		https://github.com/Grumbel/jstest-gtk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto
LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++11-lang gnome localbase:ldflags \
		pkgconfig xorg
USE_GNOME=	gtkmm30 libsigc++20
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	Grumbel
GH_TAGNAME=	d910b1caf6b4b0a34964ed961fdbfd08429df80f

.include <bsd.port.mk>
