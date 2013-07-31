# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-glib/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	telepathy-glib
PORTVERSION=	0.20.2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib utility library for the Telepathy framework

BUILD_DEPENDS=	vala-vapigen>=0.20.0:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen

PORTSCOUT=	limitw:1,even

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build libxslt:build ltverhack
USE_PYTHON_BUILD=	yes
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala-bindings

.include <bsd.port.mk>
