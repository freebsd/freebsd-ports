# Created by: Andrew Humphrey <ahumphrey@realestate.com.au>
# $FreeBSD$

PORTNAME=	XML-Filter-DOMFilter-LibXML
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahumphrey@realestate.com.au
COMMENT=	Perl SAX Filter allowing DOM processing of selected subtrees

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
