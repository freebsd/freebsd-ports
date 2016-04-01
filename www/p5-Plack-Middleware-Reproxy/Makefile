# $FreeBSD$

PORTNAME=	Plack-Middleware-Reproxy
PORTVERSION=	0.00004
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to handle X-Reproxy-URL from within Plack

RUN_DEPENDS=	\
	p5-Plack>0:www/p5-Plack \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-TEST-TCP>0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
