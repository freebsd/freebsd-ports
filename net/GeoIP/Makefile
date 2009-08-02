# New ports collection makefile for:	GeoIP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.4.6
CATEGORIES=	net geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

MAN1=		geoiplookup.1 geoipupdate.1 geoiplookup6.1

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/geoipupdate.sh ${PREFIX}/bin/

.include <bsd.port.mk>
