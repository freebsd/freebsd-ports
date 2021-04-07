PORTNAME=	jstest-gtk
PORTVERSION=	20180710
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Simple joystick tester based on Gtk+

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto

USES=		cmake compiler:c++11-lang gnome libtool localbase:ldflags \
		pkgconfig xorg
USE_GNOME=	gtkmm30 libsigc++20
INSTALLS_ICONS=	yes
USE_XORG=	x11

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	jstest-gtk
GL_COMMIT=	62f6e2d7d44620e503149510c428df9e004c9f3b

.include <bsd.port.mk>
