PORTNAME=	nwchem
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.2.20211105
DISTVERSIONSUFFIX=	-release
MASTER_SITES=	https://www.chemie.uni-bonn.de/pctc/mulliken-center/software/dft-d3/:dftd3 \
		https://web.archive.org/web/20210527062154if_/https://www.chemie.uni-bonn.de/pctc/mulliken-center/software/dft-d3/:dft3
DISTFILES=	dftd3.tgz:dft3
CATEGORIES=	science
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance computational chemistry software

LICENSE=	ECL20
LICENSE_NAME=	Educational Community License (ECL) 2.0
LICENSE_FILE=	${WRKSRC}/../LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=	fails to build: gfortran10: error: unrecognized command-line option '-m64'

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libga.so:devel/ga
RUN_DEPENDS=	nwchem-data>0:science/nwchem-data
TEST_DEPENDS=	bash:shells/bash

USES=		fortran gettext-runtime gmake perl5 shebangfix
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	nwchemgit
GH_TAGNAME=	e41592b

SHEBANG_FILES=	../contrib/distro-tools/build_* ../contrib/add_* config/64_to_32 \
		../QA/doqmtests.mpi ../QA/runtests.mpi.unix ../QA/round_esp.sh ../QA/sleep_loopqa.sh
SHEBANG_GLOB=	*.sh

MAKEFILE=	GNUmakefile
ARCH_64BIT=	${ARCH:C/.*64.*/64/:S/${ARCH}//}
MAKE_ENV=	NWCHEM_TOP=${WRKSRC}/.. NWCHEM_MODULES=all NWCHEM_LONG_PATHS=Y NWCHEM_TARGET=LINUX${ARCH_64BIT} USE_INTERNALBLAS=Y EXTERNAL_GA_PATH=${LOCALBASE} \
		BLAS_SIZE=4 USE_64TO32=y

SUB_FILES=	nwchemrc

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	gcc=${CC} gfortran=gfortran${GCC_DEFAULT}

PLIST_FILES=	bin/nwchem etc/nwchemrc

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON MPICH # the default should be the same as for the MPI option in math/scalapack and devel/ga
OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	NOMPI MPICH OPENMPI

NOMPI_DESC=		MPI isn't used
NOMPI_BROKEN=		Fails to build without MPI

MPICH_MAKE_ENV=		USE_MPI=Y
MPICH_LIB_DEPENDS=	libmpich.so:net/mpich

OPENMPI_MAKE_ENV=	USE_MPI=Y PATH=${LOCALBASE}/mpi/openmpi/bin:$${PATH} # mpif90 in path determines which MPI library to use, see https://www.nwchem-sw.org/index-php/Compiling_NWChem.html#MPI_variables
OPENMPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_VARS=		CONFLICTS_BUILD=mpich

PYTHON_DESC=		Enable Python syntax in input files
PYTHON_USES=		python
PYTHON_MAKE_ENV=	PYTHONVERSION=${PYTHON_VER} NWCHEM_MODULES="all python"

post-extract:
	@${RM} ${WRKSRC}/atomscf/src.orig
	# symlink the downloaded dftd3.tgz
	@${LN} -s ${DISTDIR}/${DIST_SUBDIR}/dftd3.tgz ${WRKSRC}/nwpw/nwpwlib/nwpwxc/

post-patch:
	@${REINPLACE_CMD} 's|nwchrc="/etc/nwchemrc"|nwchrc="${PREFIX}/etc/nwchemrc"|' ${WRKSRC}/util/util_nwchemrc.F

pre-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} nwchem_config && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} 64_to_32

do-install:
	${INSTALL_DATA} ${WRKDIR}/nwchemrc ${STAGEDIR}${PREFIX}/etc/nwchemrc
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/LINUX${ARCH_64BIT}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-test:
	@cd ${WRKSRC}/../QA && NWCHEM_TOP=${WRKSRC}/.. NWCHEM_TARGET=LINUX64 ./doqmtests.mpi

.include <bsd.port.mk>
