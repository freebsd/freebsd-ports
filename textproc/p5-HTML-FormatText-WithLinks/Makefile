PORTNAME=	HTML-FormatText-WithLinks
PORTVERSION=	0.15
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Perl5 module to convert HTML to text with links as footnotes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Format>=0:textproc/p5-HTML-Format \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-Pod>=1.00:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0.08:devel/p5-Test-Pod-Coverage \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
