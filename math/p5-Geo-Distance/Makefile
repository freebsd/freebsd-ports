PORTNAME=	Geo-Distance
PORTVERSION=	0.25
CATEGORIES=	math perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate Distances and Closest Locations
WWW=		https://metacpan.org/release/Geo-Distance

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Const-Fast>=0.014:devel/p5-Const-Fast \
		p5-GIS-Distance>=0.14:math/p5-GIS-Distance
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
