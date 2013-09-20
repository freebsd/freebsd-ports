# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	HTML-TreeBuilder-LibXML
PORTVERSION=	0.23
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	HTML::TreeBuilder::XPath compatible interface with libxml

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add p5-Web-Scraper to TEST_DEPENDS to avoid cyclic dependency loop
BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-HTML-TreeBuilder-XPath>=0.14:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-XML-LibXML>=1.70:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Web-Query>=0:${PORTSDIR}/www/p5-Web-Query

USES=		perl5
USE_PERL5=	modbuild

MAN3=		HTML::TreeBuilder::LibXML::Node.3 \
		HTML::TreeBuilder::LibXML.3

NO_STAGE=	yes
.include <bsd.port.mk>
