# Created by: gahr
# $FreeBSD$

PORTNAME=	mpir
PORTVERSION=	2.7.2
CATEGORIES=	math
MASTER_SITES=	http://mpir.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiprecision integer library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	yasm:devel/yasm

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx --with-system-yasm
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

MPIR_VERSION=	16.6.2
MPIRXX_VERSION=	8.4.2

INFO=		mpir

PLIST_FILES=	include/mpir.h \
		include/mpirxx.h \
		lib/libmpir.a \
		lib/libmpir.so \
		lib/libmpir.so.${MPIR_VERSION} \
		lib/libmpir.so.${MPIR_VERSION:R:R} \
		lib/libmpirxx.a \
		lib/libmpirxx.so \
		lib/libmpirxx.so.${MPIRXX_VERSION} \
		lib/libmpirxx.so.${MPIRXX_VERSION:R:R}

regression-test:
	${MAKE_CMD} -C ${WRKSRC} check

.include <bsd.port.mk>
