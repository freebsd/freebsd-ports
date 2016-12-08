# $FreeBSD$

PORTNAME=	sofia-sip
PORTVERSION=	1.12.11
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source SIP User-Agent library

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
# Looks like GNU make(1) is needed for parallel (-jX) builds to work
USES=		gmake libtool pathfix pkgconfig
USE_OPENSSL=	yes
USE_GNOME=	glib20

.include <bsd.port.mk>
