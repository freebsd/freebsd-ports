PORTNAME=	Math-Prime-Util
PORTVERSION=	0.74
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANAJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities related to prime numbers, including fast sieves and factoring
WWW=		https://metacpan.org/release/Math-Prime-Util

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	p5-Math-Prime-Util-GMP>=0.50:math/p5-Math-Prime-Util-GMP

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP \
				p5-Math-GMPz>=0.68:math/p5-Math-GMPz \
				p5-Math-Prime-Util-GMP>=0.53:math/p5-Math-Prime-Util-GMP
RECOMMENDED_RUN_DEPENDS=p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP \
			p5-Math-GMPz>=0.68:math/p5-Math-GMPz \
			p5-Math-Prime-Util-GMP>=0.53:math/p5-Math-Prime-Util-GMP

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Prime/Util/Util.so

.include <bsd.port.mk>
