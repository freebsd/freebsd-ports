PORTNAME=	Number-Fraction
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAVECROSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to model fractions
WWW=		https://metacpan.org/release/Number-Fraction

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=1.000001:devel/p5-Moo \
		p5-Moose>=0:devel/p5-Moose \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
