PORTNAME=	Math-GSL-Alien
DISTVERSION=	1.05
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAKONH
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Easy installation of the GSL library
WWW=		https://metacpan.org/release/Math-GSL-Alien

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

_BR_DEPENDS=	p5-Alien-Build>=2.21:devel/p5-Alien-Build \
		p5-Alien-Role-Dino>0:devel/p5-Alien-Role-Dino
BUILD_DEPENDS=	${_BR_DEPENDS}
LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	${_BR_DEPENDS}

USES=		perl5 pkgconfig
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
