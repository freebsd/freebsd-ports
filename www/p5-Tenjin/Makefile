# $FreeBSD$

PORTNAME=	Tenjin
PORTVERSION=	0.070001
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fast templating engine with support for embedded

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>0:www/p5-HTML-Parser
TEST_DEPENDS=	p5-Try-Tiny>0:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
