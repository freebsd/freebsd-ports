# $FreeBSD$

PORTNAME=	Plack-Middleware-MemoryUsage
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for measuring process memory

RUN_DEPENDS=	\
	p5-B-Size2>=2.01:${PORTSDIR}/devel/p5-B-Size2 \
	p5-Devel-Symdump>0:${PORTSDIR}/devel/p5-Devel-Symdump \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::MemoryUsage.3

.include <bsd.port.mk>
