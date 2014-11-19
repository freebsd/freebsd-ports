# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	telepathy-farsight
PORTVERSION=	0.0.19
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farsight Connection Manager for Telepathy Framework

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libgstfarsight-0.10.so:${PORTSDIR}/net-im/farsight2

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig python
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 libxslt:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
