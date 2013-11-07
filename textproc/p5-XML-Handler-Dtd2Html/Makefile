# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	XML-Handler-Dtd2Html
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SAX2 handler for generate a Html documentation from a DTD

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-HTML-Template>=2.8:${PORTSDIR}/www/p5-HTML-Template \
		p5-XML-Parser>=2.3:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX-Expat>=0.37:${PORTSDIR}/textproc/p5-XML-SAX-Expat \
		p5-XML-SAX-Writer>=0.44:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-libxml>=0.08:${PORTSDIR}/textproc/p5-libxml
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
