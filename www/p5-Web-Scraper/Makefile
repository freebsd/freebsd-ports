# New ports collection makefile for:	p5-Web-Scraper
# Date created:		2007-10-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Web-Scraper
PORTVERSION=	0.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web Scraping Toolkit inspired by Scrapi

RUN_DEPENDS=	p5-HTML-Entities>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Selector-XPath>=0.03:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-Tagset>0:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-TreeBuilder-LibXML>=0.04:${PORTSDIR}/www/p5-HTML-TreeBuilder-LibXML \
		p5-HTML-TreeBuilder-XPath>=0.08:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-HTML-TreeBuilder>=3.23:${PORTSDIR}/www/p5-HTML-Tree \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-XPathEngine>=0.08:${PORTSDIR}/textproc/p5-XML-XPathEngine \
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
		p5-libwww>=5.827:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	5.8.1+

MAN3=		Web::Scraper.3 Web::Scraper::Filter.3 Web::Scraper::LibXML.3

.include <bsd.port.mk>
