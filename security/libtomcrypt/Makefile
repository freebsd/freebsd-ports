# Created by: Yonatan <Yonatan@Xpert.com>
# $FreeBSD$

PORTNAME=	libtomcrypt
PORTVERSION=	1.18.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable cryptographic toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-I${LOCALBASE}/include
EXTRALIBS=	-L${LOCALBASE}/lib
MAKEFILE=	makefile.shared
ALL_TARGET=	library
MAKE_ARGS=	INCPATH="${PREFIX}/include" LIBPATH="${PREFIX}/lib" \
		EXTRALIBS="${EXTRALIBS}"
USES=		gmake libtool:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	libtom

OPTIONS_DEFINE=		DOCS
OPTIONS_MULTI=		MATH
OPTIONS_MULTI_MATH=	LIBTOMMATH TOMSFASTMATH GMP
OPTIONS_DEFAULT=	LIBTOMMATH

LIBTOMMATH_DESC=	Use LibTomMath
TOMSFASTMATH_DESC=	Use TomsFastMath

LIBTOMMATH_BUILD_DEPENDS=	${LOCALBASE}/include/tommath.h:math/libtommath
LIBTOMMATH_CFLAGS=		-DLTM_DESC
LIBTOMMATH_VARS=		EXTRALIBS+=-ltommath

TOMSFASTMATH_BUILD_DEPENDS=	${LOCALBASE}/include/tfm.h:math/tomsfastmath
TOMSFASTMATH_CFLAGS=		-DTFM_DESC
TOMSFASTMATH_VARS=		EXTRALIBS+=-ltfm

GMP_LIB_DEPENDS=		libgmp.so:math/gmp
GMP_CFLAGS=			-DGMP_DESC
GMP_VARS=			EXTRALIBS+=-lgmp

DOCS_MAKE_ARGS_OFF=		NODOCS=yes

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' -e 's| make | $$(MAKE) |' \
		-e 's|-g $$(GROUP)||' -e 's|-o $$(USER)||' \
		${WRKSRC}/makefile.shared ${WRKSRC}/makefile_include.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtomcrypt.so.1

do-test:
	# TomsFastMath
	@${ECHO_CMD} "Testing TomsFastMath"
	${MAKE_CMD} -C ${WRKSRC} \
	    CFLAGS="-I${LOCALBASE}/include -DUSE_TFM -DTFM_DESC" \
	    EXTRALIBS="-L${LOCALBASE}/lib -ltfm" clean test
	(cd ${WRKSRC} && ./test)
	# LibTomMath
	@${ECHO_CMD} "Testing LibTomMath"
	${MAKE_CMD} -C ${WRKSRC} \
	    CFLAGS="-I${LOCALBASE}/include -DUSE_LTM -DLTM_DESC" \
	    EXTRALIBS="-L${LOCALBASE}/lib -ltommath" clean test
	(cd ${WRKSRC} && ./test)
	# GMP
	@${ECHO_CMD} "Testing GMP"
	${MAKE_CMD} -C ${WRKSRC} \
	    CFLAGS="-I${LOCALBASE}/include -DUSE_GMP -DGMP_DESC" \
	    EXTRALIBS="-L${LOCALBASE}/lib -lgmp" clean test
	(cd ${WRKSRC} && ./test)

.include <bsd.port.mk>
