PORTNAME=	Math-GSL-Alien
PORTVERSION=	1.05
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAKONH
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Easy installation of the GSL library
WWW=		https://metacpan.org/release/Math-GSL-Alien

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libgsl.so:math/gsl
BUILD_DEPENDS=	p5-Alien-Build>=2.21:devel/p5-Alien-Build \
		p5-Alien-Role-Dino>0:devel/p5-Alien-Role-Dino
RUN_DEPENDS=	p5-Alien-Build>=2.21:devel/p5-Alien-Build \
		p5-Alien-Role-Dino>0:devel/p5-Alien-Role-Dino
TEST_DEPENDS=	p5-Test-Simple>=0.000071:devel/p5-Test-Simple \
		p5-Alien-Build>0:devel/p5-Alien-Build

USES=		perl5 pkgconfig
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
