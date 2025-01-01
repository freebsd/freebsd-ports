PORTNAME=	PDF-WebKit
PORTVERSION=	1.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use WebKit to Generate PDFs from HTML
WWW=		https://metacpan.org/release/PDF-WebKit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Depends on expired converters/wkhtmltopdf
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	p5-IPC-Run3>=0:devel/p5-IPC-Run3 \
		p5-Moo>=0:devel/p5-Moo \
		p5-XML-LibXML>=1.62:textproc/p5-XML-LibXML \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		wkhtmltopdf:converters/wkhtmltopdf
TEST_DEPENDS=	p5-Test-Spec:devel/p5-Test-Spec

USE_PERL5=	configure
USES=		perl5
NO_ARCH=	yes

.include <bsd.port.mk>
