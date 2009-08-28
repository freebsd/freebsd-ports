# New ports collection makefile for:	p5-HTML-TableParser
# Date created:				2006/08/14
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-TableParser
PORTVERSION=	0.38
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract data from an HTML table

BUILD_DEPENDS=	p5-HTML-Parser>=3.34:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::TableParser.3 HTML::TableParser::Table.3

.include <bsd.port.mk>
