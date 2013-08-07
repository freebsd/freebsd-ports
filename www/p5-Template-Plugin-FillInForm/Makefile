# New ports collection makefile for:	www/p5-Template-Plugin-FillInForm
# Date created:				07 November 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-FillInForm
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Template::Plugin::FillInForm - TT plugin for HTML::FillInForm

RUN_DEPENDS=	p5-HTML-FillInForm>=0:${PORTSDIR}/www/p5-HTML-FillInForm \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Template::Plugin::FillInForm.3

.include <bsd.port.mk>
