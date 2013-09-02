# New ports collection makefile for:	p5-CGI-Application-Plugin-JSON
# Date created:		2010-03-03
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-JSON
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Easy manipulation of JSON headers for CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>4.01:${PORTSDIR}/www/p5-CGI-Application \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any
RUN_DEPENDS=	p5-CGI-Application>4.01:${PORTSDIR}/www/p5-CGI-Application \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any

USES=		perl5
USE_PERL5=	modbuild

MAN3=	CGI::Application::Plugin::JSON.3

.include <bsd.port.mk>
