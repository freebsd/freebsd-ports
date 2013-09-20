# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	HTML-Summary
PORTVERSION=	0.017
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Produces summaries from the textual content of web pages

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree

USES=		perl5
USE_PERL5=	configure

MAN3=		HTML::Summary.3 Text::Sentence.3 Lingua::JA::Jtruncate.3

NO_STAGE=	yes
.include <bsd.port.mk>
