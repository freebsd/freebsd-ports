PORTNAME=	XML-Schematron
PORTVERSION=	1.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the Schematron
WWW=		https://metacpan.org/release/XML-Schematron

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Check-ISA>=0:devel/p5-Check-ISA \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-NonMoose>=0:devel/p5-MooseX-NonMoose \
		p5-MooseX-Traits>=0:devel/p5-MooseX-Traits \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-XML-Filter-BufferText>=0:textproc/p5-XML-Filter-BufferText \
		p5-XML-SAX>=0:textproc/p5-XML-SAX
TEST_DEPENDS=	p5-XML-LibXML>=2.0203,1:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.99:textproc/p5-XML-LibXSLT \
		p5-XML-XPath>=1.47:textproc/p5-XML-XPath

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
