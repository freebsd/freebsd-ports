# $FreeBSD$

PORTNAME=	XML-DOM
PORTVERSION=	1.44
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for building DOM Level 1 compliant document structures

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-XML-RegExp>=0:${PORTSDIR}/textproc/p5-XML-RegExp
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::DOM.3 XML::DOM::AttDef.3 XML::DOM::AttlistDecl.3 \
		XML::DOM::Attr.3 XML::DOM::CDATASection.3 \
		XML::DOM::CharacterData.3 XML::DOM::Comment.3 \
		XML::DOM::DOMImplementation.3 XML::DOM::Document.3 \
		XML::DOM::DocumentFragment.3 XML::DOM::DocumentType.3 \
		XML::DOM::Element.3 XML::DOM::ElementDecl.3 \
		XML::DOM::Entity.3 XML::DOM::EntityReference.3 \
		XML::DOM::NamedNodeMap.3 XML::DOM::Node.3 \
		XML::DOM::NodeList.3 XML::DOM::Notation.3 \
		XML::DOM::Parser.3 XML::DOM::PerlSAX.3 \
		XML::DOM::ProcessingInstruction.3 XML::DOM::Text.3 \
		XML::DOM::XMLDecl.3 XML::Handler::BuildDOM.3

NO_STAGE=	yes
.include <bsd.port.mk>
