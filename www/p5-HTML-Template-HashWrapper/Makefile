# New ports collection makefile for:	p5-HTML-Template-HashWrapper
# Date Created:				15 Sep 2005
# Whom:		Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-HashWrapper
PORTVERSION=	1.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Easy way to use the associate option from HTML::Template

RUN_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		HTML::Template::HashWrapper.3

.include <bsd.port.mk>
