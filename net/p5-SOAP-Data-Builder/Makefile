# New ports collection makefile for:	p5-SOAP-Data-Builder
# Date created:			17 January 2004
# Whom:				kungfuftr <scott@surreytech.co.uk>
#
# $FreeBSD$
#

PORTNAME=	SOAP-Data-Builder
PORTVERSION=	0.9
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A wrapper simplifying SOAP::Data and SOAP::Serialiser

BUILD_DEPENDS=	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	SOAP::Data::Builder.3 SOAP::Data::Builder::Element.3

.include <bsd.port.mk>
