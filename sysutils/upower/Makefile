# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	upower
PORTVERSION=	0.99.4
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit \
		libdbus-glib-1.so:devel/dbus-glib

USES=		gettext gmake libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	intlhack glib20 introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var \
		--with-backend=freebsd \
		--without-idevice
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes
MANPAGES_CONFIGURE_ENABLE=	man-pages
MANPAGES_BUILD_DEPENDS= \
	docbook-sgml>0:textproc/docbook-sgml \
	docbook-xml>0:textproc/docbook-xml \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
MANPAGES_USE=	GNOME=libxslt:build

.include <bsd.port.mk>
