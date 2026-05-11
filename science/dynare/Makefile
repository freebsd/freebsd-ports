PORTNAME=	dynare
DISTVERSION=	7.0
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

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tokenizer.hpp:devel/boost-libs \
		octave:math/octave
LIB_DEPENDS=	libopenblas.so:math/openblas \
		libslicot.so:math/slicot \
		libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	epstool:graphics/epstool \
		gnuplot:math/gnuplot \
		octave:math/octave \
		octave-forge-datatypes>0:math/octave-forge-datatypes \
		octave-forge-statistics>0:math/octave-forge-statistics \
		pstoedit:graphics/pstoedit \
		xfig:graphics/xfig

USES=		bison compiler:c++20-lang fortran localbase:ldflags meson pkgconfig tar:xz

MESON_ARGS=	-Dbuild_for=octave \
		-Dpardiso=disabled

SUB_FILES=	pkg-message

post-install:
	# remove empty directories, see https://git.dynare.org/Dynare/dynare/-/issues/1835
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

.include <bsd.port.mk>
