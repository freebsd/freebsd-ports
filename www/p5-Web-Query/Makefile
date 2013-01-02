# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Web-Query
PORTVERSION=	0.11
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Yet another scraping library like jQuery

BUILD_DEPENDS=	p5-HTML-Selector-XPath>=0.06:${PORTSDIR}/www/p5-HTML-Selector-XPath \
		p5-HTML-TreeBuilder-XPath>=0.12:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-libwww>=5.385:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Web::Query.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
