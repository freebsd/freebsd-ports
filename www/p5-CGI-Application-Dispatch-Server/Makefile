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

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture \
		p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CGI-Application-Dispatch>=0:${PORTSDIR}/www/p5-CGI-Application-Dispatch \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Static>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Static \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Dispatch::Server.3

.include <bsd.port.mk>
