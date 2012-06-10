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

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy way to use the associate option from HTML::Template

RUN_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Template::HashWrapper.3

.include <bsd.port.mk>
