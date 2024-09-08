PORTNAME=	mpb
DISTVERSION=	1.11.1
PORTREVISION=	8
CATEGORIES=	science
MASTER_SITES=	https://github.com/NanoComp/mpb/releases/download/v${DISTVERSION}/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	MIT Photonic-Bands
WWW=		https://mpb.readthedocs.io/en/latest/

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
# NLOPT should be enabled in science/libctl
LIB_DEPENDS=	libctl.so:science/libctl \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		libnlopt.so:math/nlopt

USES=		fortran guile:2.2,alias libtool pkgconfig readline
USE_GCC=	yes
USE_LDCONFIG=	yes
# Do not use --with-mpi, because it is not guaranted
# that science/hdf5 also built with option PARALLEL
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ATLAS OPENMP

ATLAS_DESC=	Use math/atlas instead of math/openblas
OPENMP_DESC=	Use OpenMP (enable also in math/fftw3)

ATLAS_LIB_DEPENDS=	libatlas.so:math/atlas
ATLAS_USES_OFF=		blaslapack:openblas
ATLAS_CONFIGURE_ON=	--with-lapack=-lalapack
ATLAS_CONFIGURE_OFF=	--with-blas=openblas --with-lapack=-lopenblas
OPENMP_CONFIGURE_ON=	--with-openmp

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
	${COPYTREE_SHARE} "*.ctl *.scm" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
