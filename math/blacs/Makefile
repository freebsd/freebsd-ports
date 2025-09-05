PORTNAME=	blacs
PORTVERSION=	1.7
PORTREVISION=	41
CATEGORIES=	math
MASTER_SITES=	NETLIB/blacs
DISTNAME=	BLACS
DISTFILES=	mpiblacs.tgz blacstester.tgz mpiblacs-patch03.tgz
DIST_SUBDIR=	blacs
EXTRACT_ONLY=	mpiblacs.tgz blacstester.tgz mpiblacs-patch03.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BLACS (Basic Linear Algebra Communication Subprograms)
WWW=		https://www.netlib.org/blacs/

# See http://icl.cs.utk.edu/lapack-forum/archives/lapack/msg01200.html
LICENSE=	BSD3CLAUSE

SUB_FILES=	pkg-message
USES=		fortran gmake localbase
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	MPI
OPTIONS_RADIO_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	DOCS MPICH

DOCS_DISTFILES=	blacs_install.ps f77blacsqref.ps lawn94.ps \
		cblacsqref.ps  mpi_prop.ps mpiblacs_issues.ps

OPENMPI_USES=	mpi:openmpi
OPENMPI_EXTRA_PATCHES=	${FILESDIR}/Bmake.inc-openmpi.diff

MPICH_USES=	mpi:mpich
MPICH_EXTRA_PATCHES=	${FILESDIR}/Bmake.inc-mpich.diff

.include <bsd.port.pre.mk>

F77EXTRAFLAGS=	#-w -fno-globals -fugly-complex
.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
F77EXTRAFLAGS+=	-fallow-argument-mismatch
.endif

DEBUG_LEVEL=	0

.if ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

WRKSRC_SHARED=${WRKSRC}_shared
CFLAGS_SHARED=${CFLAGS} ${FPIC}
FFLAGS_SHARED=${FFLAGS} ${FPIC}
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
	${RM} -r ${WRKDIR}/tmp_shared
	${MKDIR} ${WRKDIR}/tmp_shared
	${MV} ${WRKSRC_SHARED}/LIB/blacs_MPI-FreeBSD-${DEBUG_LEVEL}.a          ${WRKSRC_SHARED}/LIB/libblacsc.a
	${MV} ${WRKSRC_SHARED}/LIB/blacsF77init_MPI-FreeBSD-${DEBUG_LEVEL}.a   ${WRKSRC_SHARED}/LIB/libblacsf77.a
	${MV} ${WRKSRC_SHARED}/LIB/blacsCinit_MPI-FreeBSD-${DEBUG_LEVEL}.a     ${WRKSRC_SHARED}/LIB/libblacs.a
	${FIND} ${WRKSRC_SHARED} -name "*\.a" -exec ${MV} {} ${WRKDIR}/tmp_shared \;
	cd ${WRKDIR}/tmp_shared ; for i in `ls *.a | ${SED}  's/\.a//' `; do \
		${LD} -Bshareable -o $${i}.so.${SVERSION} -x -soname $${i}.so.${SVERSION} --whole-archive $${i}.a ;\
	${LN} -s $${i}.so.${SVERSION} $${i}.so ;\
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/LIB/blacsCinit_MPI-FreeBSD-${DEBUG_LEVEL}.a ${STAGEDIR}${PREFIX}/lib/libblacsc.a
	${INSTALL_DATA} ${WRKSRC}/LIB/blacsF77init_MPI-FreeBSD-${DEBUG_LEVEL}.a ${STAGEDIR}${PREFIX}/lib/libblacsf77.a
	${INSTALL_DATA} ${WRKSRC}/LIB/blacs_MPI-FreeBSD-${DEBUG_LEVEL}.a ${STAGEDIR}${PREFIX}/lib/libblacs.a

.for lib in libblacsc libblacsf77 libblacs
	${INSTALL_LIB} ${WRKDIR}/tmp_shared/${lib}.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib/${lib}.so.${SVERSION}
	${LN} -s ${lib}.so.${SVERSION} ${STAGEDIR}${PREFIX}/lib/${lib}.so
.endfor

	${MKDIR} ${STAGEDIR}${PREFIX}/share/BLACS/TESTING
	( cd ${WRKSRC_SHARED}/TESTING/EXE ; \
	  ${INSTALL_PROGRAM} xCbtest_MPI-FreeBSD-${DEBUG_LEVEL} ${STAGEDIR}${PREFIX}/share/BLACS/TESTING/xCbtest_MPI-FreeBSD; \
	  ${INSTALL_PROGRAM} xFbtest_MPI-FreeBSD-${DEBUG_LEVEL} ${STAGEDIR}${PREFIX}/share/BLACS/TESTING/xFbtest_MPI-FreeBSD; \
	  ${INSTALL_DATA}  bsbr.dat   ${STAGEDIR}${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  bt.dat     ${STAGEDIR}${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  comb.dat   ${STAGEDIR}${PREFIX}/share/BLACS/TESTING; \
	  ${INSTALL_DATA}  sdrv.dat   ${STAGEDIR}${PREFIX}/share/BLACS/TESTING)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/blacs_install.ps   | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/blacs_install.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/cblacsqref.ps      | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/cblacsqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/f77blacsqref.ps    | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/f77blacsqref.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/lawn94.ps          | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/lawn94.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/mpi_prop.ps        | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/mpi_prop.ps.gz
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/mpiblacs_issues.ps | ${GZIP_CMD} > ${STAGEDIR}${DOCSDIR}/mpiblacs_issues.ps.gz
.endif

.include <bsd.port.post.mk>
