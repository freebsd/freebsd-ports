# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	libflame
DISTVERSION=	r7421
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.cs.utexas.edu/users/%SUBDIR%/:1,2 LOCAL/bf:3
MASTER_SITE_SUBDIR=	flame/snapshots/:1 field/docs/:2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1,3
.if !defined(NOPORTDOCS) || make(makesum)
DISTFILES+=	libflame.pdf:2,3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	bf@FreeBSD.org
COMMENT=	FLAME dense linear algebra library

LICENSE=	LGPL21

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_CSTD=	c99
USE_GMAKE=	yes

CONFIGURE_ARGS	=	--enable-dynamic-build --enable-static-build

IGNOREFILES=	libflame.pdf

OPTIONS_DEFINE=	BLAS3_CNTL BUILTIN_BLAS CBLAS EXTERNAL_LAPACK GOTOBLAS \
		LAPACK2FLAME LAPACK_SUBPROBLEMS OPENMP SHARED STATIC \
		SUPERMATRIX THREADS
OPTIONS_DEFAULT=	BLAS3_CNTL LAPACK2FLAME SHARED SUPERMATRIX THREADS
BLAS3_CNTL_DESC=	Set Level-3 BLAS variant and blocksize
BUILTIN_BLAS_DESC=	Build the (suboptimal) internal BLAS
CBLAS_DESC=		Build an interface to an external C BLAS
EXTERNAL_LAPACK_DESC=	Build an interface to an external LAPACK
GOTOBLAS_DESC=		Build a full GotoBLAS interface
LAPACK2FLAME_DESC=	Build a LAPACK compatibility layer
LAPACK_SUBPROBLEMS_DESC=	Use an external LAPACK for subproblems
OPENMP_DESC=		Use multithreading via OpenMP
SHARED_DESC=		Build a shared library and PIC archive
STATIC_DESC=		Build a non-PIC archive
SUPERMATRIX_DESC=	Task scheduling and parallel execution

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBLAS3_CNTL}
CONFIGURE_ARGS+=	--enable-blas3-front-end-cntl-trees
.else
CONFIGURE_ARGS+=	--disable-blas3-front-end-cntl-trees
.endif

.if ${PORT_OPTIONS:MBUILTIN_BLAS}
IGNORE =	: WITH_BUILTIN_BLAS is an experimental option, for testing purposes only
.if ${PORT_OPTIONS:MCBLAS} || ${PORT_OPTIONS:MGOTOBLAS}
IGNORE =	: WITH_BUILTIN_BLAS is incompatible with WITH_CBLAS and WITH_GOTOBLAS
.endif
CONFIGURE_ARGS+=	--enable-builtin-blas
.else
CONFIGURE_ARGS+=	--disable-builtin-blas
.endif

.if ${PORT_OPTIONS:MCBLAS}
IGNORE =	: WITH_CBLAS yields an incomplete library, and is for testing purposes only
.if ${PORT_OPTIONS:MGOTOBLAS}
IGNORE =	: WITH_CBLAS is incompatible with WITH_GOTOBLAS
.endif
CONFIGURE_ARGS+=	--enable-cblas-interfaces
.else
CONFIGURE_ARGS+=	--disable-cblas-interfaces
.endif

.if ${PORT_OPTIONS:MEXTERNAL_LAPACK}
CONFIGURE_ARGS+=	--enable-external-lapack-interfaces
.else
CONFIGURE_ARGS+=	--disable-external-lapack-interfaces
.endif

.if ${PORT_OPTIONS:MGOTOBLAS}
CONFIGURE_ARGS+=	--enable-goto-interfaces
WITH_BLAS=	gotoblas
.else
CONFIGURE_ARGS+=	--disable-goto-interfaces
.for b in M K N
.if defined(${b}_BLOCKSIZE)
CONFIGURE_ARGS+=	--enable-default-${b:L}-blocksize=${${b}_BLOCKSIZE}
.endif
.endfor
.endif

.if ${PORT_OPTIONS:MLAPACK2FLAME}
.if ${PORT_OPTIONS:MLAPACK_SUBPROBLEMS}
IGNORE =	: WITH_LAPACK2FLAME is incompatible with WITH_LAPACK_SUBPROBLEMS
.endif
CONFIGURE_ARGS+=	--enable-lapack2flame
.else
CONFIGURE_ARGS+=	--disable-lapack2flame
.endif

.if ${PORT_OPTIONS:MLAPACK_SUBPROBLEMS}
.if ! ${PORT_OPTIONS:MEXTERNAL_LAPACK}
IGNORE =	: WITH_LAPACK_SUBPROBLEMS requires WITH_EXTERNAL_LAPACK
.endif
CONFIGURE_ARGS+=	--enable-external-lapack-for-subproblems
.else
CONFIGURE_ARGS+=	--disable-external-lapack-for-subproblems
.endif

