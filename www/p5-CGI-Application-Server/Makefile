# New ports collection makefile for:	www/p5-CGI-Application-Server
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Server
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	A simple HTTP server for developing with CGI::Application

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/Capture/Stdout.pm:${PORTSDIR}/devel/p5-IO-Capture \
		${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/HTTP/Server/Simple/Static.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple-Static
BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Test/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		${SITE_PERL}/Test/WWW/Mechanize.pm:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		${SITE_PERL}/CGI/Application/Plugin/Redirect.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-Redirect

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Server.3

.include <bsd.port.mk>
