# New ports collection makefile for:	p5-HTML-LinkExtractor
# Date created:			18 April 2004
# Whom:				Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-LinkExtractor
PORTVERSION=	0.130
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.13

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	HTML::LinkExtractor is used for extracting links from HTML

BUILD_DEPENDS=	p5-HTML-TokeParser-Simple>=0:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::LinkExtractor.3

.include <bsd.port.mk>
