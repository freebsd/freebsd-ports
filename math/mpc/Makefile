# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mpc
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	GNU

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Library of complex numbers with arbitrarily high precision

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		libtool
USE_LDCONFIG=	yes

INFO=		mpc
PLIST_FILES=	include/mpc.h \
		lib/libmpc.a lib/libmpc.so lib/libmpc.so.3 lib/libmpc.so.3.1.0

.include <bsd.port.mk>
