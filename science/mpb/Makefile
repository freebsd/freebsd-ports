# Created by: ijliao
# $FreeBSD$

PORTNAME=	mpb
DISTVERSION=	1.11.1
CATEGORIES=	science
MASTER_SITES=	https://github.com/NanoComp/mpb/releases/download/v${DISTVERSION}/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	MIT Photonic-Bands

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libctl.so:science/libctl \
		libfftw3.so:math/fftw3 \
		libgc-threaded.so:devel/boehm-gc-threaded \
		libguile-2.2.so:lang/guile2 \
		libhdf5.so:science/hdf5

USES=		fortran libtool pkgconfig readline
GNU_CONFIGURE=	yes
USE_GCC=	yes
# Do not use --with-mpi, because it is not guaranted
# that science/hdf5 also built with option PARALLEL
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		ATLAS NLOPT OPENMP
OPTIONS_DEFAULT=	NLOPT

ATLAS_DESC=	Use math/atlas instead of math/openblas
NLOPT_DESC=	Use math/nlopt (enable also in science/libctl)
OPENMP_DESC=	Use OpenMP (enable also in math/fftw3)

ATLAS_LIB_DEPENDS=	libatlas.so:math/atlas
ATLAS_USES_OFF=		blaslapack:openblas
ATLAS_CONFIGURE_ON=	--with-lapack=-lalapack
ATLAS_CONFIGURE_OFF=	--with-blas=openblas --with-lapack=-lopenblas
NLOPT_LIB_DEPENDS=	libnlopt.so:math/nlopt
OPENMP_CONFIGURE_ON=	--with-openmp

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
	${COPYTREE_SHARE} "*.ctl *.scm" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
