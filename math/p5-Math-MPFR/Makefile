# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Math-MPFR
PORTVERSION=	3.36
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to MPFR Library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
TEST_DEPENDS=	p5-Math-GMP>=0:math/p5-Math-GMP \
		p5-Math-GMPf>=0:math/p5-Math-GMPf \
		p5-Math-GMPq>=0:math/p5-Math-GMPq \
		p5-Math-GMPz>=0:math/p5-Math-GMPz

USE_PERL5=	configure
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/MPFR/MPFR.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/MPFR/Prec/Prec.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/MPFR/Random/Random.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/MPFR/V/V.so

.include <bsd.port.mk>
