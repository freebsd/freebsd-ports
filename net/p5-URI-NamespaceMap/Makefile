PORTNAME=	URI-NamespaceMap
PORTVERSION=	1.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Namespace URI/IRI class with autoload methods
WWW=		https://metacpan.org/dist/URI-NamespaceMap

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IRI>=0.004:devel/p5-IRI \
		p5-Moo>=1.006000:devel/p5-Moo \
		p5-Sub-Quote>=0:devel/p5-Sub-Quote \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Type-Tiny>=1.000000:devel/p5-Type-Tiny \
		p5-Types-URI>=0.004:devel/p5-Types-URI \
		p5-URI>=1.52:net/p5-URI \
		p5-namespace-autoclean>=0.20:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
