PORTNAME=	PDL-Graphics-Limits
PORTVERSION=	0.03
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Derive limits for display purposes
WWW=		https://metacpan.org/dist/PDL-Graphics-Limits

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=2.095:math/p5-PDL \
		p5-PDL-Fit>=0:math/p5-PDL-Fit
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
