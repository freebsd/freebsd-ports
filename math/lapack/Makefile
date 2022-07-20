PORTNAME?=	lapack
PORTVERSION=	3.10.1
.if !(defined(BLAS_SLAVEPORT) || defined(CBLAS_SLAVEPORT) || defined(XLAPACK_SLAVEPORT) || defined(LAPACKE_SLAVEPORT))
PORTREVISION=	0
.else
PORTREVISION?=	0	# Never remove this line, keep PORTREVISION?=0 in case.
.endif
CATEGORIES=	math
MASTER_SITES=	https://github.com/Reference-LAPACK/lapack/archive/refs/tags/:src	\
		http://www.netlib.org/lapack/:man	\
		LOCAL/thierry/lapack-${PORTVERSION}/:man
DISTFILES=	v${PORTVERSION}${EXTRACT_SUFX}:src
.if make(makesum) || !(defined(BLAS_SLAVEPORT) || defined(XLAPACK_SLAVEPORT))
DISTFILES+=	manpages.tgz:man
.endif
DIST_SUBDIR=	lapack-${PORTVERSION}

MAINTAINER?=	fortran@FreeBSD.org
COMMENT?=	Linear Algebra PACKage

LICENSE?=	BSD3CLAUSE

USES=		cmake:testing cpe fortran
WRKSRC=		${WRKDIR}/lapack-${PORTVERSION}
# The actual math/scilab needs deprecated functions - to be removed later
CMAKE_ON=	BUILD_SHARED_LIBS BUILD_DEPRECATED
USE_LDCONFIG=	yes
CPE_VENDOR=	lapack_project
CPE_PRODUCT=	lapack

SVERSION=	${PORTVERSION:R:R}
PLIST_SUB=	SVERSION="${SVERSION}" VER=${PORTVERSION}

.include <bsd.port.options.mk>

.if defined(BLAS_SLAVEPORT)
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}/BLAS/SRC
INSTALL_WRKSRC=		${BUILD_WRKSRC}
BLASLIB=		libblas.a
LIBS=			blas
PLIST_SUB+=		BLAS="" CBLAS="@comment " LAPACK="@comment " XLAPACK="@comment " LAPACKE="@comment "
.elif defined(CBLAS_SLAVEPORT)
BUILD_DEPENDS+=		lapack>0:math/lapack
LIB_DEPENDS+=		libblas.so:math/blas
CMAKE_ON+=		CBLAS
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}/CBLAS
INSTALL_WRKSRC=		${BUILD_WRKSRC}
CBLASLIB=		libcblas.a
LIBS=			cblas
PLIST_SUB+=		BLAS="@comment " CBLAS="" LAPACK="@comment " XLAPACK="@comment " LAPACKE="@comment "
.elif defined(LAPACKE_SLAVEPORT)
USES+=			blaslapack
CMAKE_ON+=		USE_OPTIMIZED_BLAS USE_OPTIMIZED_LAPACK LAPACKE
CMAKE_ARGS+=		-DBLAS_LIBRARIES="${LOCALBASE}/lib/libblas.so"		\
			-DLAPACK_LIBRARIES="${LOCALBASE}/lib/liblapack.so"
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}/LAPACKE
INSTALL_WRKSRC=		${BUILD_WRKSRC}
LAPACKELIB=		liblapacke.a
PLIST_SUB+=		BLAS="@comment " CBLAS="@comment " LAPACK="@comment " XLAPACK="@comment " LAPACKE=""
.elif defined(XLAPACK_SLAVEPORT)
LIB_DEPENDS+=		libblas.so:math/blas		\
			liblapack.so:math/lapack	\
			libxblas.so:math/xblas
