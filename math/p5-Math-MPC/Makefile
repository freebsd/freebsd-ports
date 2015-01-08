# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Math-MPC
PORTVERSION=	1.04
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to MPC Library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Math-MPFR>=3.23:${PORTSDIR}/math/p5-Math-MPFR
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpc.so:${PORTSDIR}/math/mpc \
		libmpfr.so:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

MAKE_ENV=	INC="-I${LOCALBASE}/include"
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
