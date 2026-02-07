PORTNAME=	fleur
DISTVERSION=	7.2
PORTREVISION=	4
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FLAPW code for atomic computations in quantum chemistry and physics
WWW=		https://www.flapw.de/master/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	Fatal Error: Cannot find an intrinsic module named 'ieee_arithmetic' at (1)

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \

USES=		cmake:noninja fortran gnome localbase:ldflags python:test tar:tgz
USE_GNOME=	libxml2

USE_GITLAB=	yes
GL_SITE=	https://iffgit.fz-juelich.de
GL_TAGNAME=	447eed3b7ec3de5fcdfbd232cd1eda4caefb51d3

FFLAGS=		-I${LOCALBASE}/include
LDFLAGS+=	-llapack -lopenblas -lxml2 # to fix missing symbols, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/670

OPTIONS_DEFINE=		HDF5 KPLIB MPI SCALAPACK ELPA LIBXC WANNIER
OPTIONS_DEFAULT=	MPI SCALAPACK ELPA WANNIER # HDF5 KPLIB LIBXC

HDF5_CMAKE_BOOL=	CLI_FLEUR_USE_HDF5
HDF5_CMAKE_ON=		-DHDF5_INCLUDE_DIRS=${LOCALBASE}/include
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_BROKEN=		Missing hdf5.mod in hdf5 # hdf5 doesn't include Fortran binding

KPLIB_DESC=		Use kpLib library
#KPLIB_CMAKE_BOOL=	CLI_FLEUR_USE_KPLIB
KPLIB_DEPENDS=		libkplib.so:science/kplib
KPLIB_BROKEN=		Fails to find the pre-installed libkplib.so library, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/691

MPI_CMAKE_BOOL=		CLI_FLEUR_USE_MPI
MPI_LDFLAGS=		-lmpich -lmpifort
MPI_LIB_DEPENDS=	libmpich.so:net/mpich
MPI_VARS=		SUFFIX=_MPI

SCALAPACK_DESC=		Use the ScaLAPACK Scalable LAPACK library
SCALAPACK_CMAKE_BOOL=	FLEUR_USE_SCALAPACK # no such variable, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/692, it works only through LDFLAGS set below
SCALAPACK_VARS=		FFLAGS+=-fallow-argument-mismatch
SCALAPACK_LDFLAGS=	-lscalapack
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack
SCALAPACK_IMPLIES=	MPI

ELPA_DESC=		Use libelpa, Eigenvalue SoLver for Petaflop Applications
ELPA_CMAKE_BOOL=	FLEUR_USE_ELPA # no such variable, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/689, it works only through FFLAGS set below
ELPA_VARS=		FFLAGS+=-I${LOCALBASE}/include/elpa-2021.11.001/modules
ELPA_LDFLAGS=		-lelpa
ELPA_LIB_DEPENDS=	libelpa.so:math/elpa

LIBXC_DESC=		Use libxc library
LIBXC_CMAKE_BOOL=	CLI_FLEUR_USE_LIBXC
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc
LIBXC_BROKEN=		Silently links with libxc when CLI_FLEUR_USE_LIBXC=OFF, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/690

WANNIER_DESC=		Use Wannier library
WANNIER_CMAKE_BOOL=	CLI_FLEUR_USE_WANNIER
WANNIER_LIB_DEPENDS=	libwannier.so:science/wannier90

EXECUTABLES=	bin/fleur${SUFFIX} \
		bin/inpgen
PLIST_FILES=	${EXECUTABLES}

CONFLICTS_BUILD=	libxc # see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/690

post-install: # strip
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${EXECUTABLES}

do-test:
	# now: some tests fail or freeze, possibly because of missing hdf5 and kplib dependencies
	# was: 9 testcases are known to fail, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/671
	@cd ${WRKSRC}/testing && pytest tests --build_dir=${TEST_WRKSRC}

# tests fail to run: INTERNALERROR> pluggy._manager.PluginValidationError: unknown hook 'pytest_html_report_title' in plugin <module 'conftest' from '/usr/ports/science/fleur/work/fleur-447eed3b7ec3de5fcdfbd232cd1eda4caefb51d3/testing/conftest.py'>

.include <bsd.port.mk>
