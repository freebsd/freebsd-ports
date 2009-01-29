# New ports collection makefile for:	p5-HTML-FillInForm
# Date created:				March 30th 2001
# Whom:	      				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-FillInForm
PORTVERSION=	2.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for auto-filling HTML form fields from previous values

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

INSTALL_TARGET=	pure_install

MAN3=		HTML::FillInForm.3

.include <bsd.port.mk>
