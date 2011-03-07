# New ports collection makefile for:	math/p5-Statistics-R
# Date created:				March 7, 2011
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Statistics-R
PORTVERSION=	0.08
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRICAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Controls the R interpreter through Perl

RUN_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R

PERL_CONFIGURE=	yes

MAN3=		Statistics::R::Bridge.3 \
		Statistics::R.3

.include <bsd.port.mk>
