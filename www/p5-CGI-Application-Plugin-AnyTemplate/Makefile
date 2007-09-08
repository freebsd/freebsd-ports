# New ports collection makefile for:	www/p5-CGI-Application-Plugin-AnyTemplate
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-AnyTemplate
PORTVERSION=	0.17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Use any templating system in CGI::Application

RUN_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Plugin/Forward.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-Forward
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::AnyTemplate.3 \
	CGI::Application::Plugin::AnyTemplate::Driver::HTMLTemplate.3 \
	CGI::Application::Plugin::AnyTemplate::Base.3 \
	CGI::Application::Plugin::AnyTemplate::Driver::TemplateToolkit.3 \
	CGI::Application::Plugin::AnyTemplate::ComponentHandler.3 \
	CGI::Application::Plugin::AnyTemplate::Driver::HTMLTemplatePluggable.3 \
	CGI::Application::Plugin::AnyTemplate::Driver::HTMLTemplateExpr.3 \
	CGI::Application::Plugin::AnyTemplate::Driver::Petal.3

.include <bsd.port.mk>
