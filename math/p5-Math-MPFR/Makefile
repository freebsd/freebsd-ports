# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Math-MPFR
PORTVERSION=	3.18
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SISYPHUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to MPFR Library

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr
TEST_DEPENDS=	p5-Math-GMP>=0:${PORTSDIR}/math/p5-Math-GMP \
		p5-Math-GMPf>=0:${PORTSDIR}/math/p5-Math-GMPf \
		p5-Math-GMPq>=0:${PORTSDIR}/math/p5-Math-GMPq \
		p5-Math-GMPz>=0:${PORTSDIR}/math/p5-Math-GMPz

USES=		perl5
USE_PERL5=	configure
MAKE_ENV=	INC="-I${LOCALBASE}/include"

.include <bsd.port.mk>
