# New ports collection makefile for:	XML::LibXML
# Date created:		28 May 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML
PORTVERSION=	0.97
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2'

MAN3=		XML::LibXML::Element.3 XML::LibXML::CDATASection.3 \
		XML::LibXML::Comment.3 XML::LibXML::Text.3 XML::LibXML.3 \
		XML::LibXML::Node.3 XML::LibXML::Document.3 \
		XML::LibXML::Dtd.3 XML::LibXML::Namespace.3 \
		XML::LibXML::DocumentFragment.3 XML::LibXML::Attr.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
