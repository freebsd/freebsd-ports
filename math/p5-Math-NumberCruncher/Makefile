# New ports collection makefile for:	math/p5-Math-NumberCruncher
# Date created:				2007/03/06
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Math-NumberCruncher
PORTVERSION=	5.00
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of useful math-related functions

BUILD_DEPENDS=	p5-Math-BigInt>=0:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::NumberCruncher.3

.include <bsd.port.mk>
