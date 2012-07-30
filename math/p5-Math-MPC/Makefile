# New ports collection makefile for:	Math-MPC
# Date created:				05 April, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math-MPC
PORTVERSION=	1.00
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl interface to MPC Library

BUILD_DEPENDS=	p5-Math-MPFR>=2.01:${PORTSDIR}/math/p5-Math-MPFR
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		mpc:${PORTSDIR}/math/mpc \
		mpfr:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

MAKE_ENV=	INC="-I${LOCALBASE}/include"
PERL_CONFIGURE=	yes

MAN3=		Math::MPC.3

.include <bsd.port.mk>