.if ${PORT_OPTIONS:MEXTERNAL_LAPACK} || ! ${PORT_OPTIONS:MBLAS}
.if ${PORT_OPTIONS:MCBLAS}
.if exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas_c
.else
WITH_BLAS?=	reference_c
.endif
.if !(${WITH_BLAS} == "atlas_c" || ${WITH_BLAS} == "reference_c")
IGNORE=	: WITH_CBLAS is incompatible with WITH_BLAS = ${WITH_BLAS}
.endif
.elif exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif  #WITH_CBLAS
.endif #WITH_EXTERNAL_LAPACK or WITH_BUILTIN_BLAS

.if ! ${PORT_OPTIONS:MBUILTIN_BLAS}
.if ${WITH_BLAS} == atlas
RUN_DEPENDS +=	${LOCALBASE}/lib/libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
.elif ${WITH_BLAS} == atlas_c
RUN_DEPENDS +=	${LOCALBASE}/lib/libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptcblas
.elif ${WITH_BLAS} == gotoblas
RUN_DEPENDS +=	${LOCALBASE}/lib/libgoto2p.so:${PORTSDIR}/math/gotoblas
BLAS =		-lgoto2p
.elif ${WITH_BLAS} == reference
RUN_DEPENDS +=	${LOCALBASE}/lib/libblas.so:${PORTSDIR}/math/blas
BLAS=		-lblas
.elif ${WITH_BLAS} == reference_c
RUN_DEPENDS +=	${LOCALBASE}/lib/libgslcblas.so:${PORTSDIR}/math/gsl
BLAS=		-lgslcblas
.endif #WITH_BLAS
.endif #WITH_BUILTIN_BLAS

.if ${PORT_OPTIONS:MEXTERNAL_LAPACK}
.if !empty(WITH_BLAS:Matlas*)
.if ${PORT_OPTIONS:MBUILTIN_BLAS}
RUN_DEPENDS +=	${LOCALBASE}/lib/libatlas.so:${PORTSDIR}/math/atlas
.endif
LAPACK =	-lalapack -lptcblas -lptf77blas
.elif ${WITH_BLAS} == gotoblas
.if ${PORT_OPTIONS:MBUILTIN_BLAS}
RUN_DEPENDS +=	${LOCALBASE}/lib/libgoto2p.so:${PORTSDIR}/math/gotoblas
.endif
LAPACK =	-lgoto2p
.elif !empty(WITH_BLAS:Mreference*)
RUN_DEPENDS +=	${LOCALBASE}/lib/liblapack.so:${PORTSDIR}/math/lapack
LAPACK =	-llapack
.if ${PORT_OPTIONS:MBUILTIN_BLAS} || ${PORT_OPTIONS:MCBLAS}
RUN_DEPENDS +=	${LOCALBASE}/lib/libblas.so:${PORTSDIR}/math/blas
LAPACK+=	-lblas
.endif
.endif #WITH_BLAS
.endif #WITH_EXTERNAL_LAPACK

.if ${PORT_OPTIONS:MOPENMP}
.if ${PORT_OPTIONS:MTHREADS}
IGNORE =	WITH_OPENMP is incompatible with WITH_THREADS
.endif
.if !empty(CC:M*clang*)
IGNORE =	clang does not support WITH_OPENMP, use WITH_THREADS instead
.endif
OPENMP_CFLAGS ?=	-fopenmp
CFLAGS+=		${OPENMP_CFLAGS}
LDFLAGS+=		${OPENMP_CFLAGS}
CONFIGURE_ARGS+=	--enable-multithreading=openmp
.elif ${PORT_OPTIONS:MTHREADS}
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=	--enable-multithreading=pthreads
.else
CONFIGURE_ARGS+=	--enable-multithreading=no
.endif

.if ${PORT_OPTIONS:MSHARED}
USE_LDCONFIG=	yes
.endif

.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
PLIST_SUB+=	${o}=""
.else
PLIST_SUB+=	${o}="@comment "
.endif
.endfor

.if ${PORT_OPTIONS:MWITH_SUPERMATRIX}
CONFIGURE_ARGS+=	--enable-supermatrix
.else
CONFIGURE_ARGS+=	--disable-supermatrix
.endif

.if !(defined(USE_GCC) || defined(USE_FORTRAN) || !empty(CC:M*gcc4*))
CONFIGURE_ARGS+=	--disable-autodetect-f77-ldflags \
			--disable-autodetect-f77-name-mangling
.endif

.if !empty(MACHINE_CPU:Msse3)
CFLAGS+=		-msse3
LDFLAGS+=		-msse3
CONFIGURE_ARGS+=	--enable-vector-intrinsics=sse
.else
CONFIGURE_ARGS+=	--enable-vector-intrinsics=none
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif
CFLAGS+=	${PICFLAG}
LDFLAGS+=	${PICFLAG} -Wl,-x

.if defined(MEMORY_ALIGNMENT)
CONFIGURE_ARGS+=	--enable-memory-alignment=${MEMORY_ALIGNMENT}
.if defined(LDIM_ALIGNMENT)
CONFIGURE_ARGS+=	--enable-ldim-alignment
.endif
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	libflame.pdf
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

