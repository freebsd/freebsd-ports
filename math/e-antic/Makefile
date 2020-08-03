# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	e-antic
PORTVERSION=	0.1.8
#MASTER_SITES=	https://www.labri.fr/perso/vdelecro/e-antic/
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Real Embedded Algebraic Number Theory In C

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libarb.so:math/arb	\
		libgmp.so:math/gmp	\
		libflint.so:math/flint2

USE_GITHUB=	yes
GH_ACCOUNT=	videlec

USES=		autoreconf compiler:c++11-lang gmake libtool localbase

OPTIONS_DEFINE=	DOCS VALGRIND

LIBS+=		"-lm"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

VALGRIND_DESC=			Enable Valgrind on the unit tests
VALGRIND_BUILD_DEPENDS=		valgrind:devel/valgrind
VALGRIND_TEST_DEPENDS=		valgrind:devel/valgrind
VALGRIND_CONFIGURE_ENABLE=	valgrind

.include <bsd.port.mk>
