# $FreeBSD$

PORTNAME=	Net-SSH-Mechanize
PORTVERSION=	0.1.3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for asynchronous ssh command invocation

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-AnyEvent-Subprocess>0:${PORTSDIR}/devel/p5-AnyEvent-Subprocess \
	p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Params-Validate>0:${PORTSDIR}/devel/p5-MooseX-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Net::SSH::Mechanize.3 \
	Net::SSH::Mechanize::ConnectParams.3 \
	Net::SSH::Mechanize::Multi.3 \
	Net::SSH::Mechanize::Session.3

.include <bsd.port.mk>
