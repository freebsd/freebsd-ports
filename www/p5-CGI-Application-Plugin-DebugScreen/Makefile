# New ports collection makefile for:	www/p5-CGI-Application-Plugin-DebugScreen
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-DebugScreen
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	This plug-in add DebugScreen support to CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/CGI/Application/Plugin/ViewCode.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-ViewCode \
		${SITE_PERL}/Devel/StackTrace.pm:${PORTSDIR}/devel/p5-Devel-StackTrace \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	CGI::Application::Plugin::DebugScreen.3

.include <bsd.port.mk>
