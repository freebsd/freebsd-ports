# New ports collection makefile for:	p5-SOAP-Data-Builder
# Date created:			17 January 2004
# Whom:				kungfuftr <scott@surreytech.co.uk>
#
# $FreeBSD$
#

PORTNAME=	SOAP-Data-Builder
PORTVERSION=	0.6
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SOAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	scott@surreytech.co.uk
COMMENT=	A wrapper simplifying SOAP::Data and SOAP::Serialiser

BUILD_DEPENDS=	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	SOAP::Data::Builder.3 SOAP::Data::Builder::Element.3

.include <bsd.port.mk>
