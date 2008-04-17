# New ports collection makefile for:	www/p5-CGI-Application-Plugin-AutoRunmode
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-AutoRunmode
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	CGI::App plugin to automatically register runmodes

RUN_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	CGI::Application::Plugin::AutoRunmode.3 \
    	CGI::Application::Plugin::AutoRunmode::FileDelegate.3

.include <bsd.port.mk>
