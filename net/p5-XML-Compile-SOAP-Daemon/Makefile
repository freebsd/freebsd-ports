# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Compile-SOAP-Daemon
PORTVERSION=	3.11
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for SOAP message servers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report>=0.90:devel/p5-Log-Report \
		p5-XML-Compile>=1.44:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=0.991:textproc/p5-XML-Compile-Cache \
		p5-XML-Compile-SOAP>=3.00:net/p5-XML-Compile-SOAP \
		p5-XML-Compile-WSDL11>=3.00:net/p5-XML-Compile-WSDL11
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-Compile-Tester>=0.90:devel/p5-XML-Compile-Tester

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
