# Created by: Yonatan <Yonatan@Xpert.com>
# $FreeBSD$

PORTNAME=	libtomcrypt
PORTVERSION=	1.17
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://libtom.org/files/
DISTNAME=	crypt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable cryptographic toolkit

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

CFLAGS+=	-I${LOCALBASE}/include
EXTRALIBS=	-L${LOCALBASE}/lib
MAKEFILE=	makefile.shared
ALL_TARGET=	library
MAKE_ARGS=	IGNORE_SPEED=yes INCPATH="${PREFIX}/include" \
		LIBPATH="${PREFIX}/lib" EXTRALIBS="${EXTRALIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake libtool tar:bzip2

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	LIBTOMMATH
OPTIONS_MULTI=		MATH
OPTIONS_MULTI_MATH=	LIBTOMMATH TOMSFASTMATH GMP
LIBTOMMATH_DESC=	Use LibTomMath
TOMSFASTMATH_DESC=	Use TomsFastMath

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBTOMMATH}
BUILD_DEPENDS+=	${LOCALBASE}/include/tommath.h:${PORTSDIR}/math/libtommath
CFLAGS+=	-DLTM_DESC
EXTRALIBS+=	-ltommath
.endif

.if ${PORT_OPTIONS:MTOMSFASTMATH}
BUILD_DEPENDS+=	${LOCALBASE}/include/tfm.h:${PORTSDIR}/math/tomsfastmath
CFLAGS+=	-DTFM_DESC
EXTRALIBS+=	-ltfm
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp
CFLAGS+=	-DGMP_DESC
EXTRALIBS+=	-lgmp
.endif

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	NODOCS=yes
.endif

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|' -e 's| make | $$(MAKE) |' \
		-e 's|-g $$(GROUP)||' -e 's|-o $$(USER)||' \
		${WRKSRC}/makefile.shared ${WRKSRC}/testprof/makefile.shared

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/crypt.pdf ${STAGEDIR}${DOCSDIR}/pdf

.if defined(MAINTAINER_MODE)
test:	build
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
.endif

.include <bsd.port.mk>
