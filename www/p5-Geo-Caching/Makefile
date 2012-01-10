# New ports collection makefile for:	Geo-Caching
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Caching
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	www perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object interface for querying Geocaching.com website

BUILD_DEPENDS=	${SITE_PERL}/Geo/Cache.pm:${PORTSDIR}/misc/p5-Geo-Cache \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Geo-Gpx>=0:${PORTSDIR}/graphics/p5-Geo-Gpx
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Geo::Caching.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
