# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	upower
PORTVERSION=	0.99.12
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.freedesktop.org/upower/upower/uploads/244f5966c58773bbd3b4c507c549560f/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		compiler:c11 gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var \
		--with-backend=freebsd \
		--without-idevice
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			MANPAGES
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_SUB=			yes
MANPAGES_CONFIGURE_ENABLE=	man-pages
MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				docbook-sgml>0:textproc/docbook-sgml \
				docbook-xml>0:textproc/docbook-xml
MANPAGES_USE=			GNOME=libxslt:build

.include <bsd.port.mk>
