# New ports collection makefile for:	textproc/p5-XML-Mini
# Date created:				12-JUL-2006
# Whom:					Vivek Khera <vivek@khera.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Mini
PORTVERSION=	1.2.8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	vivek@khera.org
COMMENT=	Perl implementation of the XML::Mini XML create/parse interface

PERL_CONFIGURE=	yes

RUN_DEPENDS+=	p5-Text-Balanced>=0.0:${PORTSDIR}/textproc/p5-Text-Balanced

MAN3=	XML::Mini.3 XML::Mini::Document.3 XML::Mini::Element.3 \
	XML::Mini::Element::CData.3 XML::Mini::Element::Comment.3 \
	XML::Mini::Element::DocType.3 XML::Mini::Element::Entity.3 \
	XML::Mini::Element::Header.3 XML::Mini::Node.3 \
	XML::Mini::TreeComponent.3

.include <bsd.port.mk>
