# New ports collection makefile for:  petsc
# Date created:               25 September 2004
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	petsc
PORTVERSION=	2.2.1
CATEGORIES=	math parallel
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/petsc/%SUBDIR%/
MASTER_SITE_SUBDIR=	. software_old
DISTNAME=	v${PORTVERSION}-${PATCH_LEVEL}.${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable, Extensible Toolkit for Scientific computation

PATCH_LEVEL=	23

HAS_CONFIGURE=		yes
USE_PYTHON=		yes
USE_REINPLACE=		yes
CONFIGURE_SCRIPT=	config/configure.py
CONFIGURE_LOG=		configure.log
CONFIGURE_ENV=		PETSC_ARCH=${TARGET}	\
			PETSC_DIR=${WRKSRC}
CONFIGURE_ARGS=		--prefix=${PREFIX} --CFLAGS="${CFLAGS}"	\
			--CXX_CXXFLAGS="${CXXFLAGS}" --FFLAGS="${FFLAGS}"
MAKEFILE=		makefile
MAKE_ENV=		PETSC_DIR=${WRKSRC} BOPT=O

PKGMESSAGE=		${WRKDIR}/pkg-message

.if !defined(WITHOUT_X11)
USE_XLIB=		yes
CONFIGURE_ARGS+=	--with-x-include=${X11BASE}/include				\
			--with-x-library=${X11BASE}/lib/libX11.so
.endif

FFLAGS?=	-O2
PFX=		${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PFX}
TARGET=		${OPSYS:L}
PLIST_SUB=	PFX=${PFX} TARGET=${TARGET}

.if !defined(WITHOUT_BLASLAPACK)
LIB_DEPENDS+=	f77blas.1:${PORTSDIR}/math/atlas
LIBBLASLAPACK=	"-L${LOCALBASE}/lib -lalapack -lf77blas -lcblas -latlas -lg2c -lm"
CONFIGURE_ARGS+=	--with-blas-lapack-lib=${LIBBLASLAPACK}
.endif

.if !defined(WITHOUT_SUPERLU)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsuperlu.a:${PORTSDIR}/math/superlu
CONFIGURE_ARGS+=	--with-superlu-include=${LOCALBASE}/include/superlu	\
			--with-superlu-lib="-L${LOCALBASE}/lib -lsuperlu"
.endif

.if !defined(WITHOUT_UMFPACK)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libumfpack.a:${PORTSDIR}/math/umfpack
CONFIGURE_ARGS+=	--with-umfpack-include="${LOCALBASE}/include/UMFPACK"	\
			--with-umfpack-lib="-L${LOCALBASE}/lib -lumfpack -lamd"
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
#BUILD_DEPENDS+=	c2html:${PORTSDIR}/textproc/c2html	\
#		pdflatex:${PORTSDIR}/print/teTeX-base	\
#		doc2lt:${PORTSDIR}/textproc/sowing
.endif

LIBSCALAPACK=	${LOCALBASE}/lib/libscalapack.a
LIBBLACS=	${LOCALBASE}/lib/libblacs.a
MPIDIR=		${LOCALBASE}/mpich

.include <bsd.port.pre.mk>

.if exists(${MPIDIR}/bin/mpiCC)
WITH_MPI=	yes
.endif
.if defined(WITH_MPI)
PKGNAMESUFFIX+=		-mpich
BUILD_DEPENDS+=		${MPIDIR}/bin/mpiCC:${PORTSDIR}/net/mpich
RUN_DEPENDS+=		${MPIDIR}/bin/mpirun:${PORTSDIR}/net/mpich
CONFIGURE_ARGS+=	--with-mpi-dir=${LOCALBASE}/mpich
CONFLICTS=		petsc-2*
PLIST_SUB+=		MPI=""
.else
CONFIGURE_ARGS+=	--with-mpi=0
CONFLICTS=		petsc-mpich-2*
WITHOUT_BS95=		yes
WITHOUT_PARMETIS=	yes
WITHOUT_SPOOLES=	yes
PLIST_SUB+=		MPI="@comment "
.endif

.if defined(WITHOUT_BS95)
CONFIGURE_ARGS+=	--with-blocksolve95=0
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libBS95.a:${PORTSDIR}/math/blocksolve95
CONFIGURE_ARGS+=	--with-blocksolve95-include=${LOCALBASE}/include	\
			--with-blocksolve95-lib="-L${LOCALBASE}/lib -lBS95"
.endif

.if defined(WITHOUT_PARMETIS)
CONFIGURE_ARGS+=	--with-parmetis=0
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/parmetis/libparmetis.a:${PORTSDIR}/math/parmetis
LIBPARMETIS=	-L${LOCALBASE}/lib/parmetis -lparmetis -lmetis -lm
CONFIGURE_ARGS+=	--with-parmetis=1					\
			--with-parmetis-include=${LOCALBASE}/include/parmetis	\
			--with-parmetis-lib="${LIBPARMETIS}"
.endif

#.if exists(${LIBBLACS})
#WITH_BLACS=	yes
#.endif
#.if defined(WITH_BLACS)
#BUILD_DEPENDS+=	${LIBBLACS}:${PORTSDIR}/math/blacs
#CONFIGURE_ARGS+=	--with_mumps=1		\
#			--with-blacs-lib=1
#. if exists(${LIBSCALAPACK})
#WITH_SCALAPACK=	yes
#. endif
#. if defined(WITH_SCALAPACK)
#BUILD_DEPENDS+=	${LIBSCALAPACK}:${PORTSDIR}/math/scalapack
#CONFIGURE_ARGS+=	--with-scalapack-lib=1
#. endif
#.endif

#.if exists(${LOCALBASE}/bin/lgrind)
#WITH_LGRIND=	yes
#.endif
#.if defined(WITH_LGRIND)
#BUILD_DEPENDS+=	lgrind:${PORTSDIR}/print/lgrind
#RUN_DEPENDS+=	lgrind:${PORTSDIR}/print/lgrind
#.endif

#.if exists(${LOCALBASE}/lib/libnetcdf.so)
#WITH_NETCDF=	yes
#.endif
#.if defined(WITH_NETCDF)
#LIB_DEPENDS+=	netcdf.1:${PORTSDIR}/math/netcdf
#CONFIGURE_ENV+=	NETCDF_INCLUDE=${LOCALBASE}/include	\
#		NETCDF_LIB=${LOCALBASE}/lib
#.endif

.if exists(${LOCALBASE}/bin/svn)
WITH_SVN=	yes
.endif
.if defined(WITH_SVN)
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif

#.if exists(${LOCALBASE}/bin/valgrind)
#WITH_VALGRIND=	yes
#.endif
#.if defined(WITH_VALGRIND)
#BUILD_DEPENDS+=	valgrind:${PORTSDIR}/devel/valgrind
#RUN_DEPENDS+=	valgrind:${PORTSDIR}/devel/valgrind
#.endif

.if !defined(WITHOUT_SPOOLES)
. if exists(${LOCALBASE}/lib/libspooles.a)	\
  && !exists(${LOCALBASE}/include/spooles/MPI/spoolesMPI.h)
BROKEN=	Please deinstall spooles and reinstall spooles-mpich
. else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libspooles.a:${PORTSDIR}/math/spooles-mpich
. endif
CONFIGURE_ARGS+=	--with-spooles-include=${LOCALBASE}/include/spooles	\
			--with-spooles-lib="-L${LOCALBASE}/lib -lspooles -lm"
.endif

pre-everything::
	@${ECHO_MSG}
.if !defined (WITH_MPI)
	@${ECHO_MSG} "Define WITH_MPI to use mpich."
.endif
.if !defined (WITH_SVN)
	@${ECHO_MSG} "Define WITH_SVN to use subversion."
.endif
.if !defined (WITHOUT_X11)
	@${ECHO_MSG} "Define WITHOUT_X11 to remove X11 support."
.endif
.if !defined (WITHOUT_BLASLAPACK)
	@${ECHO_MSG} "Define WITHOUT_BLASLAPACK to remove Blas / Lapack support."
.endif
.if !defined (WITHOUT_BS95)
	@${ECHO_MSG} "Define WITHOUT_BS95 to remove BlockSolve95 support."
.endif
.if !defined (WITHOUT_PARMETIS)
	@${ECHO_MSG} "Define WITHOUT_PARMETIS to remove ParMETIS support."
.endif
.if !defined (WITHOUT_SPOOLES)
	@${ECHO_MSG} "Define WITHOUT_SPOOLES to remove SPOOLES support."
.endif
.if !defined (WITHOUT_SUPERLU)
	@${ECHO_MSG} "Define WITHOUT_SUPERLU to remove SuperLU support."
.endif
.if !defined (WITHOUT_UMFPACK)
	@${ECHO_MSG} "Define WITHOUT_UMFPACK to remove UMFPACK support."
.endif
	@${ECHO_MSG}

pre-configure:
	@${RM} ${WRKSRC}/bmake/common/rules.shared.basic.orig	\
		${WRKSRC}/bmake/common/variables.orig
	@${REINPLACE_CMD} -e "s|AMD/Include|include/AMD|"	\
			-e "s|AMD/Lib|${LOCALBASE}/lib|"	\
		${WRKSRC}/python/PETSc/packages/Umfpack.py

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${PFX}/bin
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${PFX}/bin
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${PFX}/bmake
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/${PFX}/bmake
.if !defined(NOPORTDOCS)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS}	\
		${MAKEFILE} ${MAKE_ARGS} install_docs)
.endif
	@${SED} -e 's|%%PETSC_DIR%%|${PREFIX}/${PFX}|;s|%%PETSC_ARCH%%|${TARGET}|'	\
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.if defined(MAINTAINER_MODE)
test:	build
	@(cd ${BUILD_WRKSRC};	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.endif

.include <bsd.port.post.mk>
