# $FreeBSD$

PORTNAME=	dynare
DISTVERSION=	4.5.7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.dynare.org/release/source/

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Software platform for handling a wide class of economic models

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ARCH_amd64=	64
ARCH_i386=	32
PLIST_SUB=	ARCH=${ARCH_${ARCH}}

BUILD_DEPENDS=	${LOCALBASE}/include/boost/unordered_set.hpp:devel/boost-libs \
		ctangle:devel/cweb
LIB_DEPENDS=	libumfpack.so:math/suitesparse \
		libmatio.so:math/matio \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libfftw3_threads.so:math/fftw3 \
		libfftw3f_threads.so:math/fftw3-float

USES=		fortran gmake localbase pkgconfig shebangfix tar:xz
GNU_CONFIGURE=	yes
SHEBANG_FILES=	matlab/modules/reporting/success.sh

INFO=	dynare

OPTIONS_DEFINE=		OCTAVE MATLAB
OCTAVE_DESC=		Enable compilation of MEX files for Octave
MATLAB_DESC=		Enable compilation of MEX files for MATLAB
OPTIONS_DEFAULT=	OCTAVE
OPTIONS_SUB=		yes

MATLAB_CONFIGURE_ENABLE=	matlab
OCTAVE_CONFIGURE_ENABLE=	octave
OCTAVE_LIB_DEPENDS=		liboctave.so:math/octave
OCTAVE_USES=			compiler:c++14-lang
OCTAVE_VARS=			CXXFLAGS=--std=c++14 # https://github.com/DynareTeam/dynare/issues/1599

post-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} "Follow instructions at http://www.freebsd.org/doc/handbook/linuxemu-matlab.html"
	@${ECHO_MSG} "on how to install MATLAB on FreeBSD"
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
