# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	upower
PORTVERSION=	0.99.13
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.freedesktop.org/upower/upower/uploads/177df5b9f9b76f25a2ad9da41aa0c1fa/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		compiler:c11 gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var \
		--with-backend=freebsd \
		--without-idevice
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			MANPAGES
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_SUB=			yes
MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				docbook-sgml>0:textproc/docbook-sgml \
				docbook-xml>0:textproc/docbook-xml
MANPAGES_USE=			GNOME=libxslt:build
MANPAGES_CONFIGURE_ENABLE=	man-pages

.include <bsd.port.mk>
