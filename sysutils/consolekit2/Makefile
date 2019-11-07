# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	consolekit
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	https://github.com/ConsoleKit2/ConsoleKit2/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	2
DISTNAME=	ConsoleKit2-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libpolkit-gobject-1.so:sysutils/polkit

WRKSRC=		${WRKDIR}/ConsoleKit2-${PORTVERSION}
USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		tar:bzip2 xorg
USE_CSTD=	gnu99
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

post-install:
.for script in ck-system-hibernate ck-system-hybridsleep \
	ck-system-restart ck-system-stop ck-system-suspend
	cd ${STAGEDIR}${PREFIX}/lib/ConsoleKit/scripts && \
		${MV} ${script} ${script}.sample
.endfor

.include <bsd.port.mk>
