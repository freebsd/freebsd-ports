PORTNAME=	Math-BigInt-FastCalc
PORTVERSION=	0.5018
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Math::BigInt::Calc with some XS for more speed
WWW=		https://metacpan.org/release/Math-BigInt-FastCalc

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Math-BigInt>=2.003001:math/p5-Math-BigInt

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/BigInt/FastCalc/FastCalc.so

.include <bsd.port.mk>
