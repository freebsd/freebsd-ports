# $FreeBSD$

PORTNAME=	Corona
PORTVERSION=	0.1004
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Coro based PSGI web server

RUN_DEPENDS=	\
	p5-Coro>0:devel/p5-Coro \
	p5-Net-Server-Coro>=0.5:net/p5-Net-Server-Coro \
	p5-Plack>=0.99:www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
