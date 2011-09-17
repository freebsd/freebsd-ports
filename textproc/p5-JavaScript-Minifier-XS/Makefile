# New ports collection makefile for:	JavaScript-Minifier-XS
# Date created:	   18 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	JavaScript-Minifier-XS
PORTVERSION=	0.09
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS based JavaScript minifier

PERL_CONFIGURE=	yes

MAN3=		JavaScript::Minifier::XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-Module-Build>=0.3500:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
