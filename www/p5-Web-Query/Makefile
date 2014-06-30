# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Web-Query
PORTVERSION=	0.17
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet another scraping library like jQuery

BUILD_DEPENDS=	p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TreeBuilder-XPath>=0.12:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-libwww>=5.385:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
