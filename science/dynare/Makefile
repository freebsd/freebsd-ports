PORTNAME=	dynare
DISTVERSION=	4.6.4
PORTREVISION=	1
CATEGORIES=	science # economics
MASTER_SITES=	https://www.dynare.org/release/source/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software platform for handling a wide class of economic models

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tokenizer.hpp:devel/boost-libs
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libmatio.so:math/matio \
		libopenblas.so:math/openblas \
		libsz.so:science/szip
RUN_DEPENDS=	epstool:graphics/epstool \
		gnuplot:math/gnuplot \
		pstoedit:graphics/pstoedit \
		xfig:graphics/xfig # README says that these executables are required for the test suite

USES=		bison compiler:c++17-lang fortran gmake localbase tar:xz
USE_TEX=	pdftex
USE_GCC=	yes # clang-11 fails: error: reference to local binding 'ii1' declared in enclosing function 'ss2Iteration_pruning'
		# Clang still doesn't support this c++20 feature, see https://bugs.llvm.org/show_bug.cgi?id=49238

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-matlab \
		--disable-doc

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
OCTAVE_RUN_DEPENDS=		octave:math/octave

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dynare/matlab/preprocessor64/dynare_m

.include <bsd.port.mk>
