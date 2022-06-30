PORTNAME=	arb
DISTVERSION=	2.23.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for arbitrary-precision interval arithmetic

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fredrik-johansson

.include <bsd.port.mk>
