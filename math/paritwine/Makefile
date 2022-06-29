PORTNAME=	paritwine
DISTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Glue library between PARI/GP and other mathematics libraries

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

.include <bsd.port.mk>
