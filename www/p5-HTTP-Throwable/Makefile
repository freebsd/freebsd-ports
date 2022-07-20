PORTNAME=	HTTP-Throwable
PORTVERSION=	0.027
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of strongly-typed, PSGI-friendly HTTP 1.1 exception libraries

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=1.004003:devel/p5-Moo \
		p5-MooX-StrictConstructor>=0:devel/p5-MooX-StrictConstructor \
		p5-Package-Variant>=1.002000:devel/p5-Package-Variant \
		p5-Plack>=0.9967:www/p5-Plack \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Throwable>=0.102080:devel/p5-Throwable \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0.003:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
