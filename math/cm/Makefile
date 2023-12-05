PORTNAME=	cm
DISTVERSION=	0.4.2
CATEGORIES=	math
MASTER_SITES=	https://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for ring class fields of imaginary quadratic number fields
WWW=		https://www.multiprecision.org/cm/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libflint.so:math/flint2 \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmpfrcx.so:math/mpfrcx \
		libpari.so:math/pari

USES=		gmake libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		cm

.include <bsd.port.mk>
