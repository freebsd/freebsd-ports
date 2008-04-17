# New ports collection makefile for:	www/p5-CGI-Application-Plugin-Redirect
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-Redirect
PORTVERSION=	0.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Easy external redirects in CGI::Application

RUN_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::Redirect.3

.include <bsd.port.mk>
