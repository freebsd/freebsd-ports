# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-GMPf
PORTVERSION=	0.42
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to the GMP library floating point (mpf) functions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp
TEST_DEPENDS=	p5-Math-GMP>=0:math/p5-Math-GMP \
		p5-Test-Pod>=1:devel/p5-Test-Pod

USE_PERL5=	configure
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMPf/GMPf.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMPf/Random/Random.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMPf/V/V.so

.include <bsd.port.mk>