SHLIB_MAJOR?=	0

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name '*.sh' -o -name '*.sh.in' \) | \
	${XARGS} ${REINPLACE_CMD} -E \
	-e 's@(#!)(/bin/bash)@\1${LOCALBASE}\2@'
	@${FIND} ${WRKSRC} -type f \( -name 'makefile' -o -name 'config.mk.in' \) | \
	${XARGS} ${REINPLACE_CMD} \
	-e 's@-lpthread@${PTHREAD_LIBS}@g' \
	-e 's@-fPIC@${PICFLAG}@g'
	@${REINPLACE_CMD} \
	-e '\@MK_INCL_DIR_INST_W_ARCH_VERS[[:blank:]]*:=@ \
	s@-$$(ARCH_VERS)@/libflame@' \
	-e '\@MK_FLAMEC_...S_INST_W_ARCH_VERS[[:blank:]]*:=@ \
	{N; s@-$$(ARCH_VERS)@@; s@\.so@&.${SHLIB_MAJOR}@2;}' \
	-e '\@^$$(MK_INCL_DIR_INST):@,\@^endif@d' \
	-e '\@^$$(INSTALL_PREFIX)/lib/%\.a:@,\@^endif@d' \
	-e 's@^\($$(INSTALL_PREFIX)/lib/%\)\(-$$(ARCH_VERS)\)\(\.a:\)@\1\3@' \
	-e '\@^$$(INSTALL_PREFIX)/lib/%.*\.so:@ \
	s@\(-$$(ARCH_VERS)\)\(\.so\)@\2.${SHLIB_MAJOR}@' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's@gcc)@cc|gcc*)@g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
	-e '\@FLA_LIB_PATH[[:blank:]]*:=@ \
	s@$$(INSTALL_PREFIX)/lib@../lib/$$(HOST)@' \
	-e '\@FLA_INC_PATH[[:blank:]]*:=@ \
	s@$$(INSTALL_PREFIX)@${WRKDIR}@' \
	-e '\@HOST[[:blank:]]*:=@ \
	s@sh $$(BUILD_DIRPATH)/ac-utils/config.guess@cat ../config.sys_type@' \
		${WRKSRC}/test/Makefile

pre-configure:
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -o -name '*.fbsd10bak' \
	-o -name '*.orig' \) -delete

post-configure:
.if ${PORT_OPTIONS:MSTATIC}
	@${CP} -af ${WRKSRC} ${WRKSRC}_STATIC
	@${REINPLACE_CMD} -e 's@${PICFLAG}@@' \
	-e '\@FLA_ENABLE_DYNAMIC_BUILD[[:blank:]]*:=@s@yes@no@' \
		${WRKSRC}_STATIC/config/*/config.mk
.endif
.if ${PORT_OPTIONS:MSHARED}
	@${REINPLACE_CMD} \
	-e '\@MK_FLAMEC_LIBS_INST.*[[:blank:]]*:=@ \
	{N; s@$$(INSTALL_PREFIX)/lib/%@&_pic@;}' \
	-e '\@^$$(INSTALL_PREFIX)/lib/%\.a:@s@%@&_pic@1' \
		${WRKSRC}/Makefile
.endif

do-build:
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\n\n===> Building ${o:L} library:\n\n\n\n"
	@cd ${WRKSRC}${o:S|^|_|:M*STATIC}; ${SETENV} ${MAKE_ENV} ${GMAKE} \
	${_MAKE_JOBS} ${MAKE_ARGS} libs
.endif
.endfor

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install-headers
.if ${PORT_OPTIONS:MSHARED}
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install-libs install-lib-symlinks
.endif
.if ${PORT_OPTIONS:MSTATIC}
	@cd ${WRKSRC}_STATIC; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} install-libs
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${_DISTDIR}/${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples; ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.if defined(MAINTAINER_MODE)
BUILD_DEPENDS +=	${RUN_DEPENDS}
CONFIGURE_ARGS+=	--enable-verbose-make-output

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} MK_INCL_DIR_INST_W_ARCH_VERS="${WRKDIR}/include" \
	install-headers
.for o in SHARED STATIC
.if ${PORT_OPTIONS:M${o}}
	@${PRINTF} "\n\n\n===> Testing ${o:L} library:\n\n\n\n"
	@cd ${WRKSRC}${o:S|^|_|:M*STATIC}/test;  ${SETENV} ${MAKE_ENV} \
	${GMAKE} ${_MAKE_JOBS} ${MAKE_ARGS} \
	LIBBLAS="-L${LOCALBASE}/lib ${BLAS} -lm" \
	LIBLAPACK="-L${LOCALBASE}/lib ${LAPACK}" test_libflame ; \
	./test_libflame.x
.endif
.endfor

.endif #MAINTAINER_MODE
.include <bsd.port.mk>
