PORTNAME=	cmh
DISTVERSION=	1.1.1
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compute Igusa class polynomials

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

.include <bsd.port.mk>
