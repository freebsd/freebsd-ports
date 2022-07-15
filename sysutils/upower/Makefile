# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	upower
PORTVERSION=	0.99.20
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.freedesktop.org/upower/upower/-/archive/${DISTVERSIONFULL}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		compiler:c11 gettext gnome localbase meson \
		pkgconfig tar:bz2
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dgtk-doc=false \
		-Dos_backend=freebsd \
		-Dlocalstatedir=/var \
		-Dudevrulesdir=no \
		-Dudevhwdbdir=no \
		-Dsystemdsystemunitdir=no \
		-Didevice=disabled
LDFLAGS+=	-lkvm

OPTIONS_DEFINE=			MANPAGES
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_SUB=			yes
MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				docbook-sgml>0:textproc/docbook-sgml \
				docbook-xml>0:textproc/docbook-xml \
				gtkdoc-scan:textproc/gtk-doc
MANPAGES_USE=			GNOME=libxslt:build
MANPAGES_MESON_TRUE=		man

.include <bsd.port.mk>
