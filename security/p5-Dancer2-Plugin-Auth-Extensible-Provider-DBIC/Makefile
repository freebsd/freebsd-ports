PORTNAME=	Dancer2-Plugin-Auth-Extensible-Provider-DBIC
PORTVERSION=	0.624
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible authentication framework for Dancer2 apps using DBIC

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Dancer2-Plugin-Auth-Extensible>=0.708:security/p5-Dancer2-Plugin-Auth-Extensible \
		p5-Dancer2-Plugin-DBIC>=0.0012:databases/p5-Dancer2-Plugin-DBIC \
		p5-Dancer2>=0.200000:www/p5-Dancer2 \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Moo>=0:devel/p5-Moo \
		p5-String-CamelCase>=0:textproc/p5-String-CamelCase \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
