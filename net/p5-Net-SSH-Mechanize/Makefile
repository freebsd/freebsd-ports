# $FreeBSD$

PORTNAME=	Net-SSH-Mechanize
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for asynchronous ssh command invocation

RUN_DEPENDS=	\
	p5-AnyEvent>0:devel/p5-AnyEvent \
	p5-AnyEvent-Subprocess>0:devel/p5-AnyEvent-Subprocess \
	p5-Coro>0:devel/p5-Coro \
	p5-Moose>0:devel/p5-Moose \
	p5-MooseX-Params-Validate>0:devel/p5-MooseX-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
