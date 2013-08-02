# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-IP
PORTVERSION=	1.42
CATEGORIES=	net geography perl5
MASTER_SITES=	CPAN \
		http://www.maxmind.com/download/geoip/api/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Gets country name by IP or hostname

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	LIBS='-L${LOCALBASE}/lib' INC='-I${LOCALBASE}/include'

MAN3=		Geo::Mirror.3 Geo::IP.3 Geo::IP::Record.3

.include <bsd.port.mk>
