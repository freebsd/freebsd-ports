# $FreeBSD$

PORTNAME=	Plack-Handler-AnyEvent-ReverseHTTP
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to reversehttp gateway for PSGI application

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-AnyEvent-ReverseHTTP>0:${PORTSDIR}/www/p5-AnyEvent-ReverseHTTP \
	p5-Plack>=0.99:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
