PORTNAME=	fleur
DISTVERSION=	5.1.20220103
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FLAPW code for atomic computations in quantum chemistry and physics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		cmake:noninja fortran gnome localbase:ldflags shebanfgix tar:tgz
USE_GNOME=	libxml2

USE_GITLAB=	yes
GL_SITE=	https://iffgit.fz-juelich.de
GL_COMMIT=	0d3b9c4b71dc42ec0ba60fe5c6d2fce212e6fcd4

SHEBANG_FILES=	tests/test.pl

FFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=	-llapack -lopenblas -lxml2 # to fix missing symbols, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/670

OPTIONS_DEFINE=		HDF5 MPI SCALAPACK ELPA WANNIER
OPTIONS_DEFAULT=	MPI SCALAPACK WANNIER # ELPA

HDF5_CONFIGURE_ENV=	FLEUR_USE_HDF5=1 HDF5_ROOT=${LOCALBASE}/lib
HDF5_CONFIGURE_ENV_OFF=	FLEUR_USE_HDF5=0
HDF5_CMAKE_ON=		-DHDF5_INCLUDE_DIRS=${LOCALBASE}/include
HDF5_LDFLAGS=		-lhdf5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_BROKEN=		Missing hdf5.mod in hdf5

MPI_CONFIGURE_ENV=	FLEUR_USE_MPI=1
MPI_CONFIGURE_ENV_OFF=	FLEUR_USE_MPI=0
MPI_LDFLAGS=		-lmpich -lmpifort
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

SCALAPACK_DESC=		Use the ScaLAPACK Scalable LAPACK library
SCALAPACK_CMAKE_BOOL=	FREEBSD_USE_SCALAPACK
SCALAPACK_LDFLAGS=	-lscalapack
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack
SCALAPACK_IMPLIES=	MPI

ELPA_DESC=		Use libelpa, Eigenvalue SoLver for Petaflop Applications
ELPA_CMAKE_BOOL=	FREEBSD_USE_ELPA
ELPA_VARS=		FFLAGS+=-I${LOCALBASE}/include/elpa-2018.05.001/modules
ELPA_LDFLAGS=		-lelpa
ELPA_LIB_DEPENDS=	libelpa.so:math/elpa
ELPA_IMPLIES=		MPI
ELPA_BROKEN=		math/elpa fails to build

WANNIER_DESC=		Use Wannier library
WANNIER_CONFIGURE_ENV=	FLEUR_USE_WANNIER=1
WANNIER_CONFIGURE_ENV_OFF=	FLEUR_USE_WANNIER=0
WANNIER_LDFLAGS=	-lwannier
WANNIER_LIB_DEPENDS=	libwannier.so:science/wannier90

EXECUTABLES=	bin/fleur \
		bin/inpgen
PLIST_FILES=	${EXECUTABLES}

post-install: # strip
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${EXECUTABLES}

do-test: # 9 testcases are known to fail, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/671
	@cd ${TEST_WRKSRC} && ctest

.include <bsd.port.mk>
