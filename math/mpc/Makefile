PORTNAME=	mpc
DISTVERSION=	1.4.1
CATEGORIES=	math devel
MASTER_SITES=	GNU

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Library of complex numbers with arbitrarily high precision
WWW=		https://www.multiprecision.org/mpc/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		libtool pathfix tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		mpc
PLIST_FILES=	include/mpc.h 			\
		lib/libmpc.a 			\
		lib/libmpc.so 			\
		lib/libmpc.so.3 		\
		lib/libmpc.so.3.4.1		\
		libdata/pkgconfig/mpc.pc

.include <bsd.port.mk>
