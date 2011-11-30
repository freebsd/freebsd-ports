# New ports collection makefile for:	Math-MPC
# Date created:				05 April, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math-MPC
PORTVERSION=	0.92
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl interface to MPC Library

BUILD_DEPENDS=	p5-Math-MPFR>=2.01:${PORTSDIR}/math/p5-Math-MPFR
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		mpc.2:${PORTSDIR}/math/mpc \
		mpfr.4:${PORTSDIR}/math/mpfr
RUN_DEPENDS=	p5-Math-MPFR>=2.01:${PORTSDIR}/math/p5-Math-MPFR

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes
MAKE_ENV=	INC="-I${LOCALBASE}/include"

MAN3=		Math::MPC.3

.include <bsd.port.mk>
