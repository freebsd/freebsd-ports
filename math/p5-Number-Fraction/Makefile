PORTNAME=	Number-Fraction
PORTVERSION=	3.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAVECROSS
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl extension to model fractions

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=1.000001:devel/p5-Moo \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooX-Types-MooseLike>0:devel/p5-MooX-Types-MooseLike
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
