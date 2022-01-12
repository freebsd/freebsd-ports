# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	freefem++
PORTVERSION=	4.6
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	math science

MAINTAINER=	kh@mogami.com
COMMENT=	Partial differential equation solver

LICENSE=	LGPL3

BUILD_DEPENDS=	bash:shells/bash		\
		gmm++>0:math/gmm++		\
		pipe:misc/pipe			\
		tetgen:math/tetgen
LIB_DEPENDS=	libhdf5.so:science/hdf5		\
		libumfpack.so:math/suitesparse-umfpack	\
		libarpack.so:math/arpack-ng	\
		libfftw3.so:math/fftw3		\
		libgsl.so:math/gsl		\
		libipopt.so:math/ipopt		\
		libmetis.so:math/metis		\
		libscotch.so:cad/scotch		\
		libcmumps.so:math/mumps		\
		libnlopt.so:math/nlopt		\
		libsuperlu.so:math/superlu	\
		libsz.so:science/szip
RUN_DEPENDS=	bash:shells/bash		\
		pipe:misc/pipe

USE_GITHUB=	yes
GH_ACCOUNT=	FreeFem
GH_PROJECT=	FreeFem-sources

USES=		autoreconf bison blaslapack:openblas compiler:c++11-lib fortran	\
		gl gmake localbase perl5 pkgconfig shebangfix xorg
SHEBANG_GLOB=	ff-pkg-download.in
SHEBANG_FILES=	examples/CheckAllEdp ./examples/misc/speedtest.sh

CPPFLAGS+=	-I${LOCALBASE}/include/superlu
.if !defined{WITH_DEBUG}
LDFLAGS+=	-s
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CNOFLAGS="${CFLAGS}" LIBS=-lz
CONFIGURE_ARGS=	--disable-download		\
		--without-mpi			\
		--with-blas=${BLASLIB}		\
		--with-lapack=${LAPACKLIB}

USE_GL=		gl glu glut

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=EXAMPLES

PLIST_SUB=	VER=${PORTVERSION}
DATADIR=	${PREFIX}/share/FreeFEM/${PORTVERSION}

TEST_TARGET=	check

pre-configure:
	${REINPLACE_CMD} -e 's|-llapack|${LAPACKLIB}|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
