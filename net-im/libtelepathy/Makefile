# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/libtelepathy/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	libtelepathy
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	net-im devel
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Flexible Communications Framework

LIB_PC_DEPENDS=	dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib

LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USES=		gmake libtool pathfix pkgconfig python:build
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lglib-2.0 `pkg-config --libs telepathy-glib`
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
