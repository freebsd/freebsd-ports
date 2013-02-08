# $FreeBSD$

PORTNAME=	Template-Semantic
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to use pure XHTML/XML as a template

RUN_DEPENDS=	\
	p5-HTML-Selector-XPath>=0.09:${PORTSDIR}/www/p5-HTML-Selector-XPath \
	p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Text-Pipe>0:${PORTSDIR}/textproc/p5-Text-Pipe

PERL_CONFIGURE=	yes

MAN3=	Template::Semantic.3 \
	Template::Semantic::Cookbook.3 \
	Template::Semantic::Document.3 \
	Template::Semantic::Filter.3

.include <bsd.port.mk>
