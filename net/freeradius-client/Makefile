# Created by: netch@netch.kiev.ua
# $FreeBSD$

PORTNAME=	freeradius-client
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/ \
		ftp://ftp.suntel.com.tr/pub/freeradius/

MAINTAINER=	netch@portaone.com
COMMENT=	Client library and basic utilities for RADIUS AAA

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool tar:bzip2
USE_LDCONFIG=	yes

CONFLICTS=	radiusclient-ng-[0-9]*

.include <bsd.port.mk>
