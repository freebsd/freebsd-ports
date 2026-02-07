PORTNAME=	mpfrcx
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Arbitrary precision library for arithmetic of univariate polynomials
WWW=		https://www.multiprecision.org/mpfrcx/index.html

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr

USES=		gmake libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		mpfrcx

PLIST_FILES=	include/mpfrcx.h \
		lib/libmpfrcx.a \
		lib/libmpfrcx.so \
		lib/libmpfrcx.so.1 \
		lib/libmpfrcx.so.1.2.3

.include <bsd.port.mk>
