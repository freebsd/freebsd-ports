# Created by: citrin+bsd@citrin.ru
# $FreeBSD$

PORTNAME=	Catalyst-Controller-SOAP
PORTVERSION=	1.25
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	citrin+bsd@citrin.ru
COMMENT=	Catalyst SOAP Controller

LICENSE=	ARTPERL10

BUILD_DEPENDS=	\
		p5-Catalyst-Runtime>=5.90017:www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Moose>=0.9:devel/p5-MRO-Compat \
		p5-XML-Compile-SOAP>=2.35:net/p5-XML-Compile-SOAP \
		p5-XML-Compile-WSDL11>=0:net/p5-XML-Compile-WSDL11 \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
