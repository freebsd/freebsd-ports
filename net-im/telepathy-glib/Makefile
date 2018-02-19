# Created by: gnome@freebsd.org
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-glib/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	telepathy-glib
PORTVERSION=	0.24.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib utility library for the Telepathy framework

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	vapigen:lang/vala

PORTSCOUT=	limitw:1,even

USES=		gmake libtool pathfix pkgconfig python:2.7,build
USE_GNOME=	glib20 introspection:build libxslt:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala-bindings
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
