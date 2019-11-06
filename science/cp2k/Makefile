# $FreeBSD$

PORTNAME=	cp2k
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.0
PORTREVISION=	7
CATEGORIES=	science

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	f03e6277feea9a65d543ca6c1184f58d3e83bc2a.patch:-p2 \
		d00a71c4d0276aab849ac6a6483b9dcdb65613c9.patch:-p2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry and solid state physics software package

BROKEN=		unfetchable

LICENSE=	GPLv2+

LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack
RUN_DEPENDS=	cp2k-data>0:science/cp2k-data

USES=		fortran gmake localbase:ldflags python:build tar:bz2
USE_GITHUB=	yes

MAKEFILE=	${WRKSRC}/makefiles/Makefile
MAKE_ARGS=	XARCH=FreeBSD-${NOLIBINT}libint-gfortran VERSION=${VERSION} FC=gfortran${GCC_DEFAULT} CC=${CC} LD=gfortran${GCC_DEFAULT} \
		DATA_DIR=${DATADIR}

BUILD_WRKSRC=	${WRKSRC}/.build
INSTALL_WRKSRC=	${BUILD_WRKSRC}

BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=		LIBINT
OPTIONS_SINGLE=		MULTIPROCESSING
OPTIONS_SINGLE_MULTIPROCESSING=		SERIAL OPENMP MPI OPENMP_MPI # for the complete list see "3a. ARCH files" in https://www.cp2k.org/howto:compile
OPTIONS_DEFAULT=	LIBINT SERIAL
MULTIPROCESSING_DESC=	Multiprocessing

LIBINT_DESC=		Use libint to evaluate integrals
LIBINT_VARS_OFF=	NOLIBINT=no
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

EXECUTABLES=		cp2k graph cp2k_shell dbcsr_performance_driver

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
	@${REINPLACE_CMD} 's|LIBS.*=.*|& ${LDFLAGS}|; s|^FCFLAGS.*=.*|& -I${LOCALBASE}/include|; s| -march=native||' ${WRKSRC}/arch/FreeBSD-*

pre-build:
	@${MKDIR} ${BUILD_WRKSRC}

do-install:
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/exe/*/${e}.${VERSION} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
