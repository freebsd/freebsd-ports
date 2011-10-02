# New ports collection makefile for:	p5-Web-Query
# Date created:		2011-10-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Web-Query
PORTVERSION=	0.06
CATEGORIES=	www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Yet another scraping library like jQuery

BUILD_DEPENDS=	p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TreeBuilder-XPath>=0.12:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-libwww>=5.385:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TreeBuilder-XPath>=0.12:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-libwww>=5.385:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Web::Query.3 \
		Web::README.3

.include <bsd.port.mk>
