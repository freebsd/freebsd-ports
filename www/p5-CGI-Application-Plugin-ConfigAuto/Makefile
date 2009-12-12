# New ports collection makefile for:	p5-CGI-Application-Plugin-ConfigAuto
# Date created:				February 15th 2009
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-ConfigAuto
PORTVERSION=	1.30
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin that adds Config::Auto support to CGI::Application

RUN_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Config/Auto.pm:${PORTSDIR}/devel/p5-Config-Auto
BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Config/Auto.pm:${PORTSDIR}/devel/p5-Config-Auto

PERL_MODBUILD=	5.8.0+

MAN3=		CGI::Application::Plugin::ConfigAuto.3

.include <bsd.port.mk>
