# New ports collection makefile for:	CGI::Application::ValidateRM
# Date created:				30 Aug 2003
# Whom:					Manuel Rabade <mig@mig-29.net>
#
# $FreeBSD$
#

PORTNAME=	CGI-Application-ValidateRM
PORTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:S/eRM/e-RM/}-${PORTVERSION}

MAINTAINER=		mig@mig-29.net
COMMENT=		Help validate forms with the CGI::Application framework

RUN_DEPENDS=		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm \
			${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
			${SITE_PERL}/CGI/Carp.pm:${PORTSDIR}/www/p5-CGI.pm \
			${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
PERL_MODBUILD=		yes

MAN3=			CGI::Application::ValidateRM.3

.include <bsd.port.mk>
