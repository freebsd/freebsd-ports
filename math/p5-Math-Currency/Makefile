# New ports collection makefile for:	Math-Currency
# Date created:				Wed Jan  3 10:58:59 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-Currency
PORTVERSION=	0.39
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl module for exact currency math with formatting and rounding

BUILD_DEPENDS=	${SITE_PERL}/Math/FixedPrecision.pm:${PORTSDIR}/math/p5-Math-FixedPrecision \
		${SITE_PERL}/Math/BigFloat.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::Currency.3

.include <bsd.port.mk>
