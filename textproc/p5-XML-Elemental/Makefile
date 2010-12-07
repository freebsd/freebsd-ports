# New ports collection makefile for:	p5-XML-Elemental
# Date created:				2004-10-11
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-Elemental
PORTVERSION=	2.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic classes for simplistic and perlish handling of XML data

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-Task-Weaken>=1.02:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Elemental.3 \
	XML::Elemental::Characters.3 \
	XML::Elemental::Document.3 \
	XML::Elemental::Element.3 \
	XML::Elemental::Node.3 \
	XML::Elemental::SAXHandler.3 \
	XML::Elemental::Util.3 \
	XML::Parser::Style::Elemental.3

.include <bsd.port.mk>
