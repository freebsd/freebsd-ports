# New ports collection makefile for:	p5-Web-Scraper
# Date created:		2007-10-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Web-Scraper
PORTVERSION=	0.30
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web Scraping Toolkit inspired by Scrapi

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTTP/Response/Encoding.pm:${PORTSDIR}/www/p5-HTTP-Response-Encoding \
		${SITE_PERL}/HTML/Selector/XPath.pm:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/HTML/TreeBuilder/XPath.pm:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/XPathEngine.pm:${PORTSDIR}/textproc/p5-XML-XPathEngine \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	5.8.1+

MAN3=		Web::Scraper.3 Web::Scraper::Filter.3 Web::Scraper::LibXML.3

.include <bsd.port.mk>
