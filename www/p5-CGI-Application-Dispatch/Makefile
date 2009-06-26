# New ports collection makefile for:	www/p5-CGI-Application-Dispatch
# Date created:				5 June 2008
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Dispatch
PORTVERSION=	2.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Dispatch requests to CGI::Application based objects

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Exception/Class/TryCatch.pm:${PORTSDIR}/devel/p5-Exception-Class-TryCatch \
		${SITE_PERL}/Test/LongString.pm:${PORTSDIR}/devel/p5-Test-LongString

PERL_MODBUILD=	yes

MAN3=	CGI::Application::Dispatch.3 \
	CGI::Application::Dispatch::Regexp.3

.include <bsd.port.mk>
