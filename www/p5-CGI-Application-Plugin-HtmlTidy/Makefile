# New ports collection makefile for:	www/p5-CGI-Application-Plugin-HtmlTidy
# Date created:				14 September 2005
# Whom:					George Hartzell <hartzell@alerce.com>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-HtmlTidy
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hartzell@alerce.com
COMMENT=	Add HTML::Tidy support to CGI::Application

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CGI/Application/Plugin/DevPopup.pm:${PORTSDIR}/www/p5-CGI-Application-Plugin-DevPopup \
		${SITE_PERL}/${PERL_ARCH}/HTML/Tidy.pm:${PORTSDIR}/textproc/p5-HTML-Tidy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	CGI::Application::Plugin::HtmlTidy.3

.include <bsd.port.mk>
