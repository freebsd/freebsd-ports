# New ports collection makefile for:	p5-Geo-IP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-IP
PORTVERSION=	1.38
CATEGORIES=	net geography perl5
MASTER_SITES=	CPAN \
		http://www.maxmind.com/download/geoip/api/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Gets country name by IP or hostname

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS='-L${LOCALBASE}/lib' INC='-I${LOCALBASE}/include'

MAN3=		Geo::Mirror.3 Geo::IP.3 Geo::IP::Record.3

.include <bsd.port.mk>
