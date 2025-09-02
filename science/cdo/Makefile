PORTNAME=	cdo
PORTVERSION=	2.5.3
CATEGORIES=	science
MASTER_SITES=	https://code.mpimet.mpg.de/attachments/download/30034/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Climate Data Operators
WWW=		https://code.mpimet.mpg.de/projects/cdo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++20-lang gmake libtool localbase pathfix python:build

CONFIGURE_ARGS=	--disable-data \
		--disable-extra \
		--disable-fortran \
		--disable-ieg \
		--disable-openmp \
		--disable-service \
		--enable-cdi-lib \
		--program-transform-name="" \
		--with-zlib=/usr
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
TESTING_UNSAFE=	765 tests fail
USE_CXXSTD=	c++20
USE_LDCONFIG=	yes

PORTSCOUT=	site:https://code.mpimet.mpg.de/projects/cdo/files

OPTIONS_DEFINE=	CGRIBEX ECCODES HDF5 JASPER NETCDF PROJ SZIP UDUNITS UUID
OPTIONS_DEFAULT=CGRIBEX ECCODES HDF5 JASPER NETCDF PROJ SZIP UDUNITS UUID
OPTIONS_SUB=	yes
CGRIBEX_DESC=	Use CGRIBEX library for GRIB1 files
ECCODES_DESC=	Use ecCodes for GRIB files
HDF5_IMPLIES=	SZIP
NETCDF_IMPLIES=	HDF5
UUID_DESC=	UUID support

CGRIBEX_CONFIGURE_WITH=	cgribex
CGRIBEX_LIB_DEPENDS=	libcgribex.so:science/cgribex
ECCODES_CONFIGURE_WITH=	eccodes
ECCODES_LIB_DEPENDS=	libeccodes.so:science/eccodes
HDF5_CONFIGURE_WITH=	hdf5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
JASPER_CONFIGURE_WITH=	jasper
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
NETCDF_CONFIGURE_WITH=	netcdf
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
PROJ_CONFIGURE_WITH=	proj
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj
SZIP_CONFIGURE_WITH=	szlib
SZIP_LIB_DEPENDS=	libsz.so:science/libaec
UDUNITS_CONFIGURE_WITH=	udunits2
UDUNITS_LIB_DEPENDS=	libudunits2.so:science/udunits
UUID_CONFIGURE_OFF=	ac_cv_func_uuid_create=no ac_cv_have_decl_uuid_create=no ac_cv_have_decl_uuid_generate=no ac_cv_lib_uuid_uuid_generate=no
UUID_LIB_DEPENDS=	libuuid.so:misc/libuuid

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| contrib||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(libdir)/\($$$$pkgconfigfile\)|${PREFIX}/libdata/\1|' ${WRKSRC}/libcdi/src/Makefile.in
	@${REINPLACE_CMD} -e 's|unsigned32 |uint32_t |' ${WRKSRC}/libcdi/src/cdilib.c ${WRKSRC}/libcdi/src/util.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/libcdi/src/cdi.inc ${STAGEDIR}${PREFIX}/include/cdi.inc

test-NETCDF-on:
	@cd ${WRKSRC}/ && ${SETENVI} ${WRK_ENV} CDO_PATH=src/cdo src/cdotest

.include <bsd.port.mk>
