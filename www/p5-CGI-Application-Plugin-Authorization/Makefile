# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-Authorization
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support for authorization of requests in CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-CGI-Application-Plugin-Authentication>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Authentication \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	CGI::Application::Plugin::Authorization::Driver::Generic.3 \
	CGI::Application::Plugin::Authorization::Driver.3 \
	CGI::Application::Plugin::Authorization::Driver::DBI.3 \
	CGI::Application::Plugin::Authorization::Driver::Dummy.3 \
	CGI::Application::Plugin::Authorization::Driver::SimpleGroup.3 \
	CGI::Application::Plugin::Authorization.3 \
	CGI::Application::Plugin::Authorization::Driver::HTGroup.3

.include <bsd.port.mk>
