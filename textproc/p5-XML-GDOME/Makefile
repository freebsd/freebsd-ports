# New ports collection makefile for:	XML::GDOME
# Date created:		2003-10-02
# Whom:			Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-GDOME
PORTVERSION=	0.83
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	se@FreeBSD.org
COMMENT=	Perl module that provides the DOM Level 2 Core API for XML documents

LIB_DEPENDS=	gdome.8:${PORTSDIR}/textproc/gdome2
RUN_DEPENDS=	${SITE_PERL}/XML/SAX/Base.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML/Common.pm:${PORTSDIR}/textproc/p5-XML-LibXML-Common
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::GDOME.3 \
		XML::GDOME::Attr.3 \
		XML::GDOME::CDATASection.3 \
		XML::GDOME::CharacterData.3 \
		XML::GDOME::Comment.3 \
		XML::GDOME::Document.3 \
		XML::GDOME::DocumentFragment.3 \
		XML::GDOME::DocumentType.3 \
		XML::GDOME::Element.3 \
		XML::GDOME::Entity.3 \
		XML::GDOME::EntityReference.3 \
		XML::GDOME::NamedNodeMap.3 \
		XML::GDOME::Node.3 \
		XML::GDOME::NodeList.3 \
		XML::GDOME::Notation.3 \
		XML::GDOME::SAX::Builder.3 \
		XML::GDOME::SAX::Generator.3 \
		XML::GDOME::SAX::Parser.3 \
		XML::GDOME::Text.3 \
		XML::GDOME::XPath::Evaluator.3 \
		XML::GDOME::XPath::NSResolver.3 \
		XML::GDOME::XPath::Namespace.3 \
		XML::GDOME::XPath::Result.3 \
		XML::GDOME::ProcessingInstruction.3

post-patch:
	${PERL} -i -ne '/die "VERSION"/ or print' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
