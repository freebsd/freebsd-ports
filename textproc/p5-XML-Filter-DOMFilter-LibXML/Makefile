# New ports collection makefile for:   p5-XML-Filter-DOMFilter-LibXML
# Date created:        24 October 2005
# Whom:                Andrew Humphrey <ahumphrey@realestate.com.au>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-DOMFilter-LibXML
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahumphrey@realestate.com.au
COMMENT=	Perl SAX Filter allowing DOM processing of selected subtrees

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Filter::DOMFilter::LibXML.3

.include <bsd.port.mk>
