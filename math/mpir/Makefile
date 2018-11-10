# Created by: gahr
# $FreeBSD$

PORTNAME=	mpir
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://mpir.org/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Multiprecision integer library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	yasm:devel/yasm

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx --with-system-yasm
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

MPIR_VERSION=	23.0.3
MPIRXX_VERSION=	8.4.3

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

.include <bsd.port.mk>
