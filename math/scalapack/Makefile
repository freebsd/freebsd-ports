# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scalapack
PORTVERSION=	2.0.2
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	NL
DISTFILES=	scalapack-${PORTVERSION}.tgz manpages.tgz
DIST_SUBDIR=	scalapack
EXTRACT_ONLY=	scalapack-${PORTVERSION}.tgz manpages.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The ScaLAPACK Scalable LAPACK library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	elmer-mathlibs-1*

USE_LDCONFIG=	yes
USES=		cmake fortran pathfix
CMAKE_ARGS_ST=	-DBUILD_STATIC_LIBS:BOOL=ON
CMAKE_ARGS_SH=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS=	${CMAKE_ARGS_ST}

ARCH2FIX=	PBLAS/SRC PBLAS/SRC/PBBLAS PBLAS/SRC/PTOOLS PBLAS/SRC/PTZBLAS \
		REDIST/SRC SRC TOOLS TOOLS/LAPACK

DATADIR=	${PREFIX}/share/${PORTNAME:tu}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:tu}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
PLIST_SUB=	SVERSION=${SVERSION} PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	scalapack_install.ps scalapackqref.ps  \
		lawn100.ps pblasqref.ps manual.ps design.ps \
		pumma_refmanual.ps trans.ps
.endif

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=		yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=		-lf77blas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	libblas.so:math/blas
LIB_DEPENDS+=	liblapack.so:math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if exists(${LOCALBASE}/mpi/openmpi/bin/mpirun)
WITH_OPENMPI=	yes
.endif

.if defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:net/openmpi
.else
#LIB_DEPENDS+=	libmpich.so:net/mpich2
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:net/mpich2
.endif

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

CFLAGS+=	${FPIC}
FFLAGS+=	${FPIC}
SVERSION=	2

.if defined(WITH_OPTIMIZED_FLAGS)
.if ${ARCH} == "amd64"
FFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
CFLAGS+=	-pipe -O3 -ffast-math -funroll-all-loops -fpeel-loops -ftracer -funswitch-loops -funit-at-a-time
.elif ${ARCH} == "i386"
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -mcpu=i686 -march=i686 -mfancy-math-387 -mpreferred-stack-boundary=3
.else
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.endif
.endif

NOOPT=	-O0
.if defined(WITH_OPENMPI)
MPIF77=	${LOCALBASE}/mpi/openmpi/bin/mpif77
MPICC=	${LOCALBASE}/mpi/openmpi/bin/mpicc
.else
MPIF77=	${LOCALBASE}/bin/mpif77
MPICC=	${LOCALBASE}/bin/mpicc
.endif

pre-configure:
	${CP} -p ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	${CP} ${WRKSRC}/SLmake.inc.example ${WRKSRC}/SLmake.inc
	${REINPLACE_CMD} -e 's|@BLAS@|${BLAS}|g; s|@LAPACK@|${LAPACK}|g;s|@LAPACK@|${LAPACK}|g;s|@LAPACK@|${LAPACK}|g;s|@LAPACK@|${LAPACK}|g; s|@WRKSRC@|${WRKSRC}|g ; s|@LOCALBASE@|${LOCALBASE}|g ; s|@CC@|${CC}|g ; s|@CFLAGS@|${CFLAGS}|g ; s|@F77@|${F77}|g ; s|@MPIF77@|${MPIF77}|g ; s|@MPICC@|${MPICC}|g ; s|@FFLAGS@|${FFLAGS}|g ; s|@NOOPT@|${NOOPT}|g ; s|@F77EXTRAFLAGS@|${F77EXTRAFLAGS}|g ; s|^ARCH *.= ar|ARCMD = ar|' ${WRKSRC}/SLmake.inc
.for mkf in ${ARCH2FIX}
	${REINPLACE_CMD} -e 's|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${mkf}/Makefile
.endfor

post-build:
	${RM} -r ${WRKSRC}/CMakeFiles ${WRKSRC}/CMakeCache.txt
	${CP} -p ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile
	(cd ${WRKSRC} &&	\
	${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS:C|BUILD_STATIC_LIBS|BUILD_SHARED_LIBS|} ${CMAKE_SOURCE_PATH})
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET})

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libscalapack.a ${STAGEDIR}${PREFIX}/lib
	${MV} ${STAGEDIR}${PREFIX}/lib/libscalapack.so ${STAGEDIR}${PREFIX}/lib/libscalapack.so.${SVERSION}
	${LN} -sf libscalapack.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib/libscalapack.so
	${INSTALL_MAN}  ${WRKDIR}/MANPAGES/man/manl/*.l ${STAGEDIR}${PREFIX}/man/manl
	${MKDIR} ${STAGEDIR}${PREFIX}/share/SCALAPACK/TESTING
	(cd ${WRKSRC}/TESTING/ ;\
	${INSTALL_PROGRAM} x* ${STAGEDIR}${PREFIX}/share/SCALAPACK/TESTING ;\
	${INSTALL_DATA} *.dat ${STAGEDIR}${PREFIX}/share/SCALAPACK/TESTING)
	${INSTALL_DATA} ${FILESDIR}/scalapack.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/PBLAS/SRC/*.h ${STAGEDIR}${PREFIX}/include
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/Makefile    ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.cc ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.f  ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/design.ps    | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/design.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/lawn100.ps   | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/lawn100.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/manual.ps    | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/manual.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/pblasqref.ps | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/pblasqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/pumma_refmanual.ps | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/pumma_refmanual.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/scalapack_install.ps | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/scalapack_install.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/scalapackqref.ps | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/scalapackqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/trans.ps | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/trans.ps.gz
.endif

.if defined(MAINTAINER_MODE)
regression-test:	build
. if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
. endif
	${LOCALBASE}/bin/mpd &
	(sleep 5 && cd ${BUILD_WRKSRC}/TESTING && ${MAKE_CMD} test)
	${LOCALBASE}/bin/mpdallexit

.endif

.include <bsd.port.post.mk>
