# New ports collection makefile for:	p5-Geo-IP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-IP
PORTVERSION=	1.25
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.maxmind.com/download/geoip/api/perl/
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Gets country name by IP or hostname

LIB_DEPENDS=	GeoIP.4:${PORTSDIR}/net/GeoIP

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS='-L${LOCALBASE}/lib' INC='-I${LOCALBASE}/include'

MAN3=		Geo::Mirror.3 Geo::IP.3 Geo::IP::Record.3

post-patch:
	@${PERL} -pi -e 's/^our (.*),(.*);$$/use vars qw$$1$$2;/' ${WRKSRC}/lib/Geo/Mirror.pm
	@${PERL} -pi -e 's/^([\w].+);$$/\1/' ${WRKSRC}/IP.xs

.include <bsd.port.mk>
