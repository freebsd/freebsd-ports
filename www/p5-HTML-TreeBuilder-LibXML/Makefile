# New ports collection makefile for:	p5-HTML-TreeBuilder-LibXML
# Date created:		2009-04-16
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	HTML-TreeBuilder-LibXML
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	HTML::TreeBuilder::XPath compatible interface with libxml

BUILD_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-HTML-TreeBuilder-XPath>=0:${PORTSDIR}/www/p5-HTML-TreeBuilder-XPath \
		p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::TreeBuilder::LibXML::Node.3 \
		HTML::TreeBuilder::LibXML.3

.include <bsd.port.mk>
