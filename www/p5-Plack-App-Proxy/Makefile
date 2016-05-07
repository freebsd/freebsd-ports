# $FreeBSD$

PORTNAME=	Plack-App-Proxy
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEEDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Plack extension for proxy requests

RUN_DEPENDS=	\
	p5-AnyEvent-HTTP>=1.44:www/p5-AnyEvent-HTTP \
	p5-libwww>0:www/p5-libwww \
	p5-Plack>=1.0013:www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-TCP>0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
