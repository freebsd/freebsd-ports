PORTNAME=	telepathy-glib
PORTVERSION=	0.24.1
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib utility library for the Telepathy framework

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

PORTSCOUT=	limitw:1,even

USES=		gmake gnome libtool pathfix pkgconfig python:build vala:lib
USE_GNOME=	glib20 introspection:build libxslt:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala-bindings
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
