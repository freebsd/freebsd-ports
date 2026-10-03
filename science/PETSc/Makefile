PORTNAME=	PETSc
DISTVERSION=	3.26.0
PORTREVISION=	1
CATEGORIES=	science devel
MASTER_SITES=	https://web.cels.anl.gov/projects/petsc/download/release-snapshots/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of data structures and routines from Argonne National Laboratory
WWW=		https://petsc.org/release/ \
		https://gitlab.com/petsc/petsc \
		https://github.com/petsc/petsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	#

USES=		blaslapack:openblas bison cmake:indirect fortran gmake mpi \
		pkgconfig python shebangfix xorg
USE_LDCONFIG=	yes
USE_XORG=	x11

SHEBANG_FILES=	configure lib/petsc/bin/*.py lib/petsc/bin/*.sh		\
		lib/petsc/bin/saws/SAWs.py lib/petsc/bin/saws/*.bash	\
		lib/petsc/bin/petscnagfor share/petsc/chkerrconvert.py	\
		config/*.py src/sys/tests/ex55.py

GNU_CONFIGURE=	yes
CONFIGURE_LOG=	configure.log
CONFIGURE_ARGS=	--with-shared-libraries=1 \
		--with-mpi-dir=${MPI_HOME} \
		--with-python=1	\
		--with-python-pkg-config=${LOCALBASE}/libdata/pkgconfig \
		FCFLAGS="${FCFLAGS}" FFLAGS="${FCFLAGS}"	\
		${CONFIGURE_ARGS_${ARCH}} CPPFLAGS="${CPPFLAGS}" \
		AR=${AR} RANLIB=${RANLIB} \
		MAKEFLAGS="${MAKEFLAGS}" LDFLAGS="${LDFLAGS}" LIBS="${LIBS}"
CONFIGURE_ARGS_amd64=	CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2"
CONFIGURE_ARGS_i386=	CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2"

.if defined(WITH_DEBUG)
PLIST_SUB+=	DEBUG="" NO_DEBUG="@comment "
.else
CONFIGURE_ARGS+=--with-debugging=no
PLIST_SUB+=	NODEBUG="" DEBUG="@comment "
.endif

MAKEFILE=	makefile
TEST_TARGET=	test # 152 of 11396 tests (1.3%) fail due to missing files like /usr/local/share/petsc/datafiles/meshes/square_periodic.msh (tests expect the packe to be installed)
TEST_ENV=	DISPLAY=${DISPLAY} XAUTHORITY=${XAUTHORITY}

LIBS=		${BLASLIB} ${MPI_LIBS}

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
BINARY_ALIAS=	python=${PYTHON_CMD}

PLIST_SUB+=	SHLIB=${DISTVERSION} SHL=${DISTVERSION:C/\.[0-9]$//}

# Trilinos not supported: see https://gitlab.com/petsc/petsc/-/work_items/1943
# Trilinos-ML deprecated: see https://code-aster.org/forum/d/31916-code-aster-1754-petsc-and-trilinos-ml
OPTIONS_DEFINE=		HPDDM HYPRE METIS SOWING SUPERLU
# LONGINDEX match IDXTYPEWIDTH being set to 64 in math/metis
OPTIONS_DEFINE_amd64=	LONGINDEX
OPTIONS_DEFINE_aarch64=	LONGINDEX
OPTIONS_DEFINE_powerpc64=LONGINDEX
OPTIONS_DEFINE_powerpc64le=LONGINDEX
OPTIONS_DEFINE_riscv64=	LONGINDEX
OPTIONS_DEFAULT=	HPDDM HYPRE METIS SOWING SUPERLU

HPDDM_DESC=		Support HP domain decomposition methods
HPDDM_LIB_DEPENDS=	libhpddm_c.so:science/hpddm
HPDDM_CONFIGURE_ON=	--with-hpddm=1

HYPRE_DESC=		Enable Hypre Scalable Linear Solvers
HYPRE_LIB_DEPENDS=	libHYPRE.so:science/hypre
HYPRE_CONFIGURE_ON=	--with-hypre=1

LONGINDEX_DESC=	Set indexes to 64 bits
LONGINDEX_PREVENTS=	SUPERLU
LONGINDEX_CONFIGURE_ON=	--with-64-bit-indices # as opposed to 32-bit indices that are default

METIS_DESC=		Enable metis support for graph partitioning algorithms
METIS_LIB_DEPENDS=	libmetis.so:math/metis
METIS_CONFIGURE_ON=	--with-metis=1 # --with-parmetis=1 to use include/parmetis.h

SOWING_DESC=		Enable text processing with Sowing
SOWING_BUILD_DESC=	tohtml:textproc/sowing
SOWING_CONFIGURE_ON=	--with-sowing=1

SUPERLU_DESC=		Enable SuperLU for sparse factorization
SUPERLU_LIB_DEPENDS=	libsuperlu.so:math/superlu
SUPERLU_CONFIGURE_ON=	--with-superlu=1 \
			--with-superlu-include=${LOCALBASE}/include/superlu \
			--with-superlu-lib=${LOCALBASE}/lib/libsuperlu.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpetsc.so.${DISTVERSION}
	${FIND} ${STAGEDIR}${PREFIX} -name "*.html" -delete
	cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/win32fe lib/petsc/conf/uninstall.py
	${REINPLACE_CMD} -i '' -e 's|^PYTHON = .*|PYTHON = ${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/lib/petsc/conf/petscvariables
.if defined(WITH_DEBUG)
	${REINPLACE_CMD} -i '' -e 's|#!/.*|#!${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/lib/petsc/conf/reconfigure-arch-*-c-debug.py
.endif
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/petsc/bin/__pycache__ # stray directory

# the file /usr/local/share/petsc/examples/config/gmakegen.py is expected by some dependencies, at least by math/slepc

.include <bsd.port.mk>
