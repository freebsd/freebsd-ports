PORTNAME=	calcium
DISTVERSION=	0.4.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Exact real and complex numbers in C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libantic.so:math/antic \
		libarb.so:math/arb \
		libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fredrik-johansson

GNU_CONFIGURE=	yes

TEST_TARGET=	tests # only builds tests and doesn't run them, see https://github.com/fredrik-johansson/calcium/issues/41

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcalcium.so.${DISTVERSION}

.include <bsd.port.mk>
