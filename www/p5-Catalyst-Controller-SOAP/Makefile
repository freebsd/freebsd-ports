# Created by: citrin+bsd@citrin.ru
# $FreeBSD$

PORTNAME=	Catalyst-Controller-SOAP
PORTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst SOAP Controller

LICENSE=	ARTPERL10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.90017:www/p5-Catalyst-Runtime \
		p5-Moose>=0.9:devel/p5-Moose \
		p5-XML-Compile-SOAP>=2.35:net/p5-XML-Compile-SOAP \
		p5-XML-Compile-WSDL11>=0:net/p5-XML-Compile-WSDL11 \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
