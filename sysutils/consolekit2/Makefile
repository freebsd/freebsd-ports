# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	consolekit
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	sysutils gnome
PKGNAMESUFFIX=	2

# Support for DRM/evdev
PATCH_SITES=	https://github.com/unrelentingtech/ConsoleKit2/commit/
PATCHFILES=	03eaa9779f2c9c7b0acf0521a5547036bdec2245.patch:-p1 \
		05f26e99539e7a442e57035ed6d64fdd9a50feb9.patch:-p1 \
		ea4a569100dfa44a0c9d42b1cf7381fd8f88c837.patch:-p1 \
		42b8c93b2b7c2a57a74580531c73ab736e95336a.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Framework for defining and tracking users

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
GH_ACCOUNT=	ConsoleKit2
GH_PROJECT=	ConsoleKit2
GH_TAGNAME=	520b862 # v1.2.3

USES=		autoreconf gettext gmake gnome libtool localbase pathfix pkgconfig \
		tar:bzip2
USE_CSTD=	gnu99
USE_GNOME=	glib20 libxslt introspection:build
GNU_CONFIGURE=	yes
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
