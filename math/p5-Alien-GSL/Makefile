PORTNAME=	Alien-GSL
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Detect and get configuration setting for GSL
WWW=		https://metacpan.org/release/Alien-GSL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libgsl.so:math/gsl
BUILD_DEPENDS=	p5-Alien-Build>=2.21:devel/p5-Alien-Build \
		p5-PkgConfig>0:devel/p5-PkgConfig
RUN_DEPENDS=	p5-Alien-Build>=2.21:devel/p5-Alien-Build
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Alien-Build>=0:devel/p5-Alien-Build

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
