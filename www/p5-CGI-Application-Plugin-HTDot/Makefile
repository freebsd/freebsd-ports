# New ports collection makefile for:	CGI::Application::Plugin::HTDot
# Date created:				05 March 2006
# Whom:					Espen Tagestad <espen@tagestad.no>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-Plugin-HTDot
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Enable "magic dot" notation in CGI::Application-derived applications

BUILD_DEPENDS=	${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/HTML/Template/Plugin/Dot.pm:${PORTSDIR}/www/p5-HTML-Template-Pluggable \
		${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Application::Plugin::HTDot.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		needs Perl 5.6.1 or above (lang/perl5.8)
.endif

.include <bsd.port.post.mk>
