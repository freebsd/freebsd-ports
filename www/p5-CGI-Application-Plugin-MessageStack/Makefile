# New ports collection makefile for:	www/p5-CGI-Application-Plugin-MessageStack
# Date created:				15 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-MessageStack
PORTVERSION=	0.34
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	A message stack for your CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Plugin/Session.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-Session \
		${SITE_PERL}/CGI/Application/Plugin/TT.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-TT
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::MessageStack.3

.include <bsd.port.mk>
