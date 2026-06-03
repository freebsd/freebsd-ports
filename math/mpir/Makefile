PORTNAME=	mpir
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Multiprecision integer, rational, floating point numbers library
WWW=		https://github.com/wbhart/mpir/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	makeinfo:print/texinfo \
		yasm:devel/yasm

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	wbhart
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx --with-system-yasm
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

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
