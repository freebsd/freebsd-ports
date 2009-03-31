# New ports collection makefile for:	www/p5-POE-Component-Server-SOAP
# Date created:				12 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-SOAP
PORTVERSION=	1.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Publish POE event handlers via SOAP over HTTP

BUILD_DEPENDS=	p5-SOAP-Lite>=0.55:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-POE-Component-Server-SimpleHTTP>=1.54:${PORTSDIR}/www/p5-POE-Component-Server-SimpleHTTP \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Server::SOAP.3 \
	POE::Component::Server::SOAP::Response.3

.include <bsd.port.mk>
