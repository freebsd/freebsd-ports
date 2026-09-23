PORTNAME=	Crypt-Random-Source
DISTVERSION=	0.12
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	dereckson@gmail.com
COMMENT=	Get weak or strong random data from pluggable sources
WWW=		https://metacpan.org/release/Crypt-Random-Source

LICENSE=	ART20

BUILD_RUN_DEPENDS=	p5-Moo>=1.002000:devel/p5-Moo \
		p5-Capture-Tiny>=0.08:devel/p5-Capture-Tiny \
		p5-Module-Find>=0:devel/p5-Module-Find \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Type-Tiny>=1.000005:devel/p5-Type-Tiny \
		p5-namespace-clean>=0.08:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
