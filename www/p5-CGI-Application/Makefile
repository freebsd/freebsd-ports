# New ports collection makefile for:	CGI-Application
# Date created:				Mon Jan  1 10:52:22 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-Application
PORTVERSION=	3.1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Perl module intended to make it easier to create reusable web apps

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/CGI/Base.pm:${PORTSDIR}/www/p5-CGI-modules \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Application.3 CGI::Application::Mailform.3

.include <bsd.port.mk>
