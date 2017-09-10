# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	cdo
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/15187/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Climate Data Operators

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	CGRIBEX HDF5 JASPER NETCDF PROJ SZIP UDUNITS UUID
OPTIONS_DEFAULT=CGRIBEX HDF5 JASPER NETCDF PROJ SZIP UDUNITS UUID
OPTIONS_SUB=	yes
CGRIBEX_DESC=	Use CGRIBEX library for GRIB1 files
HDF5_IMPLIES=	SZIP
NETCDF_IMPLIES=	HDF5
UUID_DESC=	UUID support

PORTSCOUT=	site:https://code.zmaw.de/projects/cdo/files

CONFIGURE_ARGS=	--disable-data \
		--disable-extra \
		--disable-grib \
		--disable-ieg \
		--disable-openmp \
		--disable-service \
		--enable-cdi-lib \
		--program-transform-name="" \
		--with-zlib=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USES=		compiler:c++11-lib execinfo gmake libtool localbase pathfix

CGRIBEX_CONFIGURE_WITH=	cgribex
CGRIBEX_LIB_DEPENDS=	libcgribex.so:science/cgribex
HDF5_CONFIGURE_WITH=	hdf5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
JASPER_CONFIGURE_WITH=	jasper
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
NETCDF_CONFIGURE_WITH=	netcdf
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
PROJ_CONFIGURE_WITH=	proj
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj
SZIP_CONFIGURE_WITH=	szlib
SZIP_LIB_DEPENDS=	libsz.so:science/szip
UDUNITS_CONFIGURE_WITH=	udunits2
UDUNITS_LIB_DEPENDS=	libudunits2.so:science/udunits
UUID_CONFIGURE_OFF=	ac_cv_func_uuid_create=no ac_cv_have_decl_uuid_create=no ac_cv_have_decl_uuid_generate=no ac_cv_lib_uuid_uuid_generate=no
UUID_LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64"
CFLAGS+=	-DPTHREAD_MUTEXATTR_CONDATTR
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| contrib||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(libdir)/\($$$$pkgconfigfile\)|${PREFIX}/libdata/\1|' ${WRKSRC}/libcdi/src/Makefile.in
	@${REINPLACE_CMD} -e 's|unsigned32 |uint32_t |' ${WRKSRC}/libcdi/src/cdilib.c ${WRKSRC}/libcdi/src/util.c

test-NETCDF-on:
	@cd ${WRKSRC}/ && ${SETENV} CDO_PATH=src/cdo src/cdotest

.include <bsd.port.post.mk>
