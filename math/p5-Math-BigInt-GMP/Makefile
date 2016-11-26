# Created by: Maxime Henrion <mux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-BigInt-GMP
PORTVERSION=	1.6001
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Math::BigInt::GMP - Use the GMP library for Math::BigInt routines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Math-BigInt>=1.999801:math/p5-Math-BigInt
LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/BigInt/GMP/GMP.so

.include <bsd.port.mk>
