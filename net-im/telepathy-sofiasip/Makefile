# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	telepathy-sofiasip
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF/tp-sofiasip/${PORTNAME}/${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIP (sofia-sip) Connection Manager for Telepathy Framework

LIB_DEPENDS=	libsofia-sip-ua.so:net/sofia-sip \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libdbus-glib-1.so:devel/dbus-glib

GNU_CONFIGURE=	yes
USES=		gmake gnome pkgconfig ssl
USE_GNOME=	glib20

.include <bsd.port.mk>
