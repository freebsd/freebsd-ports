# New ports collection makefile for:	math/p5-Math-BigInt-GMP
# Date created:				7 February 2007
# Whom:					Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-BigInt-GMP
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Math::BigInt::GMP - Use the GMP library for Math::BigInt routines

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4
BUILD_DEPENDS=	p5-Math-BigInt>=1.78:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INC="-I${LOCALBASE}/include"

MAN3=		Math::BigInt::GMP.3

.include <bsd.port.mk>
