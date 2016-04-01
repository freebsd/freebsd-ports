# $FreeBSD$

PORTNAME=	Plack-Middleware-MemoryUsage
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for measuring process memory

RUN_DEPENDS=	\
	p5-B-Size2>=2.01:devel/p5-B-Size2 \
	p5-Devel-Symdump>0:devel/p5-Devel-Symdump \
	p5-Plack>0:www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
