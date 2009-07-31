# New ports collection makefile for:	CGI-Application
# Date created:				Mon Jan  1 10:52:22 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-Application
PORTVERSION=	4.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module intended to make it easier to create reusable web apps

RUN_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template

PERL_CONFIGURE=	yes

MAN3=		CGI::Application.3 CGI::Application::Mailform.3

.include <bsd.port.mk>
