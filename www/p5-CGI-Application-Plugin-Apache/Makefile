# New ports collection makefile for:	p5-CGI-Application-Plugin-Apache
# Date created:		2010-11-18
# Whom:			Kurt Lidl <kurt.lidl@cello.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-Apache
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides easy access to Apache::* modules for CGI::Application

RUN_DEPENDS=	p5-CGI-Application>=3.22:${PORTSDIR}/www/p5-CGI-Application \
		p5-HTML-GenerateUtil>=0:${PORTSDIR}/www/p5-HTML-GenerateUtil \
		p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		CGI::Application::Plugin::Apache.3 \
		CGI::Application::Plugin::Apache::Request.3 \
		CGI::Application::Plugin::Apache2::Request.3

.include <bsd.port.mk>
