# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/upower/Makefile 19882 2014-09-16 12:34:00Z kwm $

PORTNAME=	upower
PORTVERSION=	0.99.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		gettext gmake libtool pathfix pkgconfig \
		python tar:xz
USE_GNOME=	intlhack glib20 introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ENV=	GTKDOC="false"

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes
MANPAGES_CONFIGURE_ENABLE=	man-pages
MANPAGES_BUILD_DEPENDS= \
	docbook-sgml>0:${PORTSDIR}/textproc/docbook-sgml \
	docbook-xml>0:${PORTSDIR}/textproc/docbook-xml \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MANPAGES_USE=	GNOME=libxslt:build

.include <bsd.port.mk>
