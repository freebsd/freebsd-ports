# New ports collection makefile for:	www/p5-CGI-Application-Plugin-HTMLPrototype
# Date created:				15 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-HTMLPrototype
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Access to the prototype JavaScript library using HTML::Prototype

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/HTML/Prototype.pm:${PORTSDIR}/www/p5-HTML-Prototype
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	CGI::Application::Plugin::HTMLPrototype.3

.include <bsd.port.mk>
