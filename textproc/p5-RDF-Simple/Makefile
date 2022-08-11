PORTNAME=	RDF-Simple
PORTVERSION=	0.421
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write RDF without complication

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-IO-CaptureOutput>=0:devel/p5-IO-CaptureOutput \
		p5-Test-File>=0:devel/p5-Test-File

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
