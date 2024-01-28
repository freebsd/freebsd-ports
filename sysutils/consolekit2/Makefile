PORTNAME=	consolekit
PORTVERSION=	1.2.6
PORTREVISION=	3
CATEGORIES=	sysutils gnome
PKGNAMESUFFIX=	2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Framework for defining and tracking users
WWW=		https://github.com/ConsoleKit2/ConsoleKit2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libevdev.so:devel/libevdev \
		libudev.so:devel/libudev-devd

OPTIONS_DEFINE=	POLKIT X11
OPTIONS_DEFAULT=POLKIT X11
OPTIONS_SUB=	yes

POLKIT_DESC=	Build with Polkit support

POLKIT_LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit
POLKIT_CONFIGURE_ENABLE=	polkit

X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_WITH=	x

USE_GITHUB=	yes
GH_ACCOUNT=	arrowd
GH_PROJECT=	ConsoleKit2
GH_TAGNAME=	70b5f7d6f710377f288b4723a32923290dc16501

USES=		autoreconf gettext gmake gnome libtool localbase pathfix pkgconfig \
		tar:bzip2
USE_CSTD=	gnu99
USE_GNOME=	glib20 libxslt introspection:build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid \
		--enable-pam-module \
		--with-pam-module-dir=${PREFIX}/lib \
		--localstatedir=/var \
		--enable-introspection \
		--enable-libdrm \
		--enable-libevdev \
		--enable-libudev \
		--disable-udev-acl \
		--disable-libcgmanager \
		--without-systemdsystemunitdir
INSTALL_TARGET=	install-strip

post-install:
.for script in ck-system-hibernate ck-system-hybridsleep \
	ck-system-restart ck-system-stop ck-system-suspend
	cd ${STAGEDIR}${PREFIX}/lib/ConsoleKit/scripts && \
		${MV} ${script} ${script}.sample
.endfor

.include <bsd.port.mk>
