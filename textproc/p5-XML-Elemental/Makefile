# New ports collection makefile for:	p5-XML-Elemental
# Date created:				2004-10-11
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-Elemental
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic classes for simplistic and perlish handling of XML data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	yes

MAN3=	XML::Parser::Style::Elemental.3 XML::Elemental::Node.3 \
	XML::Elemental::Element.3 XML::Elemental::Characters.3 \
	XML::Elemental::Document.3 XML::Elemental.3

.include <bsd.port.mk>
