# $FreeBSD$

PORTNAME=	Twiggy
PORTVERSION=	0.1025
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of AnyEvent HTTP server for PSGI (like Thin)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-AnyEvent>0:devel/p5-AnyEvent \
	p5-libwww>0:www/p5-libwww \
	p5-Plack>=0.99:www/p5-Plack \
	p5-Try-Tiny>0:lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-TCP>0:devel/p5-Test-TCP

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
