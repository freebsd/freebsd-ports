# New ports collection makefile for:	XML::XPath
# Date created:		11 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-XPath
PORTVERSION=	1.13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Modules for parsing and evaluating XPath statements

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::XPath.3 XML::XPath::Boolean.3 XML::XPath::Builder.3 \
		XML::XPath::Literal.3 XML::XPath::Node.3 \
		XML::XPath::Node::Attribute.3 XML::XPath::Node::Comment.3 \
		XML::XPath::Node::Element.3 XML::XPath::Node::Namespace.3 \
		XML::XPath::Node::PI.3 XML::XPath::Node::Text.3 \
		XML::XPath::NodeSet.3 XML::XPath::Number.3 \
		XML::XPath::PerlSAX.3 XML::XPath::XMLParser.3


.include <bsd.port.mk>
