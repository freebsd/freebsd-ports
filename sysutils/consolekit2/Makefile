# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	consolekit
PORTVERSION=	1.2.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	https://github.com/ConsoleKit2/ConsoleKit2/releases/download/${PORTVERSION}/
DISTNAME=	ConsoleKit2-${PORTVERSION}
PKGNAMESUFFIX=	2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libpolkit-gobject-1.so:sysutils/polkit

WRKSRC=		${WRKDIR}/ConsoleKit2-${PORTVERSION}
USES=		gettext gmake libtool localbase pathfix pkgconfig tar:bzip2
USE_XORG=	x11
USE_GNOME=	glib20 libxslt introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid \
		--enable-pam-module \
		--with-pam-module-dir=${PREFIX}/lib \
		--localstatedir=/var \
		--enable-polkit \
		--enable-introspection \
		--without-html-dir \
		--disable-udev-acl \
		--disable-libcgmanager \
		--disable-libdrm \
		--disable-libevdev \
		--disable-libudev \
		--without-systemdsystemunitdir
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
