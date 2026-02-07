PORTNAME=	paritwine
DISTVERSION=	0.2.2
CATEGORIES=	math
MASTER_SITES=	https://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Glue library between PARI/GP and other mathematics libraries
WWW=		https://www.multiprecision.org/paritwine/index.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libarb.so:math/arb \
		libcmh.so:math/cmh \
		libflint.so:math/flint2 \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libpari.so:math/pari

USES=		gmake libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

INFO=		paritwine

TEST_TARGET=	check

# ============================================================================
# Testsuite summary for paritwine 0.2.2
# ============================================================================
# TOTAL: 4
# PASS:  3
# SKIP:  1
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0

.include <bsd.port.mk>
