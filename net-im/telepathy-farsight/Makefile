# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	telepathy-farsight
PORTVERSION=	0.0.19
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farsight Connection Manager for Telepathy Framework

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libgstfarsight-0.10.so:net-im/farsight2

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool localbase:ldflags pathfix pkgconfig python:2.7
USE_LDCONFIG=	yes
USE_GNOME=	glib20 libxslt:build

.include <bsd.port.mk>
