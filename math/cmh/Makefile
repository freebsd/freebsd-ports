PORTNAME=	cmh
DISTVERSION=	1.1.2
CATEGORIES=	math
MASTER_SITES=	https://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compute Igusa class polynomials
WWW=		https://www.multiprecision.org/cmh/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfplll.so:math/fplll \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmpfrcx.so:math/mpfrcx \
		libpari.so:math/pari
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool localbase shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/cmh-classpol.sh.in
SHEBANG_GLOB=	*.sh

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # tests fail, see https://gitlab.inria.fr/cmh/cmh/-/issues/1

# ============================================================================
# Testsuite summary for cmh 1.1.2
# ============================================================================
# TOTAL: 1
# PASS:  1
# SKIP:  0
# XFAIL: 0
# FAIL:  0
# XPASS: 0
# ERROR: 0
# ============================================================================

.include <bsd.port.mk>