FFLAGS+=		-fallow-argument-mismatch
CMAKE_ON+=		USE_OPTIMIZED_BLAS USE_XBLAS  BUILD_TESTING
CMAKE_ARGS+=		-DBLAS_LIBRARIES="${LOCALBASE}/lib/libblas.so"
PLIST_SUB+=		BLAS="@comment " CBLAS="@comment " LAPACK="@comment " XLAPACK="" LAPACKE="@comment "
.else
# Upstream recommand to use an optimized BLAS, but it would cause conflicts
# among the dependencies: for an optimized lapack switch to OpenBLAS.
# BUILD_TESTING to get tmglib.
LIB_DEPENDS+=		libblas.so:math/blas
. if defined(MAINTAINER_MODE)
USES+=			python:3.6+,build,test
. endif
CMAKE_ON+=		USE_OPTIMIZED_BLAS BUILD_TESTING
CMAKE_ARGS+=		-DBLAS_LIBRARIES="${LOCALBASE}/lib/libblas.so"
LIBS=			lapack
PLIST_SUB+=		BLAS="@comment " CBLAS="@comment " LAPACK="" XLAPACK="@comment " LAPACKE="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${SED} -Ee '\
		s@^(FORTRAN|LOADER)([[:blank:]]*=)(.*)@\1\2 $${FC}@; \
		s@^(OPTS[[:blank:]]*=)(.*)@\1 $${FFLAGS} $${EXTRAFLAGS}@; \
		s@^NOOPT[[:blank:]]*=.*@& $${EXTRAFLAGS}@; \
		s@^(LOADOPTS[[:blank:]]*=)(.*)@\1 $${LDFLAGS} $${EXTRAFLAGS}@; \
		s@^(CC[[:blank:]]*=)(.*)@@; \
		s@^(FC[[:blank:]]*=)(.*)@@; \
		s@^(CFLAGS[[:blank:]]*)(=)(.*)@\1 += $${EXTRAFLAGS}@; \
		s@^(FFLAGS[[:blank:]]*=)(.*)@@; \
		s@^(LDFLAGS[[:blank:]]*=)(.*)@@; \
		\@(BLAS|LAPACKE|RAN)LIB[[:blank:]]*=@d;' \
			${WRKSRC}/make.inc.example > ${WRKSRC}/make.inc

pre-configure:
	${REINPLACE_CMD} -e 's@\./lapack_testing\.py@${S} &@' \
		${WRKSRC}/Makefile
	${FIND} ${WRKSRC} -name Makefile | ${XARGS}	\
		${SED} -i ".bak" -e 's|^ifdef|.ifdef|;s|^endif|.endif|'
.if defined(MAINTAINER_MODE)
	${REINPLACE_CMD} -e 's|PythonInterp 2.7|PythonInterp ${PYTHON_VER}|'	\
		${WRKSRC}/CMakeLists.txt
.endif

post-build:
.if defined(BLAS_SLAVEPORT)
	${SED} -e 's|%%LIB%%|blas|g;s|cd SRC|cd BLAS/SRC|;s|SRC/lib|BLAS/SRC/lib|'	\
		${FILESDIR}/static.mk >> ${BUILD_WRKSRC}/CMakeFiles/blas.dir/build.make
	(cd ${CONFIGURE_WRKSRC} && ${MAKE} -f BLAS/SRC/CMakeFiles/blas.dir/build.make build-static)
.elif defined(CBLAS_SLAVEPORT)
	${SED} -e 's|%%LIB%%|cblas|g;s|cd SRC|cd CBLAS/src|;s|SRC/lib|CBLAS/src/lib|'	\
		${FILESDIR}/static.mk >> ${BUILD_WRKSRC}/src/CMakeFiles/cblas.dir/build.make
	(cd ${CONFIGURE_WRKSRC} && ${MAKE} -f CBLAS/src/CMakeFiles/cblas.dir/build.make build-static)
.elif defined(LAPACKE_SLAVEPORT)
	${SED} -e 's|%%LIB%%|lapacke|g;s|cd SRC|cd LAPACKE|' ${FILESDIR}/static.mk	\
		>> ${BUILD_WRKSRC}/CMakeFiles/lapacke.dir/build.make
	(cd ${CONFIGURE_WRKSRC} && ${MAKE} -f LAPACKE/CMakeFiles/lapacke.dir/build.make build-static)
