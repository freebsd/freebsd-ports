# New ports collection makefile for:	GeoIP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/

MAINTAINER=	seanc@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gnu-ld=yes
INSTALLS_SHLIB=	yes

MAN1=		geoiplookup.1 geoipupdate.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
