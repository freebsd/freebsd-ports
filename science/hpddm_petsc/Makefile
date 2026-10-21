PORTNAME=	hpddm_petsc
PORTVERSION=	${PETSC_VER}
CATEGORIES=	science
MASTER_SITES=	https://web.cels.anl.gov/projects/petsc/download/release-snapshots/:petsc \
		http://slepc.upv.es/download/distrib/:slepc
DISTFILES=	petsc-${PORTVERSION}${EXTRACT_SUFX}:petsc \
		slepc-${PORTVERSION}${EXTRACT_SUFX}:slepc
EXTRACT_ONLY=	petsc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Interface between PETSc and HPDDM
WWW=		https://petsc.org/release/ \
		https://gitlab.com/petsc/petsc \
		https://github.com/petsc/petsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhpddm_c.so:science/hpddm	\
		libHYPRE.so:science/hypre	\
		libmetis.so:math/metis		\
		libpetsc.so:science/PETSc	\
		libscalapack.so:math/scalapack	\
		libslepc.so:math/slepc		\
		libsuperlu.so:math/superlu
BUILD_RUN_DEPENDS=mumps>=5.3.1:math/mumps	\
		tohtml:textproc/sowing

USES=		blaslapack:openblas bison cmake:indirect fortran gmake mpi \
		pkgconfig python shebangfix xorg
USE_LDCONFIG=	yes
USE_XORG=	x11

SHEBANG_FILES=	configure lib/petsc/bin/*.py lib/petsc/bin/*.sh		\
		lib/petsc/bin/saws/SAWs.py lib/petsc/bin/saws/*.bash	\
		lib/petsc/bin/petscnagfor share/petsc/chkerrconvert.py	\
		config/*.py src/sys/tests/ex55.py

WRKSRC=		${WRKDIR}/petsc-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_LOG=	configure.log
CONFIGURE_ARGS=	--with-shared-libraries=1 \
		--with-mpi-dir=${MPI_HOME} \
		--with-python=1	\
		--with-python-pkg-config=${LOCALBASE}/libdata/pkgconfig \
		--download-slepc=${WRKDIR}/slepc-${PORTVERSION}${EXTRACT_SUFX} \
		--with-blaslapack=1 \
		--with-hpddm=1 \
		--with-hpddm-include=${LOCALBASE}/include/HPDDM \
		--with-hypre=1 \
		--with-metis=1 \
		--with-mumps=1 \
		--with-openblas=1 \
		--with-scalapack=1 \
		--with-sowing=1 \
		--with-superlu=1 \
		--with-superlu-include=${LOCALBASE}/include/superlu \
		--with-superlu-lib=${LOCALBASE}/lib/libsuperlu.so \
		FCFLAGS="${FCFLAGS}" FFLAGS="${FCFLAGS}"	\
		${CONFIGURE_ARGS_${ARCH}} CPPFLAGS="${CPPFLAGS}" \
		AR=${AR} RANLIB=${RANLIB} \
		MAKEFLAGS="${MAKEFLAGS}" LDFLAGS="${LDFLAGS}" LIBS="${LIBS}"
CONFIGURE_ARGS_amd64=	CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2"
CONFIGURE_ARGS_i386=	CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2"
# Without PETSC_POST_INSTALLS= it will try to tall SLEPc directly under $PREFIX
MAKE_ARGS+=	PETSC_POST_INSTALLS=

.if defined(WITH_DEBUG)
PETSC_ARCH=	arch-${OPSYS:tl}${OSREL:R}-c-debug
PLIST_SUB+=	DEBUG="" NO_DEBUG="@comment "
.else
CONFIGURE_ARGS+=--with-debugging=no
PETSC_ARCH=	arch-${OPSYS:tl}${OSREL:R}-c-opt
PLIST_SUB+=	NODEBUG="" DEBUG="@comment "
.endif

MAKEFILE=	makefile

SLEPC_WRKSRC=	${WRKSRC}/${PETSC_ARCH}/externalpackages/slepc-${PORTVERSION}
SLEPC_ENV=	SLEPC_DIR=${SLEPC_WRKSRC} PETSC_DIR=${WRKSRC} PETSC_ARCH=${PETSC_ARCH}

LIBS=		${BLASLIB} ${MPI_LIBS}

BINARY_ALIAS=	python=${PYTHON_CMD}

PLIST_FILES=	lib/libhpddm_petsc.so lib/libhpddm_petsc.so.0

pre-configure:
	${CP} ${DISTDIR}/slepc-${PORTVERSION}${EXTRACT_SUFX} ${WRKDIR}

post-build:
	# Build SLEPc while respecting DESTDIR
	cd ${SLEPC_WRKSRC} && \
	${SETENV} ${SLEPC_ENV} ${PYTHON_CMD} ./configure --prefix=${PREFIX}
	cd ${SLEPC_WRKSRC} && \
	${MAKE_CMD} ${SLEPC_ENV} PETSC_SNES_LIB='-Wl,-rpath,${PREFIX}/lib \
		-L${WRKSRC}/${PETSC_ARCH}/lib -lpetsc $${PETSC_EXTERNAL_LIB_BASIC}'
	# Build libhpddm_petsc.so
	${MAKE_CMD} -f ${FILESDIR}/hpddm_petsc.mk ${SLEPC_ENV} PREFIX=${PREFIX} \
		WRKLIB=${SLEPC_WRKSRC}/${PETSC_ARCH}/lib \
		HPDDM_SRC=${LOCALBASE}/share/HPDDM/interface/hpddm_petsc.cpp \
		libhpddm_petsc

do-install:
	${INSTALL_LIB} ${SLEPC_WRKSRC}/${PETSC_ARCH}/lib/libhpddm_petsc.so	\
		${STAGEDIR}${PREFIX}/lib

post-install:
	(cd ${STAGEDIR}${PREFIX}/lib &&	\
		${MV} libhpddm_petsc.so libhpddm_petsc.so.0 && \
		${LN} -sf libhpddm_petsc.so.0 ${STAGEDIR}${PREFIX}/lib/libhpddm_petsc.so)

.include <../../science/PETSc/Makefile.version>
.include <bsd.port.mk>
