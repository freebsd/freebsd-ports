PORTNAME=	cp2k
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry and solid state physics software package

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	fypp:devel/py-fypp@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack
RUN_DEPENDS=	cp2k-data>0:science/cp2k-data
TEST_DEPENDS=	bash:shells/bash

USES=		fortran gmake localbase:ldflags python:build shebangfix tar:bz2

USE_GITHUB=	yes
GH_TUPLE=	cp2k:dbcsr:c134996:cp2k_dbcsr/exts/dbcsr \
		pseewald:fprettify:71781aa:pseewald_fprettify/tools/prettify/fprettify

SHEBANG_FILES=	tools/regtesting/do_regtest

GCC_VERSION=	${GCC_DEFAULT} # ${_USE_GCC}

MAKE_ARGS=	XARCH=FreeBSD-gfortran VERSION=${VERSION} FC=gfortran${GCC_VERSION} CC=${CC} LD=gfortran${GCC_VERSION} \
		DATA_DIR=${DATADIR}

BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD} make=${GMAKE} # make - only for tests

OPTIONS_DEFINE=		LIBINT
OPTIONS_SINGLE=		MULTIPROCESSING
OPTIONS_SINGLE_MULTIPROCESSING=		SERIAL OPENMP MPI OPENMP_MPI # for the complete list see https://github.com/cp2k/cp2k/blob/master/INSTALL.md
OPTIONS_DEFAULT=	LIBINT OPENMP
MULTIPROCESSING_DESC=	Multiprocessing

LIBINT_DESC=		Use libint to evaluate integrals
LIBINT_LIB_DEPENDS=	libint.so:science/libint

SERIAL_DESC=		Single core (no multiprocessing)
SERIAL_VARS=		VERSION=sopt EFFECTIVE_VERSION=ssmp # now is a flavor of ssmp with NUM_THEADS=1
SERIAL_CFLAGS=		${OPENMP_CFLAGS}
SERIAL_CXXFLAGS=	${OPENMP_CXXFLAGS}
SERIAL_LDFLAGS=		${OPENMP_LDFLAGS}
SERIAL_PLIST_FILES=	${EXECUTABLES_CORE:C/(.*)/bin\/\1.${VERSION}/} # symlinks

OPENMP_VARS=		VERSION=ssmp EFFECTIVE_VERSION=ssmp
OPENMP_CFLAGS=		-fopenmp
OPENMP_CXXFLAGS=	-fopenmp
OPENMP_LDFLAGS=		/usr/lib/libgomp.so

MPI_VARS=		VERSION=popt EFFECTIVE_VERSION=psmp # now is a flavor of psmp with NUM_THEADS=1
MPI_LIB_DEPENDS=	libmpich.so:net/mpich \
			libscalapack.so:math/scalapack
MPI_LDFLAGS=		-lmpifort
MPI_PLIST_FILES=	${EXECUTABLES_CORE:C/(.*)/bin\/\1.${VERSION}/} # symlinks
MPI_BROKEN=		https://github.com/cp2k/cp2k/issues/2128

OPENMP_MPI_DESC=	Enable both OpenMP and MPI
OPENMP_MPI_VARS=	VERSION=psmp EFFECTIVE_VERSION=psmp
OPENMP_MPI_CFLAGS=	${OPENMP_CFLAGS}
OPENMP_MPI_CXXFLAGS=	${OPENMP_CXXFLAGS}
OPENMP_MPI_LDFLAGS=	${OPENMP_LDFLAGS}
OPENMP_MPI_LIB_DEPENDS=	${MPI_LIB_DEPENDS}
OPENMP_MPI_LDFLAGS=	${MPI_LDFLAGS}
OPENMP_MPI_BROKEN=	https://github.com/cp2k/cp2k/issues/2128

EXECUTABLES_CORE=	cp2k cp2k_shell
EXECUTABLES_EXTRA=	dumpdcd graph grid_miniapp xyz2dcd
EXECUTABLES=		${EXECUTABLES_CORE} ${EXECUTABLES_EXTRA}

PLIST_FILES=		${EXECUTABLES:C/(.*)/bin\/\1.${EFFECTIVE_VERSION}/}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENMP} || ${PORT_OPTIONS:MOPENMP_MPI}
pre-configure:
	@if [ ! -e ${LOCALBASE}/lib/libfftw3_omp.so ] ; then \
	  ${ECHO_MSG} "The OPENMP and OPENMP_MPI options require math/fftw3" ; \
	  ${ECHO_MSG} "to be built and installed with the OPENMP option ON" ; \
	  exit 1; \
	fi
.endif

post-patch:
	@${REINPLACE_CMD} -i '' 's|LIBS.*=.*|& ${LDFLAGS}|; s|^FCFLAGS.*=.*|& -I${LOCALBASE}/include|; s| -march=native||' ${WRKSRC}/arch/FreeBSD-*

xpre-build:
	@${ECHO} ${PORTVERSION} > ${WRKSRC}/REVISION

do-install:
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/exe/*/${e}.${EFFECTIVE_VERSION} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-SERIAL-on:
.for e in ${EXECUTABLES_CORE}
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${e}.${EFFECTIVE_VERSION} ${e}.${VERSION}
.endfor

do-test: # fails to run: some Linux-only commands are present, also /usr/local/bin/ar: invalid option -- /
	@cd ${WRKSRC} && \
		${TOUCH} arch/local.${EFFECTIVE_VERSION} && \
		${SETENV} ${MAKE_ENV} ./tools/regtesting/do_regtest -maxtasks 8

.include <bsd.port.pre.mk>

.  if ${GCC_DEFAULT} >= 10 # only needed when MPI is on, but flags aren't passed into DBCSR sub-project, see https://github.com/cp2k/cp2k/issues/2128
FCFLAGS+=	-fallow-argument-mismatch
.  endif

# build instructions: https://github.com/cp2k/cp2k/blob/master/INSTALL.md

.include <bsd.port.post.mk>
