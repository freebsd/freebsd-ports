# $FreeBSD$

PORTNAME=	Plack-Server-POE
PORTVERSION=	0.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Plack Server implementation for POE

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-POE>0:${PORTSDIR}/devel/p5-POE \
	p5-POE-Filter-HTTP-Parser>0:${PORTSDIR}/www/p5-POE-Filter-HTTP-Parser
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

MAN3=	Plack::Server::POE.3

NO_STAGE=	yes
.include <bsd.port.mk>
