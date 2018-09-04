# $FreeBSD$

PORTNAME=	cp2k
DISTVERSION=	6.1
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry and solid state physics software package

LICENSE=	GPLv2+

LIB_DEPENDS=	libblas.so:math/blas \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack

USES=		fortran gmake python:build tar:bz2

MAKEFILE=	${WRKSRC}/makefiles/Makefile
MAKE_ARGS=	XARCH=FreeBSD-${NOLIBINT}libint-gfortran VERSION=${VERSION} FC=gfortran${GCC_DEFAULT} CC=${CC} LD=gfortran${GCC_DEFAULT}

BUILD_WRKSRC=	${WRKSRC}/.build
INSTALL_WRKSRC=	${BUILD_WRKSRC}

BINARY_ALIAS=	python=${PYTHON_CMD}

OPTIONS_DEFINE=		LIBINT
OPTIONS_SINGLE=		MULTIPROCESSING
OPTIONS_SINGLE_MULTIPROCESSING=		SERIAL OPENMP # for the complete list see "3a. ARCH files" in https://www.cp2k.org/howto:compile
OPTIONS_DEFAULT=	LIBINT SERIAL
MULTIPROCESSING_DESC=	Multiprocessing

LIBINT_DESC=		Use libint to evaluate integrals
LIBINT_VARS_OFF=	NOLIBINT=no
LIBINT_LIB_DEPENDS=	libint.so:science/libint

SERIAL_DESC=		Single core (no multiprocessing)
SERIAL_VARS=		VERSION=sopt

OPENMP_VARS=		VERSION=ssmp
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp
OPENMP_BROKEN=		undefined reference to `dfftw_plan_with_nthreads_': https://github.com/cp2k/cp2k/issues/12 (need OPENMP=on in math/fftw3 ?)

PLIST_FILES=		bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|^LIBS.*=.*|& ${LDFLAGS}|' ${WRKSRC}/arch/FreeBSD-*

pre-build:
	@${MKDIR} ${BUILD_WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exe/*/${PORTNAME}.* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
