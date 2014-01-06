# $FreeBSD$

PORTNAME=	Plack-Handler-AnyEvent-SCGI
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for PSGI handler on AnyEvent::SCGI

RUN_DEPENDS=	\
	p5-AnyEvent-SCGI>0:${PORTSDIR}/www/p5-AnyEvent-SCGI \
	p5-Plack>=0.9901:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