.else # xlapack + Lapack + tmglib
	${SED} -e 's|%%LIB%%|lapack|g' ${FILESDIR}/static.mk	\
		>> ${BUILD_WRKSRC}/SRC/CMakeFiles/lapack.dir/build.make
	(cd ${CONFIGURE_WRKSRC} && ${MAKE} -f SRC/CMakeFiles/lapack.dir/build.make build-static)
	${SED} -e 's|%%LIB%%|tmglib|g;s|cd SRC|cd TESTING/MATGEN|;s|SRC/lib|TESTING/MATGEN/lib|'	\
		${FILESDIR}/static.mk >> ${BUILD_WRKSRC}/TESTING/MATGEN/CMakeFiles/tmglib.dir/build.make
	(cd ${BUILD_WRKSRC} && ${MAKE} -f TESTING/MATGEN/CMakeFiles/tmglib.dir/build.make build-static)
.endif

pre-su-install:
.if !(defined(BLAS_SLAVEPORT) || defined(CBLAS_SLAVEPORT) || defined(XLAPACK_SLAVEPORT) || defined(LAPACKE_SLAVEPORT))
	cd ${WRKDIR} && ${FIND} man/man3 -type f | ${GREP} -v Users_julie | \
	tee ${WRKDIR}/manpages | ${SED} 's|$$|.gz|' >> ${TMPPLIST}
	cd ${WRKDIR} && \
	${XARGS} -J @ ${INSTALL_MAN} @ ${STAGEDIR}${MAN3PREFIX}/man/man3 < ${WRKDIR}/manpages
.endif

post-install:
.if defined(BLAS_SLAVEPORT)
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/BLAS/SRC/${BLASLIB} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/BLAS/blas.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
.elif defined(CBLAS_SLAVEPORT)
	# Avoid conflict with OpenBLAS
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cblas
	${MV} ${STAGEDIR}${PREFIX}/include/*.h ${STAGEDIR}${PREFIX}/include/cblas/
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/${CBLASLIB} ${STAGEDIR}${PREFIX}/lib
.elif defined(LAPACKE_SLAVEPORT)
	# Avoid conflict with OpenBLAS
	${MKDIR} ${STAGEDIR}${PREFIX}/include/lapacke
	${MV} ${STAGEDIR}${PREFIX}/include/*.h ${STAGEDIR}${PREFIX}/include/lapacke/
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/LAPACKE/${LAPACKELIB} ${STAGEDIR}${PREFIX}/lib
.elif defined(XLAPACK_SLAVEPORT)
	${INSTALL_DATA} ${BUILD_WRKSRC}/SRC/liblapack.a ${STAGEDIR}${PREFIX}/lib/libxlapack.a
	${INSTALL_DATA} ${BUILD_WRKSRC}/TESTING/MATGEN/libtmglib.a	\
		${STAGEDIR}${PREFIX}/lib/libxtmglib.a
	${MV} ${STAGEDIR}${PREFIX}/lib/liblapack.so	\
		${STAGEDIR}${PREFIX}/lib/libxlapack.so.${PORTVERSION}
	${LN} -sf libxlapack.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libxlapack.so
	${LN} -sf libxlapack.so.${PORTVERSION}	\
		${STAGEDIR}${PREFIX}/lib/libxlapack.so.${SVERSION}
	${MV} ${STAGEDIR}${PREFIX}/lib/libtmglib.so	\
		${STAGEDIR}${PREFIX}/lib/libxtmglib.so.${PORTVERSION}
	${LN} -sf libxtmglib.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libxtmglib.so
	${LN} -sf libxtmglib.so.${PORTVERSION}	\
		${STAGEDIR}${PREFIX}/lib/libxtmglib.so.${SVERSION}
	${SED} -e 's|lapack|xlapack|g;s|LAPACK|XLAPACK|'		\
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/lapack.pc	\
		> ${STAGEDIR}${PREFIX}/libdata/pkgconfig/xlapack.pc
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/lapack.pc
.else # Lapack
	${INSTALL_DATA} ${BUILD_WRKSRC}/SRC/liblapack.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${BUILD_WRKSRC}/TESTING/MATGEN/libtmglib.a ${STAGEDIR}${PREFIX}/lib
.endif

.include <bsd.port.post.mk>
