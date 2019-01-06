# $FreeBSD$

PORTNAME=	Gazelle
PORTVERSION=	0.48
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Preforked Plack Handler for performance freaks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Devel-CheckCompiler>=0.04:devel/p5-Devel-CheckCompiler
RUN_DEPENDS=	p5-Guard>=0:devel/p5-Guard \
		p5-Parallel-Prefork>=0.18:devel/p5-Parallel-Prefork \
		p5-Plack>=1.0037:www/p5-Plack \
		p5-Server-Starter>=0:net/p5-Server-Starter \
		p5-Stream-Buffered>=0:devel/p5-Stream-Buffered
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Plack>=0:www/p5-Plack \
		p5-Test-TCP>=2:devel/p5-Test-TCP

USES=		perl5

USE_PERL5=	modbuild

.include <bsd.port.mk>
