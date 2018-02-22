# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	PDF-WebKit
PORTVERSION=	1.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use WebKit to Generate PDFs from HTML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

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
