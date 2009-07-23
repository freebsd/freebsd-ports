# New ports collection makefile for:	Apache2-SOAP
# Date Created:				26 January 2006
# Whom:					Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Apache2-SOAP
PORTVERSION=	0.73
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Apache2 mod_perl2 SOAP Server

BUILD_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2 \
	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+
USE_APACHE=	2.0+

MAN3=		Apache2::SOAP.3

.include <bsd.port.mk>
