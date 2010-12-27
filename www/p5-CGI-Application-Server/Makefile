# New ports collection makefile for:	www/p5-CGI-Application-Server
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Server
PORTVERSION=	0.062
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	A simple HTTP server for developing with CGI::Application

RUN_DEPENDS= p5-CGI-Application-Plugin-Redirect>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Redirect \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture \
		p5-HTTP-Server-Simple-Static>=0.02:${PORTSDIR}/www/p5-HTTP-Server-Simple-Static

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Server.3

.include <bsd.port.mk>
