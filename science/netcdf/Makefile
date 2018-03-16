# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf
PORTVERSION=	4.6.1
CATEGORIES=	science
MASTER_SITES=	https://www.unidata.ucar.edu/downloads/netcdf/ftp/ \
		ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for machine-independent, array-oriented data access

LICENSE=	UCAR_UNIDATA
LICENSE_NAME=	University Corporation for Atmospheric Research/Unidata
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libhdf5.so:science/hdf5

CONFLICTS_INSTALL=	hdf-4.[0-9]* netcdf-3.[0-9]* netcdf3-3.[0-9]*

OPTIONS_DEFINE=	DAP DOCS DOXYGEN SZIP
OPTIONS_DEFAULT=DAP SZIP
DAP_DESC=	Build DAP client and remote testing
SZIP_DESC=	SZIP support (required if HDF5 was built with SZIP)

CONFIGURE_ARGS=	--disable-filter-testing --enable-netcdf-4
CPPFLAGS+=	-fPIC -DPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		libtool localbase ncurses pathfix pkgconfig:run

DAP_CONFIGURE_ENABLE=	dap
DAP_LIB_DEPENDS=	libcurl.so:ftp/curl
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_PORTDOCS=	*
SZIP_LIB_DEPENDS=	libsz.so:science/szip
SZIP_LIBS=		-lsz

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl ||g' ${WRKSRC}/configure

post-build-DOXYGEN-on:
	cd ${WRKSRC}/docs/ && ${LOCALBASE}/bin/doxygen .

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
