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

.include <bsd.port.mk>
