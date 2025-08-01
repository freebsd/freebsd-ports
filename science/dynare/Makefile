PORTNAME=	dynare
DISTVERSION=	5.4
PORTREVISION=	14
CATEGORIES=	science # economics
MASTER_SITES=	https://www.dynare.org/release/source/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software platform for handling a wide class of economic models
WWW=		https://www.dynare.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	cannot open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory
.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tokenizer.hpp:devel/boost-libs
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libmatio.so:math/matio \
		libopenblas.so:math/openblas \
		libsz.so:science/libaec
RUN_DEPENDS=	epstool:graphics/epstool \
		gnuplot:math/gnuplot \
		pstoedit:graphics/pstoedit \
		xfig:graphics/xfig # README says that these executables are required for the test suite

USES=		bison compiler:c++17-lang fortran gmake localbase:ldflags tar:xz tex
USE_TEX=	pdftex

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-matlab \
		--disable-doc

FCFLAGS+=	-fPIC # required because configure tests with -shared

SUB_FILES=	pkg-message

OPTIONS_DEFINE=			OCTAVE
OPTIONS_DEFAULT=		OCTAVE
OPTIONS_SUB=			yes

OCTAVE_DESC=			Integrate with Octave (main way to use Dynare)
OCTAVE_CONFIGURE_ENABLE=	octave
OCTAVE_CONFIGURE_ON=		--disable-mex-kalman-steady-state # Kalman Steady State MEX file for Octave - requires the non-free library slicot-5.0
OCTAVE_BUILD_DEPENDS=		octave:math/octave
OCTAVE_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libfftw3f.so:math/fftw3-float \
				libgsl.so:math/gsl \
				libumfpack.so:math/suitesparse-umfpack
OCTAVE_RUN_DEPENDS=		octave:math/octave \
				octave-forge-statistics>0:math/octave-forge-statistics

post-install:
	# remove empty directories, see https://git.dynare.org/Dynare/dynare/-/issues/1835
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
