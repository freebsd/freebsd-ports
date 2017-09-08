# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-GSL
PORTVERSION=	0.39
PORTREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to GNU Scientific Library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BROKEN_sparc64=	does not compile on sparc64

BUILD_DEPENDS=	p5-PkgConfig>=0.07720:devel/p5-PkgConfig
LIB_DEPENDS=	libgsl.so:math/gsl
TEST_DEPENDS=	p5-Test-Class>=0.12:devel/p5-Test-Class \
		p5-Test-Exception>=0.21:devel/p5-Test-Exception \
		p5-Test-Most>=0.31:devel/p5-Test-Most \
		p5-Test-Taint>=1.06:devel/p5-Test-Taint

USE_PERL5=	modbuild
USES=		perl5

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GSL/ -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
