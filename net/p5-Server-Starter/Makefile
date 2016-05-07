# $FreeBSD$

PORTNAME=	Server-Starter
PORTVERSION=	0.30
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZUHO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of superdaemon for hot-deploying server programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-IO-Socket-IP>=0:net/p5-IO-Socket-IP \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-SharedFork>0:devel/p5-Test-SharedFork \
		p5-Test-TCP>=0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
