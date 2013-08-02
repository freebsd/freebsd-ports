# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-LibXML
PORTVERSION=	2.0018
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Gnome libxml2 library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-NamespaceSupport>=1.07:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0.11:${PORTSDIR}/textproc/p5-XML-SAX
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	p5-XML-NamespaceSupport>=1.07:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0.11:${PORTSDIR}/textproc/p5-XML-SAX

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	XMLPREFIX=${LOCALBASE}

PKGDEINSTALL=	${PKGINSTALL}

CONFLICTS=	p5-XML-LibXML-XPathContext-[0-9]* p5-XML-LibXML-Common-[0-9]*

MAN3=		XML::LibXML.3 XML::LibXML::AttributeHash.3 \
		XML::LibXML::Attr.3 XML::LibXML::Boolean.3 \
		XML::LibXML::CDATASection.3 XML::LibXML::Comment.3 \
		XML::LibXML::Devel.3 \
		XML::LibXML::DOM.3 XML::LibXML::Document.3 \
		XML::LibXML::DocumentFragment.3 XML::LibXML::Dtd.3 \
		XML::LibXML::Element.3 XML::LibXML::ErrNo.3 \
		XML::LibXML::Error.3 XML::LibXML::InputCallback.3 \
		XML::LibXML::Literal.3 XML::LibXML::Namespace.3 \
		XML::LibXML::Node.3 XML::LibXML::NodeList.3 \
		XML::LibXML::Number.3 XML::LibXML::PI.3 XML::LibXML::Parser.3 \
		XML::LibXML::Pattern.3 XML::LibXML::Reader.3 \
		XML::LibXML::RelaxNG.3 XML::LibXML::SAX.3 \
		XML::LibXML::SAX::Builder.3 XML::LibXML::SAX::Generator.3 \
		XML::LibXML::Schema.3 XML::LibXML::Text.3 \
		XML::LibXML::XPathContext.3 \
		XML::LibXML::XPathExpression.3 \
		XML::LibXML::Common.3 XML::LibXML::RegExp.3

.include <bsd.port.mk>
