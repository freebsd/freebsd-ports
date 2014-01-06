# $FreeBSD$

PORTNAME=	Fliggy
PORTVERSION=	0.009003
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VTI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Fliggy: Twiggy with inlined flash policy server

RUN_DEPENDS=	\
	p5-Twiggy>0:${PORTSDIR}/www/p5-Twiggy
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
