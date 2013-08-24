# $FreeBSD$

PORTNAME=	sofia-sip
PORTVERSION=	1.12.11
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source SIP User-Agent library

LICENSE=	LGPL21

# Looks like GNU make(1) is needed for parallel (-jX) builds to work
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GNOME=	glib20

MAN1=		sip-date.1 \
		sip-options.1 \
		localinfo.1 \
		addrinfo.1 \
		stunc.1 \
		sip-dig.1

.include <bsd.port.mk>
