# $FreeBSD$

PORTNAME=	cp2k
DISTVERSIONPREFIX=	v
DISTVERSION=	7.1.0-20200518
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry and solid state physics software package

LICENSE=	GPLv2+

LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack
RUN_DEPENDS=	cp2k-data>0:science/cp2k-data

USES=		fortran gmake localbase:ldflags python:build tar:bz2
USE_GITHUB=	yes
GH_TAGNAME=	2e995eec7fd208c8a72d9544807bd8b8ba8cd1cc
GH_TUPLE=	cp2k:dbcsr:f385868eec7c89f40ac9d6d9783fc34a05d2f68e:cp2k_dbcsr/exts/dbcsr \
		pseewald:fprettify:2b2801bf91dd651c417c232bb891d407bf81085c:pseewald_fprettify/tools/prettify/fprettify \
		aradi:fypp:7895a7efb7d2f07dc284cece6cc9474297b8dc55:aradi_fypp/exts/dbcsr/tools/build_utils/fypp

MAKE_ARGS=	XARCH=FreeBSD-gfortran VERSION=${VERSION} FC=gfortran${GCC_DEFAULT} CC=${CC} LD=gfortran${GCC_DEFAULT} \
		DATA_DIR=${DATADIR}

BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=		LIBINT
OPTIONS_SINGLE=		MULTIPROCESSING
OPTIONS_SINGLE_MULTIPROCESSING=		SERIAL OPENMP MPI OPENMP_MPI # for the complete list see "3a. ARCH files" in https://www.cp2k.org/howto:compile
OPTIONS_DEFAULT=	LIBINT SERIAL
MULTIPROCESSING_DESC=	Multiprocessing

LIBINT_DESC=		Use libint to evaluate integrals
LIBINT_LIB_DEPENDS=	libint.so:science/libint

SERIAL_DESC=		Single core (no multiprocessing)
SERIAL_VARS=		VERSION=sopt

OPENMP_VARS=		VERSION=ssmp

MPI_VARS=		VERSION=popt
MPI_LIB_DEPENDS=	libmpich.so:net/mpich \
			libscalapack.so:math/scalapack
MPI_LDFLAGS=		-lmpifort

OPENMP_MPI_DESC=	Enable both OpenMP and MPI
OPENMP_MPI_VARS=	VERSION=psmp
OPENMP_MPI_LIB_DEPENDS=	${MPI_LIB_DEPENDS}
OPENMP_MPI_LDFLAGS=	${MPI_LDFLAGS}

EXECUTABLES=		cp2k graph cp2k_shell

PLIST_FILES=		${EXECUTABLES:C/(.*)/bin\/\1.${VERSION}/}

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

pre-build:
	@${ECHO} ${PORTVERSION} > ${WRKSRC}/REVISION

do-install:
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/exe/*/${e}.${VERSION} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
