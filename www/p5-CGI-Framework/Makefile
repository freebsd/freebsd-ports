# New ports collection makefile for:	p5-CGI-Framework
# Date created:				25 feb 2004
# Whom:	      				Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Framework
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A simple-to-use, lightweight web CGI framework

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Framework.3

.include <bsd.port.mk>
