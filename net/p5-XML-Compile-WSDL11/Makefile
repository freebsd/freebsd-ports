# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Compile-WSDL11
PORTVERSION=	3.04
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create SOAP messages defined by WSDL 1.1

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report>=1.05:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile>=1.48:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=1.03:${PORTSDIR}/textproc/p5-XML-Compile-Cache \
		p5-XML-Compile-SOAP>=3.06:${PORTSDIR}/net/p5-XML-Compile-SOAP
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
