PORTNAME=	cm
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for ring class fields of imaginary quadratic number fields

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmpfrcx.so:math/mpfrcx \
		libpari.so:math/pari

USES=		gmake libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

INFO=		cm

.include <bsd.port.mk>
