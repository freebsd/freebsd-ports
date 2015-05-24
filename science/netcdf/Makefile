# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	netcdf
PORTVERSION=	4.3.3.1
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

CONFIGURE_ARGS=	--enable-netcdf-4
CPPFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include -fPIC -DPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LIBS+=		-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		libtool pathfix

DAP_CONFIGURE_OFF=	--disable-dap
DAP_CONFIGURE_ON=	--enable-dap
DAP_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
DOXYGEN_BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
DOXYGEN_CONFIGURE_OFF=	--disable-doxygen
DOXYGEN_CONFIGURE_ON=	--enable-doxygen
SZIP_LIB_DEPENDS=	libsz.so:${PORTSDIR}/science/szip
SZIP_LIBS=		-lsz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl ||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|mmap|_&|g' ${WRKSRC}/nc_test/tst_diskless.c ${WRKSRC}/nc_test/tst_diskless3.c

post-build:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
	cd ${WRKSRC}/docs/ && ${LOCALBASE}/bin/doxygen .
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS} && ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
