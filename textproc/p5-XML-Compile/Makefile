PORTNAME=	XML-Compile
PORTVERSION=	1.63
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compilation based XML processing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Report>=1.20:devel/p5-Log-Report \
		p5-Types-Serialiser>=0:devel/p5-Types-Serialiser \
		p5-XML-LibXML>=2.0107:textproc/p5-XML-LibXML
TEST_DEPENDS=	p5-Test-Deep>=0.095:devel/p5-Test-Deep \
		p5-XML-Compile-Tester>=0.90:devel/p5-XML-Compile-Tester

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
