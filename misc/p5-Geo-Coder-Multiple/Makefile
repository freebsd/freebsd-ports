# New ports collection makefile for:	Geo-Coder-Multiple
# Date created:				12th March, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coder-Multiple
PORTVERSION=	0.60
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.6

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl module to tie together multiple Geo::Coder modules

RUN_DEPENDS=	p5-List-Util-WeightedRoundRobin>=0:${PORTSDIR}/misc/p5-List-Util-WeightedRoundRobin
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geo::Coder::Multiple.3

.include <bsd.port.mk>
