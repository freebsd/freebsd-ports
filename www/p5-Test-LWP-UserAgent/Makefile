# $FreeBSD$

PORTNAME=	Test-LWP-UserAgent
PORTVERSION=	0.030
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	LWP::UserAgent suitable for simulating and testing network calls

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-URI>=0:net/p5-URI \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-ExtUtils-MakeMaker>=0:devel/p5-ExtUtils-MakeMaker \
		p5-Plack>=0:www/p5-Plack \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Simple>=0:devel/p5-Test-Simple \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
