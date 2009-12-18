# New ports collection makefile for:	math/p5-Math-Base36
# Date created:				2008-08-04
# Whom:					Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Base36
PORTVERSION=	0.07
PORTEPOCH=	2
CATEGORIES=	math perl5 converters
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Encoding and decoding of base36 strings

BUILD_DEPENDS=	p5-Math-BigInt>=1.60:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::Base36.3

.include <bsd.port.mk>
