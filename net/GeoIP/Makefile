# New ports collection makefile for:	GeoIP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.4.2
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		geoiplookup.1 geoipupdate.1

.include <bsd.port.mk>
