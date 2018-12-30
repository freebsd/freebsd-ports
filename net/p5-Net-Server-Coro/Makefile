# $FreeBSD$

PORTNAME=	Net-Server-Coro
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for co-operative multithreaded server using Coro

LICENSE=	MIT

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-AnyEvent>0:devel/p5-AnyEvent \
	p5-Coro>0:devel/p5-Coro \
	p5-Net-Server>=2:net/p5-Net-Server

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
