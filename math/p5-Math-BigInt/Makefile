# New ports collection makefile for:	math/p5-Math-BigInt
# Date created:				12 October 2001
# Whom:					tobez
#
# $FreeBSD$
#

PORTNAME=	Math-BigInt
PORTVERSION=	1.49
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	INSTALLDIRS='site'

MAN3=		Math::BigFloat.3 \
		Math::BigInt.3 \
		Math::BigInt::Calc.3 \
		Math::BigInt::Scalar.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
