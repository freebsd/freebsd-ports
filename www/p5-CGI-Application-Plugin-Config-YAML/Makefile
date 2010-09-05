# New ports collection makefile for:	p5-CGI-Application-Plugin-Config-YAML
# Date created:		2010-03-03
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-Config-YAML
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Add Config::YAML support to CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>4.01:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Config/YAML.pm:${PORTSDIR}/devel/p5-Config-YAML
RUN_DEPENDS=	p5-CGI-Application>4.01:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Config/YAML.pm:${PORTSDIR}/devel/p5-Config-YAML

PERL_CONFIGURE=	yes

MAN3=	CGI::Application::Plugin::Config::YAML.3

.include <bsd.port.mk>
