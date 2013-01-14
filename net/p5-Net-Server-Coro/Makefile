# $FreeBSD$

PORTNAME=	Net-Server-Coro
PORTVERSION=	1.3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for co-operative multithreaded server using Coro

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
	p5-Net-Server>=2:${PORTSDIR}/net/p5-Net-Server
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Server::Coro.3

.include <bsd.port.mk>
