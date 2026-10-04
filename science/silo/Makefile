PORTNAME=	silo
DISTVERSION=	4.12.1
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mesh and field I/O library and scientific database
WWW=		https://software.llnl.gov/Silo/ \
		https://github.com/LLNL/Silo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake:testing perl5 readline
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Silo

CMAKE_ON=			SILO_ENABLE_INSTALL_LITE_HEADERS
CMAKE_TESTING_ON=		BUILD_TESTING
# upstream tests share filenames in a common test directory, so they are
# not safe to run with ctest's default parallelism
CMAKE_TESTING_JOBS=		1

FFLAGS+=			-fallow-argument-mismatch # needed only for tests

# tests invoke "python3" via $PATH; provide it since only python3.12 is installed
TEST_ENV=		${MAKE_ENV} PATH=${WRKDIR}/bin:${PATH}

CONFLICTS_INSTALL=		deforaos-browser # bin/browser

OPTIONS_DEFINE=			BROWSER FORTRAN HDF5 PYTHON SILOCK
OPTIONS_DEFAULT=		BROWSER FORTRAN HDF5 PYTHON SILOCK
OPTIONS_SUB=			yes

BROWSER_DESC=			Enable building of browser
BROWSER_CMAKE_BOOL=		SILO_ENABLE_BROWSER

FORTRAN_CMAKE_BOOL=		SILO_ENABLE_FORTRAN
FORTRAN_USES=			fortran

HDF5_CMAKE_BOOL=		SILO_ENABLE_HDF5
HDF5_CFLAGS=			-DH5_USE_110_API=1
HDF5_LIB_DEPENDS=		libhdf5.so:science/hdf5
HDF5_PLIST_SUB=			SUFX_HDF5="h5"
HDF5_PLIST_SUB_OFF=		SUFX_HDF5=""

PYTHON_CMAKE_BOOL=		SILO_ENABLE_PYTHON_MODULE
PYTHON_USES=			python

SILOCK_DESC=			Enable building of silock
SILOCK_CMAKE_BOOL=		SILO_ENABLE_SILOCK

pre-test-PYTHON-on: # tests don't work w/out the PYTHON option; BINARY_ALIAS can't be easily used because this is option-conditional
	@${MKDIR} ${WRKDIR}/bin
	@${LN} -sf ${PYTHON_CMD} ${WRKDIR}/bin/python3

# tests as of 4.12.1: 100% tests passed, 0 tests failed out of 180

.include <bsd.port.mk>
