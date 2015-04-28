# $FreeBSD$

PORTNAME=	Server-Starter
PORTVERSION=	0.27
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZUHO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of superdaemon for hot-deploying server programs

TEST_DEPENDS=	p5-IO-Socket-IP>=0:${PORTSDIR}/net/p5-IO-Socket-IP \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-SharedFork>0:${PORTSDIR}/devel/p5-Test-SharedFork \
		p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
