PORTNAME=	Business-Hours
PORTVERSION=	0.13
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Calculate business hours during a time period

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Set-IntSpan>1.12:math/p5-Set-IntSpan
TEST_DEPENDS=	p5-Test-Pod>-1.0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
