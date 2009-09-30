# New ports collection makefile for:    blacs
# Date created:                 5 May 2003
# Whom:                         NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	blacs
PORTVERSION=	1.7
PORTREVISION=	11
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/blacs/
DISTNAME=	BLACS
DISTFILES=	mpiblacs.tgz blacstester.tgz mpiblacs-patch03.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=	blacs_install.ps f77blacsqref.ps lawn94.ps \
		cblacsqref.ps  mpi_prop.ps mpiblacs_issues.ps
.endif
DIST_SUBDIR=	blacs
EXTRACT_ONLY=	mpiblacs.tgz blacstester.tgz mpiblacs-patch03.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The BLACS (Basic Linear Algebra Communication Subprograms)

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/mpi/openmpi/bin/mpirun)
WITH_OPENMPI=   yes
.endif

.if defined(WITH_OPENMPI)
BUILD_DEPENDS=	${LOCALBASE}/mpi/openmpi/lib/libmpi.so:${PORTSDIR}/net/openmpi
RUN_DEPENDS=	${LOCALBASE}/mpi/openmpi/bin/mpirun:${PORTSDIR}/net/openmpi
EXTRA_PATCHES+=	${FILESDIR}/Bmake.inc-openmpi.diff
.else
LIB_DEPENDS=	mpich:${PORTSDIR}/net/mpich2
RUN_DEPENDS=	${LOCALBASE}/mpich2/bin/mpirun:${PORTSDIR}/net/mpich2
EXTRA_PATCHES+=	${FILESDIR}/Bmake.inc-mpich.diff
.endif

USE_LDCONFIG=	yes

USE_FORTRAN=	yes
USE_GMAKE=yes
F77EXTRAFLAGS=	#-w -fno-globals -fugly-complex
DEBUG_LEVEL=	0

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

pre-patch:
	(${CP} ${WRKSRC}/BMAKES/Bmake.MPI-LINUX ${WRKSRC}/Bmake.inc)

post-patch:
	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}

pre-configure:
	(${REINPLACE_CMD} -e 's|@WRKSRC@|${WRKSRC}|g ; s|@DEBUG_LEVEL@|${DEBUG_LEVEL}|g ; s|@LOCALBASE@|${LOCALBASE}|g ; s|@CC@|${CC}|g ; s|@CFLAGS@|${CFLAGS}|g ; s|@F77@|${F77}|g ; s|@FFLAGS@|${FFLAGS}|g ; s|@F77EXTRAFLAGS@|${F77EXTRAFLAGS}|g ; s|   ARCH *.= ar|   ARCMD = ar|'  ${WRKSRC}/Bmake.inc)
	(${REINPLACE_CMD} -e 's|@WRKSRC@|${WRKSRC_SHARED}|g ; s|@DEBUG_LEVEL@|${DEBUG_LEVEL}|g ; s|@LOCALBASE@|${LOCALBASE}|g ; s|@CC@|${CC}|g ; s|@CFLAGS@|${CFLAGS_SHARED}|g ; s|@F77@|${F77}|g ; s|@FFLAGS@|${FFLAGS_SHARED}|g ; s|@F77EXTRAFLAGS@|${F77EXTRAFLAGS}|g ; s|   ARCH *.= ar|   ARCMD = ar|'  ${WRKSRC_SHARED}/Bmake.inc)
	${REINPLACE_CMD} -e 's|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/SRC/MPI/Makefile
	${REINPLACE_CMD} -e 's|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC_SHARED}/SRC/MPI/Makefile

do-build:
	(cd ${WRKSRC}; make mpi; make tester)
	(cd ${WRKSRC_SHARED}; make mpi; make tester)

post-build:
	${RM} -rf ${WRKDIR}/tmp_shared
	${MKDIR} ${WRKDIR}/tmp_shared
	${MV} ${WRKSRC_SHARED}/LIB/blacs_MPI-FreeBSD-${DEBUG_LEVEL}.a          ${WRKSRC_SHARED}/LIB/libblacsc.a
	${MV} ${WRKSRC_SHARED}/LIB/blacsF77init_MPI-FreeBSD-${DEBUG_LEVEL}.a   ${WRKSRC_SHARED}/LIB/libblacsf77.a
	${MV} ${WRKSRC_SHARED}/LIB/blacsCinit_MPI-FreeBSD-${DEBUG_LEVEL}.a     ${WRKSRC_SHARED}/LIB/libblacs.a
	${FIND} ${WRKSRC_SHARED} -name "*\.a" -exec ${MV} {} ${WRKDIR}/tmp_shared \;
	cd ${WRKDIR}/tmp_shared ; for i in `ls *.a | ${SED}  's/\.a//' `; do \
		ld -Bshareable -o $${i}.so.${SVERSION} -x -soname $${i}.so.${SVERSION} --whole-archive $${i}.a ;\
	${LN} -s $${i}.so.${SVERSION} $${i}.so ;\
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/LIB/blacsCinit_MPI-FreeBSD-${DEBUG_LEVEL}.a ${PREFIX}/lib/libblacsc.a
	${INSTALL_DATA} ${WRKSRC}/LIB/blacsF77init_MPI-FreeBSD-${DEBUG_LEVEL}.a ${PREFIX}/lib/libblacsf77.a
	${INSTALL_DATA} ${WRKSRC}/LIB/blacs_MPI-FreeBSD-${DEBUG_LEVEL}.a ${PREFIX}/lib/libblacs.a

	${INSTALL_DATA} ${WRKDIR}/tmp_shared/libblacsc.so.${SVERSION}   ${PREFIX}/lib/libblacsc.so.${SVERSION}
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/libblacsf77.so.${SVERSION} ${PREFIX}/lib/libblacsf77.so.${SVERSION}
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/libblacs.so.${SVERSION}    ${PREFIX}/lib/libblacs.so.${SVERSION}

	${INSTALL_DATA} ${WRKDIR}/tmp_shared/libblacsc.so   ${PREFIX}/lib/libblacsc.so
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/libblacsf77.so ${PREFIX}/lib/libblacsf77.so
	${INSTALL_DATA} ${WRKDIR}/tmp_shared/libblacs.so    ${PREFIX}/lib/libblacs.so

	${MKDIR} ${PREFIX}/share/BLACS/TESTING
	( cd ${WRKSRC_SHARED}/TESTING/EXE ; \
	  ${INSTALL_PROGRAM} xCbtest_MPI-FreeBSD-${DEBUG_LEVEL} ${PREFIX}/share/BLACS/TESTING/xCbtest_MPI-FreeBSD; \
	  ${INSTALL_PROGRAM} xFbtest_MPI-FreeBSD-${DEBUG_LEVEL} ${PREFIX}/share/BLACS/TESTING/xFbtest_MPI-FreeBSD; \
	  ${INSTALL_DATA}  bsbr.dat   ${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  bt.dat     ${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  comb.dat   ${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  sdrv.dat   ${PREFIX}/share/BLACS/TESTING)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/blacs_install.ps   | ${GZIP_CMD} > ${DOCSDIR}/blacs_install.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/cblacsqref.ps      | ${GZIP_CMD} > ${DOCSDIR}/cblacsqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/f77blacsqref.ps    | ${GZIP_CMD} > ${DOCSDIR}/f77blacsqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/lawn94.ps          | ${GZIP_CMD} > ${DOCSDIR}/lawn94.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/mpi_prop.ps        | ${GZIP_CMD} > ${DOCSDIR}/mpi_prop.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/mpiblacs_issues.ps | ${GZIP_CMD} > ${DOCSDIR}/mpiblacs_issues.ps.gz
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
