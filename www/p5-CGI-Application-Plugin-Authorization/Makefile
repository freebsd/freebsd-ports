# New ports collection makefile for:	www/p5-CGI-Application-Plugin-Authorization
# Date created:				01 September 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-Authorization
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Support for authorization of requests in CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/CGI/Application/Plugin/Authentication.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-Authentication \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Plugin::Authorization::Driver::Generic.3 \
	CGI::Application::Plugin::Authorization::Driver.3 \
	CGI::Application::Plugin::Authorization::Driver::DBI.3 \
	CGI::Application::Plugin::Authorization::Driver::Dummy.3 \
	CGI::Application::Plugin::Authorization::Driver::SimpleGroup.3 \
	CGI::Application::Plugin::Authorization.3 \
	CGI::Application::Plugin::Authorization::Driver::HTGroup.3

.include <bsd.port.mk>
