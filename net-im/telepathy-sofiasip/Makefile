# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	telepathy-sofiasip
PORTVERSION=	0.4.5
CATEGORIES=	net-im
MASTER_SITES=	SF/tp-sofiasip/${PORTNAME}/${PORTVERSION}

MAINTAINER=	yuri@tsoft.com
COMMENT=	SIP (sofia-sip) Connection Manager for Telepathy Framework

LIB_DEPENDS=	sofia-sip-ua:${PORTSDIR}/net/sofia-sip \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USES=		pkgconfig
USE_GNOME=	glib20

.include <bsd.port.mk>
