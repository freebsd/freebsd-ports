# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Math-MPC
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to MPC Library

BUILD_DEPENDS=	p5-Math-MPFR>=2.01:${PORTSDIR}/math/p5-Math-MPFR
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		mpc:${PORTSDIR}/math/mpc \
		mpfr:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

MAKE_ENV=	INC="-I${LOCALBASE}/include"
USES=		perl5
USE_PERL5=	configure

MAN3=		Math::MPC.3

NO_STAGE=	yes
.include <bsd.port.mk>
