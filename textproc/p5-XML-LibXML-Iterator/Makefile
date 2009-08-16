# New ports collection makefile for:	p5-XML-LibXML-Iterator
# Date created:				11 Sep 2003
# Whom:					Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-Iterator
PORTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XML::LibXML::Iterator is an iterator for XML::LibXML parsed documents

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/NodeFilter.pm:${PORTSDIR}/textproc/p5-XML-NodeFilter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::LibXML::Iterator.3 XML::LibXML::NodeList::Iterator.3

.include <bsd.port.mk>
