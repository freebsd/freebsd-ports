# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	xblas
PORTVERSION=	1.0.248
CATEGORIES=	math
MASTER_SITES=	NL/xblas LOCAL/bf
DISTNAME=	xblas

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extra Precise Basic Linear Algebra Subroutines (BLAS)

LICENSE=	BSD3CLAUSE

USE_LDCONFIG=	yes

CFLAGS+=	${MANGLING}
HDIR=		include/xblas
HEADERS=	blas_dense_proto.h blas_enum.h blas_extended.h \
		blas_extended_private.h blas_extended_proto.h blas_fpu.h \
		blas_malloc.h f2c-bridge.h
MAKE_ENV=	EXTRA_LIBS="-lm" LINKER="${CC}" M4="${M4}" RANLIB="${RANLIB}"
OPTIONS_DEFINE=	SHARED STATIC DOCS
OPTIONS_DEFAULT=	SHARED
SHARED_DESC=	Build a shared library and PIC archive
STATIC_DESC=	Build a non-PIC archive
PLIST_FILES=	${HEADERS:S|^|${HDIR}/|}
SHLIB_MAJOR=	0
WRKSRC=		${WRKDIR}/xblas-${PORTVERSION}

.include <bsd.port.options.mk>

M4?=	m4
M4_OPTS?=	#empty
MANGLING?=	-DCONFIG_FC_UNDERSCORE

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CFLAGS+=	-Dx86
.endif

.if ${ARCH} == "sparc64"
PICFLAG=	-fPIC
.else
PICFLAG=	-fpic
.endif

PORTDOCS=	report.ps

.if ${PORT_OPTIONS:MSHARED}
PLIST_FILES+=	lib/libxblas_pic.a lib/libxblas.so lib/libxblas.so.${SHLIB_MAJOR}
.endif

.if ${PORT_OPTIONS:MSTATIC}
PLIST_FILES+=	lib/libxblas.a
.endif

post-patch:
	@${REINPLACE_CMD} -E \
	-e '/(ARCH|CC|(C|LD)FLAGS|EXTRA_LIBS|M4|M4_OPTS|RANLIB|XBLASLIB)[[:blank:]]*=/d' \
		${WRKSRC}/make.inc
.if ${PORT_OPTIONS:MSTATIC}
	@${CP} -af ${WRKSRC} ${WRKSRC}_STATIC
.endif
	@${PRINTF} "\nCFLAGS+=\t${PICFLAG}\n" >> ${WRKSRC}/make.inc
# Fix parallel (-jX) builds
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-E 's/cd (.+) && (\$$\(MAKE\))/\2 -C \1/'

do-build: build-shared build-static

build-shared: patch
.if ${PORT_OPTIONS:MSHARED}
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} XBLASLIB="libxblas_pic.a" ${MAKE} \
	${_MAKE_JOBS} ${MAKE_ARGS} ARCH="${AR}" lib ; \
	${CC} ${CFLAGS} ${PICFLAG} ${LDFLAGS} -shared -Wl,-x \
	-Wl,-soname,libxblas.so.${SHLIB_MAJOR} -o libxblas.so.${SHLIB_MAJOR} \
	-Wl,--whole-archive libxblas_pic.a -Wl,--no-whole-archive -Wl,--as-needed -lm
.endif

build-static: patch
.if ${PORT_OPTIONS:MSTATIC}
	@cd ${WRKSRC}_STATIC; ${SETENV} ${MAKE_ENV} XBLASLIB="libxblas.a" ${MAKE} \
	${_MAKE_JOBS} ${MAKE_ARGS} ARCH="${AR}" lib
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${HDIR}
	@cd ${WRKSRC}/src; ${INSTALL_DATA} ${HEADERS} ${STAGEDIR}${PREFIX}/${HDIR}
.if ${PORT_OPTIONS:MSHARED}
	@cd ${WRKSRC}; ${INSTALL_DATA} libxblas_pic.a \
	libxblas.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib
	@${LN} -sf libxblas.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib/libxblas.so
.endif
.if ${PORT_OPTIONS:MSTATIC}
	@${INSTALL_DATA} ${WRKSRC}_STATIC/libxblas.a ${STAGEDIR}${PREFIX}/lib
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/report.ps ${STAGEDIR}${DOCSDIR}
.endif

check regression-test test: test-shared test-static

test-shared: build
.if ${PORT_OPTIONS:MSHARED}
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} XBLASLIB="libxblas_pic.a" ${MAKE} \
	${_MAKE_JOBS} ${MAKE_ARGS} ARCH="${AR}" tests
.endif

test-static: build
.if ${PORT_OPTIONS:MSTATIC}
	@cd ${WRKSRC}_STATIC; ${SETENV} ${MAKE_ENV} XBLASLIB="libxblas.a" ${MAKE} \
	${_MAKE_JOBS} ${MAKE_ARGS} ARCH="${AR}" tests
.endif

.include <bsd.port.mk>
