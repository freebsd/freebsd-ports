# New ports collection makefile for:	www/p5-CGI-Application-Dispatch-Server
# Date created:				5 June 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Dispatch-Server
PORTVERSION=	0.53
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	A simple HTTP server for developing with CGI::Application::Dispatch

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/IO/Capture/Stdout.pm:${PORTSDIR}/devel/p5-IO-Capture \
		${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Dispatch.pm:${PORTSDIR}/www/p5-CGI-Application-Dispatch \
		${SITE_PERL}/HTTP/Server/Simple/CGI.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/HTTP/Server/Simple/Static.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple-Static \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Dispatch::Server.3

.include <bsd.port.mk>
