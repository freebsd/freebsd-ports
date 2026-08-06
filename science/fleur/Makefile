PORTNAME=	fleur
DISTVERSION=	8.1
CATEGORIES=	science # chemistry
#MASTER_SITES=	https://iffgit.fz-juelich.de/fleur/fleur/-/archive/MaX-R${DISTVERSION}/
MASTER_SITES=	LOCAL/yuri # same as unversioned tarball linked from https://www.flapw.de/master/downloads/#download-via-configure-script: it only downloads from a browser, and fails with fetch/wget
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FLAPW code for atomic computations in quantum chemistry and physics
WWW=		https://www.flapw.de/master/ \
		https://iffgit.fz-juelich.de/fleur/fleur

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fatal error: cannot find an intrinsic module named 'ieee_arithmetic' at (1)

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-html>0:devel/py-pytest-html@${PY_FLAVOR}

USES=		cmake:noninja fortran gnome localbase:ldflags python:test
USE_GNOME=	libxml2

#USE_GITLAB=	yes
#GL_SITE=	https://iffgit.fz-juelich.de
#GL_TAGNAME=	6960e037c34e5b704cd79718ec34c7147ccbf06a16fef397c7e3316f47e99a39

USE_GITHUB=	nodefault
GH_TUPLE=	wannier-developers:wannier90:v3.1.0:wannier90/external/wannier90/src

WRKSRC=		${WRKDIR}/fleur-release

OPTIONS_DEFINE=		HDF5 KPLIB MPI SCALAPACK ELPA LIBXC #WANNIER WANNIER exernal wannier90 is not compatible and is replaced with submodule
OPTIONS_DEFAULT=	MPI SCALAPACK ELPA #WANNIER # HDF5 KPLIB LIBXC

HDF5_CMAKE_BOOL=	CLI_FLEUR_USE_HDF5
HDF5_CMAKE_ON=		-DHDF5_INCLUDE_DIRS=${LOCALBASE}/include
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_BROKEN=		missing hdf5.mod in hdf5 # hdf5 doesn't include Fortran binding

KPLIB_DESC=		Use kpLib library
#KPLIB_CMAKE_BOOL=	CLI_FLEUR_USE_KPLIB
KPLIB_DEPENDS=		libkplib.so:science/kplib
KPLIB_BROKEN=		fails to find the pre-installed libkplib.so library, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/691

MPI_CMAKE_BOOL=		CLI_FLEUR_USE_MPI
MPI_LDFLAGS=		-lmpich -lmpifort
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

SCALAPACK_DESC=		Use the ScaLAPACK Scalable LAPACK library
SCALAPACK_CMAKE_BOOL=	FLEUR_USE_SCALAPACK # no such variable, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/692, it works only through FLEUR_LIBRARIES set below
SCALAPACK_LDFLAGS=	-lscalapack
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack
SCALAPACK_IMPLIES=	MPI

ELPA_DESC=		Use libelpa, Eigenvalue SoLver for Petaflop Applications
ELPA_CMAKE_BOOL=	FLEUR_USE_ELPA # no such variable, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/689, it works only through FLEUR_LIBRARIES set below
ELPA_LDFLAGS=		-lelpa
ELPA_LIB_DEPENDS=	libelpa.so:math/elpa

LIBXC_DESC=		Use libxc library
LIBXC_CMAKE_BOOL=	CLI_FLEUR_USE_LIBXC
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc
LIBXC_BROKEN=		silently links with libxc when CLI_FLEUR_USE_LIBXC=OFF, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/690

#WANNIER_DESC=		Use Wannier library
#WANNIER_CMAKE_BOOL=	CLI_FLEUR_USE_WANNIER
#WANNIER_LIB_DEPENDS=	libwannier90.so:science/wannier90

.include <bsd.port.options.mk>

FFLAGS=			-I${LOCALBASE}/include
FLEUR_LIBRARIES=		-L${LOCALBASE}/lib;-ldl;-lfftw3;-lxml2;-llapack;-lopenblas
.if ${PORT_OPTIONS:MMPI}
SUFFIX=			_MPI
FLEUR_LIBRARIES:=	${FLEUR_LIBRARIES};-lmpich;-lmpifort
.endif
.if ${PORT_OPTIONS:MSCALAPACK}
FFLAGS+=		-fallow-argument-mismatch
FLEUR_LIBRARIES:=	${FLEUR_LIBRARIES};-lscalapack
.endif
.if ${PORT_OPTIONS:MELPA}
FFLAGS+=		-I${LOCALBASE}/include/elpa-2021.11.001/modules
FLEUR_LIBRARIES:=	${FLEUR_LIBRARIES};-lelpa
.endif
#.if ${PORT_OPTIONS:MWANNIER}
#FLEUR_LIBRARIES:=	${FLEUR_LIBRARIES};-lwannier90
#.endif

CMAKE_ARGS=	-DFLEUR_LIBRARIES:STRING="${FLEUR_LIBRARIES}"
LDFLAGS+=	-llapack -lopenblas -lxml2 # to fix missing symbols, see https://iffgit.fz-juelich.de/fleur/fleur/-/issues/670

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

# tests as of 8.1: 54 passed, 1 skipped, 24 deselected, 2 warnings in 249.24s (0:04:09)

.include <bsd.port.mk>
