# New ports collection makefile for:	www/p5-CGI-Application-Plugin-DevPopup
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-DevPopup
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Runtime cgiapp info in a popup window

BUILD_DEPENDS=	p5-CGI-Application>=4.01:${PORTSDIR}/www/p5-CGI-Application
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	CGI::Application::Plugin::DevPopup.3 \
	CGI::Application::Plugin::DevPopup::HTTPHeaders.3 \
	CGI::Application::Plugin::DevPopup::Timing.3 \
	CGI::Application::Plugin::DevPopup::Log.3

.include <bsd.port.mk>
