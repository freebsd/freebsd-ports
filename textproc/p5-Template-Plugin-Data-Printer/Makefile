PORTNAME=	Template-Plugin-DataPrinter
PORTVERSION=	0.015
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Template Toolkit dumper plugin using Data::Printer

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Printer>=1.000000:devel/p5-Data-Printer \
		p5-HTML-FromANSI-Tiny>=0:textproc/p5-HTML-FromANSI-Tiny \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
