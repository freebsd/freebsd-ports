# Created by: Yonatan <Yonatan@Xpert.com>
# $FreeBSD$

PORTNAME=	libtomcrypt
PORTVERSION=	1.17
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://libtom.net/files/
DISTNAME=	crypt-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable cryptographic toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-I${LOCALBASE}/include
EXTRALIBS=	-L${LOCALBASE}/lib
MAKEFILE=	makefile.shared
ALL_TARGET=	library
MAKE_ARGS=	IGNORE_SPEED=yes INCPATH="${PREFIX}/include" \
		LIBPATH="${PREFIX}/lib" EXTRALIBS="${EXTRALIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake libtool:build tar:bzip2

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
		${WRKSRC}/makefile.shared ${WRKSRC}/testprof/makefile.shared

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtomcrypt_prof.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtomcrypt.so.0

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/crypt.pdf ${STAGEDIR}${DOCSDIR}/pdf

do-test:
	@${ECHO_MSG} "Testing with -DUSE_TFM..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_TFM" EXTRALIBS="-L${PREFIX}/lib -ltfm" ${MAKE_CMD} test && ${WRKSRC}/test)

	@${ECHO_MSG} "Cleaning up test binary..."
	@${RM} ${WRKSRC}/test
	@${RM} ${WRKSRC}/demos/test.o

	@${ECHO_MSG} "Testing with -DUSE_LTM..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_LTM" EXTRALIBS="-L${PREFIX}/lib -ltommath" ${MAKE_CMD} test && ${WRKSRC}/test)

	@${ECHO_MSG} "Cleaning up test binary..."
	@${RM} ${WRKSRC}/test
	@${RM} ${WRKSRC}/demos/test.o

	@${ECHO_MSG} "Testing with -DUSE_GMP..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_GMP" EXTRALIBS="-L${PREFIX}/lib -lgmp" ${MAKE_CMD} test && ${WRKSRC}/test)

.include <bsd.port.mk>
