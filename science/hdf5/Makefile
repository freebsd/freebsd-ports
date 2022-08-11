PORTNAME=	hdf5
PORTVERSION=	1.12.2
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${PORTVERSION:R}/hdf5-${PORTVERSION}/src/
DISTNAME=	CMake-hdf5-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA) (latest)

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c11 localbase perl5
USE_PERL5=	build

CFLAGS+=	-D__LONG_LONG_SUPPORTED
CMAKE_ARGS=	-DDEFAULT_API_VERSION=v112 \
		-DHDF5_INSTALL_CMAKE_DIR=lib/cmake/hdf5 \
		-DHDF5_INSTALL_INCLUDE_DIR=${PREFIX}/include
CMAKE_ON=	HDF5_BUILD_HL_LIB HDF5_BUILD_TOOLS HDF5_ENABLE_INSTRUMENT HDF5_ENABLE_Z_LIB_SUPPORT HDF5_STRICT_FORMAT_CHECKS
TEST_TARGET=	test
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC_SUBDIR=	hdf5-${PORTVERSION}

CONFLICTS_INSTALL=	hdf

CPE_VENDOR=	hdfgroup

OPTIONS_DEFINE=	DEBUG EXAMPLES FORTRAN SZIP
OPTIONS_RADIO=	SUPPORT
OPTIONS_RADIO_SUPPORT=	CXX PARALLEL
OPTIONS_DEFAULT=CXX SZIP
OPTIONS_SUB=	yes
PARALLEL_DESC=	Parallel support
PARALLEL_IMPLIES=	FORTRAN

CXX_CMAKE_BOOL=		HDF5_BUILD_CPP_LIB
EXAMPLES_CMAKE_BOOL=	HDF5_BUILD_EXAMPLES HDF5_TEST_EXAMPLES HDF5_PACK_EXAMPLES
FORTRAN_CMAKE_BOOL=	HDF5_BUILD_FORTRAN
FORTRAN_CONFIGURE_ENV=	F9X=${FC}
FORTRAN_USES=		fortran
PARALLEL_CMAKE_BOOL=	HDF5_ENABLE_PARALLEL
PARALLEL_USES=		localbase:ldflags mpi:mpich
PARALLEL_VARS=		FCFLAGS+=-I${LOCALBASE}/include
SZIP_CMAKE_BOOL=	HDF5_ENABLE_SZIP_SUPPORT
SZIP_LIB_DEPENDS=	libsz.so:science/libaec

post-patch-EXAMPLES-on:
	@${MKDIR} ${WRKDIR}/.build
	@${TAR} -C ${WRKDIR}/.build -xf ${WRKSRC}/../HDF5Examples-1.12.9-Source.tar.gz

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${PREFIX}/share/COPYING
	${RM} ${STAGEDIR}${DATADIR}/COPYING
	cd ${STAGEDIR}${PREFIX}/share && ${MV} RELEASE.txt USING_HDF5_CMake.txt ${STAGEDIR}${DATADIR}/
	${LN} -fs hdf5.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/hdf5-${PORTVERSION}.pc
	${LN} -fs hdf5_hl.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/hdf5_hl-${PORTVERSION}.pc

post-install-CXX-on:
	${LN} -fs hdf5_cpp.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/hdf5_cpp-${PORTVERSION}.pc
	${LN} -fs hdf5_hl_cpp.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/hdf5_hl_cpp-${PORTVERSION}.pc

post-install-EXAMPLES-on:
	cd ${STAGEDIR}${PREFIX}/share && ${MV} CTestScript.cmake HDF5_Examples.cmake HDF5_Examples_options.cmake USING_CMake_Examples.txt ${STAGEDIR}${DATADIR}/
	${MV} ${STAGEDIR}${PREFIX}/share/HDF5Examples ${STAGEDIR}${EXAMPLESDIR}

post-install-FORTRAN-on:
	${LN} -fs hdf5_fortran.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/hdf5_fortran-${PORTVERSION}.pc
	${LN} -fs hdf5_hl_fortran.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/hdf5_hl_fortran-${PORTVERSION}.pc

.include <bsd.port.mk>
