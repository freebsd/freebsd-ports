# New ports collection makefile for:	p5-Geo-IP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-IP
PORTVERSION=	1.13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.maxmind.com/download/geoip/api/perl/
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	seanc@FreeBSD.org

LIB_DEPENDS=	GeoIP.2:${PORTSDIR}/net/GeoIP

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS='-L${PREFIX}/lib' INC='-I${PREFIX}/include'

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Geo::Mirror.3 Geo::IP.3 Geo::IP::Record.3

.include <bsd.port.mk>
