# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-GSL
PORTVERSION=	0.42
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Perl interface to GNU Scientific Library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PkgConfig>=0.07720:devel/p5-PkgConfig
LIB_DEPENDS=	libgsl.so:math/gsl
TEST_DEPENDS=	p5-Test-Class>=0.12:devel/p5-Test-Class \
		p5-Test-Exception>=0.21:devel/p5-Test-Exception \
		p5-Test-Most>=0.31:devel/p5-Test-Most \
		p5-Test-Taint>=1.06:devel/p5-Test-Taint

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GSL/ -name "*.so" -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
