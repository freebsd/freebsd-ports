# New ports collection makefile for:	p5-HTML-FillInForm
# Date created:				March 30th 2001
# Whom:	      				Alex Kapranoff <kapr@crosswinds.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-FillInForm
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	kapr@crosswinds.net

BUILD_DEPEND=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser

PERL_CONFIGURE=	yes

INSTALL_TARGET=	pure_install

MAN3=		HTML::FillInForm.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
