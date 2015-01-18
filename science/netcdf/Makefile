# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf
PORTVERSION=	4.3.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for machine-independent, array-oriented data access

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5

CONFLICTS_INSTALL=	hdf-4.[0-9]* netcdf-3.[0-9]* netcdf3-3.[0-9]*
PORTSCOUT=	limit:^4\.

OPTIONS_DEFINE=	DAP DOCS DOXYGEN SZIP
OPTIONS_DEFAULT=DAP SZIP
DAP_DESC=	Build DAP client and remote testing
SZIP_DESC=	SZIP support (required if HDF5 was built with SZIP)

CFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include -fPIC -DPIC
CMAKE_ARGS=	-DHDF5_INCLUDE_DIRS=${LOCALBASE} -DUSE_HDF5=ON -DZLIB_INCLUDE_DIRS=/usr
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		cmake pathfix

PLIST_SUB=	PORTVERSION=${PORTVERSION}

DAP_CMAKE_OFF=		-DENABLE_DAP=OFF -DENABLE_DAP_REMOTE_TESTS=OFF
DAP_CMAKE_ON=		-DCURL_INCLUDE_DIRS=${LOCALBASE} -DENABLE_DAP=ON
DAP_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_CMAKE_OFF=	-DENABLE_DOXYGEN=OFF
DOXYGEN_CMAKE_ON=	-DENABLE_DOXYGEN=ON
SZIP_CMAKE_OFF=		-DUSE_SZIP=OFF
SZIP_CMAKE_ON=		-DSZIP_DIR=${LOCALBASE} -DSZIP_INCLUDE_DIRS=${LOCALBASE} -DUSE_SZIP=ON
SZIP_LDFLAGS=		-lsz
SZIP_LIB_DEPENDS=	libsz.so:${PORTSDIR}/science/szip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e '/man4/d; s|share/cmake|&/Modules|; s|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/libsrc/CMakeLists.txt ${WRKSRC}/ncdump/CMakeLists.txt ${WRKSRC}/ncgen/CMakeLists.txt ${WRKSRC}/ncgen3/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|mmap|_&|g' ${WRKSRC}/nc_test/tst_diskless.c ${WRKSRC}/nc_test/tst_diskless3.c

post-build:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
	@cd ${WRKSRC}/man4 && ${LOCALBASE}/bin/doxygen .
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/man4/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
