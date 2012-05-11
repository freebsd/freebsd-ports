# New ports collection makefile for:	www/p5-CGI-Application-Server
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Server
PORTVERSION=	0.062
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple HTTP server for developing with CGI::Application

BUILD_DEPENDS=	p5-CGI-Application-Plugin-Redirect>=0:${PORTSDIR}/www/p5-CGI-Application-Plugin-Redirect \
		p5-HTTP-Server-Simple-Static>=0.02:${PORTSDIR}/www/p5-HTTP-Server-Simple-Static \
		p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		p5-Test-WWW-Mechanize>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Server.3

.include <bsd.port.mk>
