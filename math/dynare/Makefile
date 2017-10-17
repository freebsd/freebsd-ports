# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	dynare
PORTVERSION=	4.5.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.dynare.org/release/source/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Software platform for handling a wide class of economic models

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/unordered_set.hpp:devel/boost-libs \
		ctangle:devel/cweb
LIB_DEPENDS=	libumfpack.so:math/suitesparse \
		libmatio.so:math/matio \
		libhdf5.so:science/hdf5 \
		libopenblas.so:math/openblas \
		libopenblasp.so:math/openblas \
		libfftw3_threads.so:math/fftw3 \
		libfftw3.so:math/fftw3 \
		libfftw3f_threads.so:math/fftw3-float \
		libfftw3f.so:math/fftw3-float

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USES=		fortran gmake pkgconfig tar:xz shebangfix
SHEBANG_FILES=	matlab/modules/reporting/success.sh

INFO=		dynare

OPTIONS_DEFINE=		OCTAVE MATLAB
OCTAVE_DESC=		Enable compilation of MEX files for Octave
MATLAB_DESC=		Enable compilation of MEX files for MATLAB
OPTIONS_DEFAULT=	OCTAVE

MATLAB_CONFIGURE_ENABLE=	matlab
OCTAVE_CONFIGURE_ENABLE=	octave
OCTAVE_BUILD_DEPENDS=		octave:math/octave

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} "Follow instructions at http://www.freebsd.org/doc/handbook/linuxemu-matlab.html"
	@${ECHO_MSG} "on how to install MATLAB on FreeBSD"
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.pre.mk>

post-install:
.if ${ARCH} == "amd64"
	${REINPLACE_CMD} -e 's|preprocessor32|preprocessor64|g' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
