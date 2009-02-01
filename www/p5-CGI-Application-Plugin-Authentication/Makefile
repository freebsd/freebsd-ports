# New ports collection makefile for:	www/p5-CGI-Application-Plugin-Authentication
# Date created:				01 September 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-Authentication
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Support for authenticating requests in CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Plugin/Session.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-Session \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA \
		${SITE_PERL}/Attribute/Handlers.pm:${PORTSDIR}/devel/p5-Attribute-Handlers \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::Authentication::Driver.3 \
	CGI::Application::Plugin::Authentication::Driver::Filter::strip.3 \
	CGI::Application::Plugin::Authentication::Driver::DBI.3 \
	CGI::Application::Plugin::Authentication::Driver::Filter::sha1.3 \
	CGI::Application::Plugin::Authentication::Driver::Filter::lc.3 \
	CGI::Application::Plugin::Authentication::Store::Session.3 \
	CGI::Application::Plugin::Authentication.3 \
	CGI::Application::Plugin::Authentication::Driver::Filter::uc.3 \
	CGI::Application::Plugin::Authentication::Driver::Filter::crypt.3 \
	CGI::Application::Plugin::Authentication::Store.3 \
	CGI::Application::Plugin::Authentication::Driver::Generic.3 \
	CGI::Application::Plugin::Authentication::Store::Cookie.3 \
	CGI::Application::Plugin::Authentication::Driver::Authen::Simple.3 \
	CGI::Application::Plugin::Authentication::Driver::Filter::md5.3 \
	CGI::Application::Plugin::Authentication::Driver::HTPasswd.3 \
	CGI::Application::Plugin::Authentication::Driver::Dummy.3

.include <bsd.port.mk>
