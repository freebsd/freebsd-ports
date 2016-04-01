# $FreeBSD$

PORTNAME=	Template-Semantic
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to use pure XHTML/XML as a template

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-HTML-Selector-XPath>=0.09:www/p5-HTML-Selector-XPath \
	p5-XML-LibXML>=1.69:textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Text-Pipe>0:textproc/p5-Text-Pipe

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
