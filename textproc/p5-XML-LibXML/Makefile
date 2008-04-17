# New ports collection makefile for:	XML::LibXML
# Date created:		28 May 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML
PORTVERSION=	1.66000
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Interface to Gnome libxml2 library

CONFLICTS=	p5-XML-LibXML-XPathContext-*

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML/Common.pm:${PORTSDIR}/textproc/p5-XML-LibXML-Common \
		${SITE_PERL}/XML/NamespaceSupport.pm:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.1+
CONFIGURE_ENV=	XMLPREFIX=${LOCALBASE}

PKGDEINSTALL=	${PKGINSTALL}

WRKSRC=		${WRKDIR}/${DISTNAME:C/00.$//}

MAN3=		XML::LibXML.3 XML::LibXML::Attr.3 XML::LibXML::Boolean.3 \
		XML::LibXML::CDATASection.3 XML::LibXML::Comment.3 \
		XML::LibXML::DOM.3 XML::LibXML::Document.3 \
		XML::LibXML::DocumentFragment.3 XML::LibXML::Dtd.3 \
		XML::LibXML::Element.3 XML::LibXML::InputCallback.3 \
		XML::LibXML::Literal.3 XML::LibXML::Namespace.3 \
		XML::LibXML::Node.3 XML::LibXML::NodeList.3 \
		XML::LibXML::Number.3 XML::LibXML::PI.3 XML::LibXML::Parser.3 \
		XML::LibXML::Reader.3 XML::LibXML::RelaxNG.3 XML::LibXML::SAX.3 \
		XML::LibXML::SAX::Builder.3 XML::LibXML::SAX::Generator.3 \
		XML::LibXML::Schema.3 XML::LibXML::Text.3 \
		XML::LibXML::XPathContext.3

post-install:
	@PKG_PREFIX=${PREFIX} ${PERL} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
