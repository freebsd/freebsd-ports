# New ports collection makefile for:	p5-HTML-LinkExtractor
# Date created:			18 April 2004
# Whom:				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-LinkExtractor
PORTVERSION=	0.130
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.13

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	HTML::LinkExtractor is used for extracting links from HTML

BUILD_DEPENDS=	${SITE_PERL}/HTML/TokeParser/Simple.pm:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::LinkExtractor.3

.include <bsd.port.mk>
