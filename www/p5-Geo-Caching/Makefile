# New ports collection makefile for:	Geo-Caching
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Caching
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Object interface for querying Geocaching.com website

BUILD_DEPENDS=	${SITE_PERL}/Geo/Cache.pm:${PORTSDIR}/misc/p5-Geo-Cache \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Geo::Caching.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl5.8
.endif

.include <bsd.port.post.mk>
