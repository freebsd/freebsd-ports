PORTNAME=	HTML-TreeBuilder-LibXML
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	HTML::TreeBuilder::XPath compatible interface with libxml
WWW=		https://metacpan.org/release/HTML-TreeBuilder-LibXML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Filter>=0:devel/p5-Filter \
		p5-HTML-TreeBuilder-XPath>=0.14:www/p5-HTML-TreeBuilder-XPath \
		p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML
TEST_DEPENDS=	p5-Web-Query>=0:www/p5-Web-Query \
		p5-Web-Scraper>=0.36:www/p5-Web-Scraper

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
