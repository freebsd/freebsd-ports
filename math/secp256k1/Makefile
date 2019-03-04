# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	secp256k1
PORTVERSION=	0.1.20190225
CATEGORIES=	math security java

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Optimized C library for EC operations on curve secp256k1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool gmake

USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bitcoin-core
GH_TAGNAME=	aa15154

OPTIONS_DEFINE=	GMP JAVA
OPTIONS_DEFAULT=GMP JAVA

GMP_DESC=	Use GMP bignum implementation
GMP_LIB_DEPENDS=libgmp.so:math/gmp
GMP_CONFIGURE_ON=--with-bignum=gmp
GMP_CONFIGURE_OFF=--with-bignum=no

JAVA_DESC=	Build JNI bindings
JAVA_CONFIGURE_ENABLE=jni

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-experimental --enable-module-ecdh \
		--enable-endomorphism --enable-module-recovery
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGMP}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
CONFIGURE_ENV+=	JAVA_HOME="${JAVA_HOME}"
.endif

check regression-test test:	build
	cd ${WRKSRC} && ./tests

.include <bsd.port.mk>
