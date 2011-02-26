# New ports collection makefile for:    scalapack
# Date created:                         5 Feb 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scalapack
PORTVERSION=	1.8.0
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/scalapack/
DISTFILES=	scalapack-${PORTVERSION}.tgz manpages.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=	scalapack_install.ps scalapackqref.ps  \
		lawn100.ps pblasqref.ps manual.ps design.ps \
		pumma_refmanual.ps trans.ps
.endif
DIST_SUBDIR=	scalapack
EXTRACT_ONLY=	scalapack-${PORTVERSION}.tgz manpages.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The ScaLAPACK Scalable LAPACK library

BUILD_DEPENDS=	f2c:${PORTSDIR}/lang/f2c
LIB_DEPENDS=	blacs.1:${PORTSDIR}/math/blacs

CONFLICTS=	elmer-mathlibs-1*

USE_LDCONFIG=	yes
USE_FORTRAN=	yes

ARCH2FIX=	PBLAS/SRC PBLAS/SRC/PBBLAS PBLAS/SRC/PTOOLS PBLAS/SRC/PTZBLAS \
		REDIST/SRC SRC TOOLS TOOLS/LAPACK

DATADIR=	${PREFIX}/share/${PORTNAME:U}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:U}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include "files/manpages"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=		yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

.if exists(${LOCALBASE}/mpi/openmpi/bin/mpirun)
WITH_OPENMPI=	yes
.endif

.if defined(WITH_OPENMPI)
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
EXTRA_PATCHES+=	${FILESDIR}/SLmake.inc-openmpi.diff
.else
#LIB_DEPENDS+=	mpich:${PORTSDIR}/net/mpich2
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/mpich2
EXTRA_PATCHES+=	${FILESDIR}/SLmake.inc-mpich.diff
.endif

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

WRKSRC_SHARED=${WRKSRC}_shared
CFLAGS_SHARED=${CFLAGS} ${FPIC}
FFLAGS_SHARED=${CFLAGS} ${FPIC}
SVERSION=1

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

post-patch:
	${CP} ${WRKSRC}/SLmake.inc.example ${WRKSRC}/SLmake.inc
	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
	@${REINPLACE_CMD} -e 's|@BLAS@|${BLAS}|g; s|@LAPACK@|${LAPACK}|g;s|@LAPACK@|${LAPACK}|g;s|@LAPACK@|${LAPACK}|g;s|@LAPACK@|${LAPACK}|g; s|@WRKSRC@|${WRKSRC}|g ; s|@LOCALBASE@|${LOCALBASE}|g ; s|@CC@|${CC}|g ; s|@CFLAGS@|${CFLAGS}|g ; s|@F77@|${F77}|g ; s|@MPIF77@|${MPIF77}|g ; s|@MPICC@|${MPICC}|g ; s|@FFLAGS@|${FFLAGS}|g ; s|@NOOPT@|${NOOPT}|g ; s|@F77EXTRAFLAGS@|${F77EXTRAFLAGS}|g ; s|^ARCH *.= ar|ARCMD = ar|' ${WRKSRC}/SLmake.inc
	@${REINPLACE_CMD} -e 's|@BLAS@|${BLAS}|g; s|@LAPACK@|${LAPACK}|g; s|@WRKSRC@|${WRKSRC_SHARED}|g ; s|@LOCALBASE@|${LOCALBASE}|g ; s|@CC@|${CC}|g ; s|@CFLAGS@|${CFLAGS_SHARED}|g ; s|@F77@|${F77}|g ; s|@MPIF77@|${MPIF77}|g ; s|@MPICC@|${MPICC}|g ; s|@FFLAGS@|${FFLAGS_SHARED}|g ; s|@NOOPT@|${NOOPT} ${FPIC}|g ; s|@F77EXTRAFLAGS@|${F77EXTRAFLAGS}|g ; s|^ARCH *.= ar|ARCMD = ar|' ${WRKSRC_SHARED}/SLmake.inc
.for mkf in ${ARCH2FIX}
	@${REINPLACE_CMD} -e 's|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${mkf}/Makefile
	@${REINPLACE_CMD} -e 's|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC_SHARED}/${mkf}/Makefile
.endfor

do-build:
	(cd ${WRKSRC}; make ; make exe)
	(cd ${WRKSRC_SHARED}; make ; make exe)
	(cd ${WRKSRC}; ${PATCH} < ${FILESDIR}/PBtools.h.patch )
	(cd ${WRKSRC_SHARED}; ${PATCH} < ${FILESDIR}/PBtools.h.patch )
	(${MKDIR} ${WRKSRC}/include ;\
	  cd ${WRKSRC}/include ;\
	  f2c -C++ -P  ${WRKSRC}/SRC/*.f ;\
	  f2c -C++ -P  ${WRKSRC}/TOOLS/*.f ;\
 	  ${CAT} *.P | ${GREP} -v :ref: > scalapack.h)

post-build:
	cd ${WRKSRC_SHARED} ; \
	ld -Bshareable -o libscalapack.so.${SVERSION} -x -soname libscalapack.so.${SVERSION} --whole-archive ${WRKSRC_SHARED}/libscalapack.a ;\
	${LN} -s libscalapack.so.${SVERSION} libscalapack.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/libscalapack.a ${PREFIX}/lib/libscalapack.a
	${INSTALL_DATA} ${WRKSRC_SHARED}/libscalapack.so ${PREFIX}/lib/libscalapack.so
	${INSTALL_DATA} ${WRKSRC_SHARED}/libscalapack.so.1 ${PREFIX}/lib/libscalapack.so.1
	${INSTALL_MAN}  ${WRKDIR}/MANPAGES/man/manl/*.l ${PREFIX}/man/manl
	${MKDIR} ${PREFIX}/share/SCALAPACK/TESTING
	(cd ${WRKSRC_SHARED}/TESTING/ ;\
	${INSTALL_PROGRAM} x* ${PREFIX}/share/SCALAPACK/TESTING ;\
	${INSTALL_DATA} *.dat ${PREFIX}/share/SCALAPACK/TESTING)
	${INSTALL_DATA} ${WRKSRC}/include/scalapack.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/PBLAS/SRC/*.h ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/Makefile    ${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.cc ${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.f  ${PREFIX}/share/examples/SCALAPACK
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/design.ps    | ${GZIP_CMD} > ${DOCSDIR}/design.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/lawn100.ps   | ${GZIP_CMD} > ${DOCSDIR}/lawn100.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/manual.ps    | ${GZIP_CMD} > ${DOCSDIR}/manual.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/pblasqref.ps | ${GZIP_CMD} > ${DOCSDIR}/pblasqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/pumma_refmanual.ps | ${GZIP_CMD} > ${DOCSDIR}/pumma_refmanual.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/scalapack_install.ps | ${GZIP_CMD} > ${DOCSDIR}/scalapack_install.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/scalapackqref.ps | ${GZIP_CMD} > ${DOCSDIR}/scalapackqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/trans.ps | ${GZIP_CMD} > ${DOCSDIR}/trans.ps.gz
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
