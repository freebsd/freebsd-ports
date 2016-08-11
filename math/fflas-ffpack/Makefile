# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fflas-ffpack
PORTVERSION=	1.4.3
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://linalg.org/ LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for dense linear algebra over word-size finite fields

LICENSE=	LGPL20

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp="${LOCALBASE}"
SHEBANG_FILES=	fflas-ffpack-config.in

OPTIONS_DEFINE=	DOXYGEN OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${LOCALBASE} == "/usr/local"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--with-givaro="${LOCALBASE}"
LIB_DEPENDS+=		libgivaro.so:math/givaro
.else
CONFIGURE_ARGS+=	--with-givaro=no
.endif

#a C interface to BLAS is needed
WITH_BLAS?=	gsl

.if ${WITH_BLAS} == "gotoblas"
CONFIGURE_ARGS+=	--with-gotoblas2="${LOCALBASE}" --with-lapack=blas
LIB_DEPENDS+=	libgoto2p.so:math/gotoblas
USES+=		fortran
.elif ${WITH_BLAS} == "atlas"
CONFIGURE_ARGS+=	--with-cblas="${LOCALBASE}" --with-lapack=blas
LIB_DEPENDS+=	libcblas.so:math/atlas
USES+=		fortran
.elif ${WITH_BLAS} == "gsl"
CONFIGURE_ARGS+=	--with-gsl="${LOCALBASE}"
LIB_DEPENDS+=	libgslcblas.so:math/gsl
.else
IGNORE =	unknown value of WITH_BLAS: ${WITH_BLAS}
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=		doxygen:devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --with-docdir="${DOCSDIR}"
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MANUAL_PACKAGE_BUILD=	: optimizes for the build machine
.else
CONFIGURE_ARGS+=	--disable-optimization
.endif

post-patch:
	${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/{s/-O2 //;s/-pipe//;}' \
		-e '/DEBUG_CFLAGS=.*-DNDEBUG/s/$${DEBUG_CFLAGS} //' \
		-e '/^WARN_CFLAGS="-Wall"/d' \
		-e '/if test "x$$WARN" = "xyes"/s/$$/ WARN_CFLAGS="-Wall" ;/' \
		-e 's/\(-lgoto2\)\( -pthread\)\{0,1\}/\1p/g' -e 's/libgoto2/&p/g' \
		-e '/"GOTO2")/{N; s/LAPACK_LIBS=""/LAPACK_LIBS="-lgoto2p"/; }' \
		-e 's/liblapack_atlas/libalapack/g' \
		-e 's/$${LAPACK_LIBS} -llapack_atlas/-lalapack -lf77blas -lcblas/g' \
		${WRKSRC}/configure
#Unfortunately, we must leave stdint.h --> cstdint unresolved when not using
#lang/gcc4*, or switch to TR1 headers, due to our aging base system libstdc++
	${REINPLACE_CMD} -E \
	-e 's/(#include[[:blank:]]+<)(std)(arg|def|io|lib)(\.h>)/\1c\2\3>/' \
		${WRKSRC}/fflas-ffpack/field/nonzero-randiter.h \
		${WRKSRC}/fflas-ffpack/field/modular-randiter.h \
		${WRKSRC}/fflas-ffpack/utils/args-parser.h \
		${WRKSRC}/fflas-ffpack/utils/debug.h \
		${WRKSRC}/fflas-ffpack/utils/Matio.h \
		${WRKSRC}/utils/args-parser.h \
		${WRKSRC}/utils/debug.h \
		${WRKSRC}/utils/Matio.h
.if ${PORT_OPTIONS:MDOXYGEN}
	@${REINPLACE_CMD} -e 's/sed -i/& ""/' ${WRKSRC}/doc/Makefile.in
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/fflas-ffpack-dev-html
	${TOUCH} ${STAGEDIR}${DOCSDIR}/fflas-ffpack-dev-html/.keep-me
.endif

.if defined(MAINTAINER_MODE)
check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
	${MAKE_ARGS} check

.endif

.include <bsd.port.mk>
