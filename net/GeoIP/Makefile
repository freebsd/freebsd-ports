# New ports collection makefile for:	GeoIP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.3.8
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		geoiplookup.1 geoipupdate.1

post-install:
.if !exists(${PREFIX}/etc/GeoIP.conf)
	@${INSTALL_DATA} ${PREFIX}/etc/GeoIP.conf.default ${PREFIX}/etc/GeoIP.conf
.endif

.include <bsd.port.mk>
