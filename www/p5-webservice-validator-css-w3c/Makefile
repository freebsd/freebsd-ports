# New ports collection makefile for:	p5-webservice-validator-css-w3c
# Date created:				Oct 10, 2005
# Whom:					toni.viemero@iki.fi
#
# $FreeBSD$
#

PORTNAME=	WebService-Validator-CSS-W3C
PORTVERSION=	0.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Experimental interface to the W3C CSS Validation online service

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/QueryParam.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WebService::Validator::CSS::W3C.3

.include <bsd.port.mk>
