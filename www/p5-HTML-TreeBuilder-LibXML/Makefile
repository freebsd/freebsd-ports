# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	HTML-TreeBuilder-LibXML
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	HTML::TreeBuilder::XPath compatible interface with libxml

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add p5-Web-Query and p5-Web-Scraper to TEST_DEPENDS to avoid cyclic dependency loop
BUILD_DEPENDS=	p5-Filter>=0:devel/p5-Filter \
		p5-HTML-TreeBuilder-XPath>=0.14:www/p5-HTML-TreeBuilder-XPath \
		p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
