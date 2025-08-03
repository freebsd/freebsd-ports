PORTNAME=	freefem++
DISTVERSIONPREFIX=	v
DISTVERSION=	4.14
PORTREVISION=	10
CATEGORIES=	math science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Partial differential equation solver
WWW=		https://freefem.org/ \
		https://github.com/FreeFem/FreeFem-sources

LICENSE=	LGPL3

BROKEN=		fails to compile with nlopt-2.9.0, see https://github.com/FreeFem/FreeFem-sources/issues/324
BROKEN_FreeBSD_15=	compilation fails with clang-19, see https://github.com/FreeFem/FreeFem-sources/issues/323

BUILD_DEPENDS=	bash:shells/bash		\
		gmm++>0:math/gmm++		\
		pipe:misc/pipe			\
		tetgen:math/tetgen
LIB_DEPENDS=	libhdf5.so:science/hdf5		\
		libamd.so:math/suitesparse-amd	\
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libumfpack.so:math/suitesparse-umfpack	\
		libarpack.so:math/arpack-ng	\
		libfftw3.so:math/fftw3		\
		libgsl.so:math/gsl		\
		libipopt.so:math/ipopt		\
		libmetis.so:math/metis		\
		libscotch.so:cad/scotch		\
		libcmumps.so:math/mumps		\
		libnlopt.so:math/nlopt		\
		libsuperlu.so:math/superlu
RUN_DEPENDS=	bash:shells/bash		\
		pipe:misc/pipe

USES=		autoreconf bison blaslapack:openblas compiler:c++14-lang fortran \
		gl gmake localbase perl5 pkgconfig shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	FreeFem
GH_PROJECT=	FreeFem-sources

SHEBANG_GLOB=	ff-pkg-download.in
SHEBANG_FILES=	examples/CheckAllEdp ./examples/misc/speedtest.sh

CPPFLAGS+=	-I${LOCALBASE}/include/superlu
.if !defined{WITH_DEBUG}
LDFLAGS+=	-s
.endif

LDFLAGS+=	-pthread # workaround for https://github.com/FreeFem/FreeFem-sources/issues/296#issuecomment-1839198380

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CNOFLAGS="${CFLAGS}" LIBS=-lz
CONFIGURE_ARGS=	--disable-download		\
		--without-mpi			\
		--with-blas=${BLASLIB}		\
		--with-lapack=${LAPACKLIB}

USE_GL=		gl glu glut

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_DEFAULT=EXAMPLES

PORTEXAMPLES=	*

PLIST_SUB=	VER=${PORTVERSION}
DATADIR=	${PREFIX}/share/FreeFEM/${PORTVERSION}

TEST_TARGET=	check # 1 test fails, see https://github.com/FreeFem/FreeFem-sources/issues/281

pre-configure:
	@${REINPLACE_CMD} -e 's|-llapack|${LAPACKLIB}|' ${WRKSRC}/configure.ac

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
