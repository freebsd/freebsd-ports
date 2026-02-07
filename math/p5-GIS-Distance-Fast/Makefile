PORTNAME=	GIS-Distance-Fast
PORTVERSION=	0.16
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C implementation of GIS::Distance formulas
WWW=		https://metacpan.org/release/GIS-Distance-Fast

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-namespace-clean>=0.24:devel/p5-namespace-clean \
		p5-strictures>=2.000000:devel/p5-strictures
TEST_DEPENDS=	p5-GIS-Distance>=0.17:math/p5-GIS-Distance \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuildtiny

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/GIS/Distance/Fast/Fast.so

.include <bsd.port.mk>
