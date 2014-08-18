# Created by: gnome@freebsd.org
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-glib/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	telepathy-glib
PORTVERSION=	0.24.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib utility library for the Telepathy framework

BUILD_DEPENDS=	vala-vapigen>=0.20.0:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen

PORTSCOUT=	limitw:1,even

USES=		gmake libtool pathfix pkgconfig python:build
USE_GNOME=	glib20 gnomehier introspection:build libxslt:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala-bindings
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
