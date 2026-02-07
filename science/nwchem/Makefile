PORTNAME=	nwchem
#DISTVERSIONPREFIX=	v
DISTVERSION=	7.3.1
DISTVERSIONSUFFIX=	-release.revision-23c3b41b-src.2025-11-06
CATEGORIES=	science
MASTER_SITES=	https://github.com/nwchemgit/nwchem/releases/download/v${DISTVERSION}-release/ \
		https://www.chemie.uni-bonn.de/grimme/de/software/dft-d3/:dft3 \
		https://gitlab.com/libxc/libxc/-/archive/${LIBXC_VERSION}/:libxc
DISTFILES=	${PORTNAME}-${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX} \
		dftd3.tgz:dft3 \
		libxc-${LIBXC_VERSION}.tar.gz:libxc
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance computational chemistry software
WWW=		https://nwchemgit.github.io/ \
		https://github.com/nwchemgit/nwchem

LICENSE=	ECL20
LICENSE_NAME=	Educational Community License (ECL) 2.0
LICENSE_FILE=	${WRKSRC}/../LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=	fails to build: gfortran10: error: unrecognized command-line option '-m64'

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libga.so:devel/ga \
		libhwloc.so:devel/hwloc2 \
		libscalapack.so:math/scalapack
RUN_DEPENDS=	nwchem-data>0:science/nwchem-data
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:indirect fortran gettext-runtime gmake perl5 pkgconfig
USE_PERL5=	build

#USE_GITHUB=	yes
#GH_ACCOUNT=	nwchemgit

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKEFILE=	GNUmakefile
ARCH_64BIT=	${ARCH:C/.*64.*/64/:S/${ARCH}//}
MAKE_ARGS=	NWCHEM_TOP=${WRKSRC}/.. NWCHEM_MODULES=all NWCHEM_LONG_PATHS=Y NWCHEM_TARGET=LINUX${ARCH_64BIT} USE_INTERNALBLAS=Y EXTERNAL_GA_PATH=${LOCALBASE} \
		USE_64TO32=y

SUB_FILES=	nwchemrc

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	gcc=${CC} gfortran=gfortran${GCC_DEFAULT}
BINARY_ALIAS+=	make=${GMAKE} # only for LIBXC

PLIST_FILES=	bin/nwchem etc/nwchemrc

LIBXC_VERSION=	7.0.0 # from src/libext/libxc/build_libxc.sh

MAKE_ENV+=	SCALAPACK_LIB=${PREFIX}/lib/libscalapack.so \
		SCALAPACK_SIZE=8

OPTIONS_DEFINE=			LIBXC PYTHON # more potential optional dependencies are listed in src/libext/GNUmakefile
OPTIONS_DEFAULT=		LIBXC PYTHON BLAS_SIZE_4 MPICH # the MPI default should be the same as for the MPI option in math/scalapack and devel/ga
OPTIONS_RADIO=			BLAS_SIZE MPI
OPTIONS_RADIO_BLAS_SIZE=	BLAS_SIZE_4 BLAS_SIZE_8 # should be the same choice as in devel/ga and math/blas or math/openblasblas
OPTIONS_RADIO_MPI=		NOMPI MPICH OPENMPI

BLAS_SIZE_DESC=		BLAS_SIZE value to use during build (should be same as in devel/ga)
BLAS_SIZE_4_DESC=	BLAS_SIZE=4
BLAS_SIZE_4_MAKE_ARGS=	BLAS_SIZE=4
BLAS_SIZE_8_BROKEN=	SEGVs on many examples, possibly due to the need to compile blas or openblas with the 8-byte-integers option
BLAS_SIZE_8_DESC=	BLAS_SIZE=8
BLAS_SIZE_8_MAKE_ARGS=	BLAS_SIZE=8

NOMPI_DESC=		MPI isn't used
NOMPI_BROKEN=		Fails to build without MPI

MPICH_MAKE_ENV=		USE_MPI=Y
MPICH_LIB_DEPENDS=	libmpich.so:net/mpich

OPENMPI_MAKE_ENV=	USE_MPI=Y PATH=${LOCALBASE}/mpi/openmpi/bin:$${PATH} # mpif90 in path determines which MPI library to use, see https://www.nwchem-sw.org/index-php/Compiling_NWChem.html#MPI_variables
OPENMPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_VARS=		CONFLICTS_BUILD=mpich

LIBXC_DESC=		Use libxc
LIBXC_USES=		cmake:indirect
LIBXC_MAKE_ENV=		USE_LIBXC=Y

PYTHON_DESC=		Enable Python syntax in input files
PYTHON_USES=		python
PYTHON_MAKE_ENV=	PYTHONVERSION=${PYTHON_VER} NWCHEM_MODULES="all python"

post-extract:
	@${RM} ${WRKSRC}/atomscf/src.orig
	# symlink the downloaded dftd3.tgz
	@${LN} -s ${DISTDIR}/${DIST_SUBDIR}/dftd3.tgz ${WRKSRC}/nwpw/nwpwlib/nwpwxc/

post-extract-LIBXC-on:
	# symlink the downloaded libxc
	@${LN} -s ${DISTDIR}/${DIST_SUBDIR}/libxc-${LIBXC_VERSION}.tar.gz ${WRKSRC}/libext/libxc/

post-patch:
	@${REINPLACE_CMD} 's|nwchrc="/etc/nwchemrc"|nwchrc="${PREFIX}/etc/nwchemrc"|' ${WRKSRC}/util/util_nwchemrc.F

pre-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} nwchem_config

#pre-build-BLAS_SIZE_4-on: # this is already done in the tarball, but not in the repository
#	@cd ${WRKSRC} && \
#		${SETENV} ${MAKE_ENV} ${MAKE_CMD} 64_to_32

do-install:
	${INSTALL_DATA} ${WRKDIR}/nwchemrc ${STAGEDIR}${PREFIX}/etc/nwchemrc
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/LINUX${ARCH_64BIT}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-test:
	@cd ${WRKSRC}/../QA && NWCHEM_TOP=${WRKSRC}/.. NWCHEM_TARGET=LINUX64 ./doqmtests.mpi

.include <bsd.port.mk>
