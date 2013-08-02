# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-XPath
PORTVERSION=	1.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules for parsing and evaluating XPath statements

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::XPath.3 XML::XPath::Boolean.3 XML::XPath::Builder.3 \
		XML::XPath::Literal.3 XML::XPath::Node.3 \
		XML::XPath::Node::Attribute.3 XML::XPath::Node::Comment.3 \
		XML::XPath::Node::Element.3 XML::XPath::Node::Namespace.3 \
		XML::XPath::Node::PI.3 XML::XPath::Node::Text.3 \
		XML::XPath::NodeSet.3 XML::XPath::Number.3 \
		XML::XPath::PerlSAX.3 XML::XPath::XMLParser.3


.include <bsd.port.mk>
