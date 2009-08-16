# New ports collection makefile for:	Math-FixedPrecision
# Date created:				Wed Jan  3 11:03:30 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Math-FixedPrecision
PORTVERSION=	0.21
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides decimal math without floating point errors

BUILD_DEPENDS=	${SITE_PERL}/Math/BigFloat.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Math::FixedPrecision.3

.include <bsd.port.mk>
