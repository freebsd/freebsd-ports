# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-glib/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	telepathy-glib
PORTVERSION=	0.20.2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib utility library for the Telepathy framework

BUILD_DEPENDS=	vala-vapigen>=0.20.0:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen

PORTSCOUT=	limitw:1,even

USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build libxslt:build ltverhack
USE_PYTHON_BUILD=	yes
MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala-bindings

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
