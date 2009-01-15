# New ports collection makefile for:	p5-XML-DOM2
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-DOM2
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	DOM controlled, strict XML module for extentable xml objects

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::DOM2::Attribute.3 XML::DOM2::Element.3 \
		XML::DOM2::Element::Document.3 \
		XML::DOM2::Element::DocumentType.3 XML::DOM2.3 \
		XML::DOM2::DOM::Document.3 XML::DOM2::Parser.3 \
		XML::DOM2::Attribute::Namespace.3 XML::DOM2::XPath.3 \
		XML::DOM2::DOM::NameSpace.3 XML::DOM2::Element::CDATA.3 \
		XML::DOM2::DOM::Element.3 XML::DOM2::Element::Comment.3 \
		XML::DOM2::DOM::Attribute.3

.include <bsd.port.mk>
