# New ports collection makefile for:	www/p5-CGI-Application-Plugin-Forward
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-Forward
PORTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Support for forwarding requests in CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Plugin/AutoRunmode.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-AutoRunmode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::Forward.3

.include <bsd.port.mk>
