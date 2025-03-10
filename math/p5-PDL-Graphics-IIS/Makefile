PORTNAME=	PDL-Graphics-IIS
PORTVERSION=	0.001
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Display PDL images on IIS devices (saoimage/ximtool)
WWW=		https://metacpan.org/dist/PDL-Graphics-IIS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=2.093:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Graphics/IIS/IIS.so

.include <bsd.port.mk>
