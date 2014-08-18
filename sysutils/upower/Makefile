# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/upower/Makefile 19813 2014-08-15 19:44:33Z gusi $

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

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
PLIST_SUB+=	MAN="@comment "
.else
BUILD_DEPENDS+=	docbook-sgml>=0:${PORTSDIR}/textproc/docbook-sgml \
		docboox-xml>=0:${PORTSDIR}/textproc/docbook-xml \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt:build
PLIST_SUB+=	MAN=""
.endif

.include <bsd.port.mk>
