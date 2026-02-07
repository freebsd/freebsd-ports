PORTNAME=	PDL-Fit
PORTVERSION=	2.100
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Various fitting implementations for PDL
WWW=		https://metacpan.org/dist/PDL-Fit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=2.094:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Fit/Gaussian/Gaussian.so

.include <bsd.port.mk>
