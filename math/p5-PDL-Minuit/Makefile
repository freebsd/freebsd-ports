PORTNAME=	PDL-Minuit
PORTVERSION=	0.001
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDL interface to the Minuit library
WWW=		https://metacpan.org/dist/PDL-Minuit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PDL>=2.093:math/p5-PDL \
		p5-ExtUtils-F77>=1.26:lang/p5-ExtUtils-F77 \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=2.093:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Minuit/Minuit.so

.include <bsd.port.mk>
