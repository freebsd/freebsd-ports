PORTNAME=	XML-Compile-WSDL11
PORTVERSION=	3.08
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create SOAP messages defined by WSDL 1.1

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Report>=1.05:devel/p5-Log-Report \
		p5-XML-Compile>=1.48:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=1.03:textproc/p5-XML-Compile-Cache \
		p5-XML-Compile-SOAP>=3.23:net/p5-XML-Compile-SOAP \
		p5-XML-Compile-Tester>=0:devel/p5-XML-Compile-Tester

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
