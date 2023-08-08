PORTNAME=	netcdf
PORTVERSION=	4.9.2
DISTVERSIONPREFIX=	c-
CATEGORIES=	science
MASTER_SITES=	https://downloads.unidata.ucar.edu/netcdf-c/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for machine-independent, array-oriented data access
WWW=		https://www.unidata.ucar.edu/software/netcdf/ \
		https://github.com/Unidata/netcdf-c

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhdf5.so:science/hdf5 \
		libzstd.so:archivers/zstd

USES=		gmake libtool localbase ncurses pathfix pkgconfig:run

CONFIGURE_ARGS=	--disable-filter-testing --disable-libxml2 \
		--enable-byterange --enable-dap --enable-netcdf-4
CPPFLAGS+=	-fPIC -DPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LIBS+=		-lexecinfo
TEST_TARGET=	check
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	hdf-4.[0-9]* netcdf-3.[0-9]* netcdf3-3.[0-9]*

OPTIONS_DEFINE=	DOCS DOXYGEN SZIP
OPTIONS_DEFAULT=SZIP
OPTIONS_SUB=	yes
DOXYGEN_IMPLIES=DOCS
SZIP_DESC=	SZIP support (required if HDF5 was built with SZIP)

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen
SZIP_LIB_DEPENDS=	libsz.so:science/libaec
SZIP_LIBS=		-lsz

post-build-DOXYGEN-on:
	cd ${WRKSRC}/docs/ && ${LOCALBASE}/bin/doxygen .

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
