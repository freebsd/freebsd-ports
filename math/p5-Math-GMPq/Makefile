PORTNAME=	Math-GMPq
PORTVERSION=	0.67
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to the GMP library rational (mpq) functions
WWW=		https://metacpan.org/release/Math-GMPq

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp
TEST_DEPENDS=	p5-Math-GMP>=0:math/p5-Math-GMP \
		p5-Test-Pod>=1:devel/p5-Test-Pod

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMPq/GMPq.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMPq/Random/Random.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMPq/V/V.so

.include <bsd.port.mk>
