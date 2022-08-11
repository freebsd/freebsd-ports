PORTNAME=	hdf5
PORTVERSION=	1.10.9
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${PORTVERSION:R}/${DISTNAME}/src/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	-110

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA) 1.10.x

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe libtool localbase tar:bzip2

CONFIGURE_ARGS=	--enable-hl \
		--enable-instrument \
		--enable-strict-format-checks \
		--includedir=${PREFIX}/include/hdf5${PKGNAMESUFFIX} \
		--program-suffix=${PKGNAMESUFFIX} \
		--with-default-api-version=v110
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/hdf5${PKGNAMESUFFIX}

CONFLICTS_INSTALL=	hdf

CPE_VENDOR=	hdfgroup

PORTSCOUT=	limit:^1\.10\.

OPTIONS_DEFINE=	DEBUG EXAMPLES FORTRAN SZIP
OPTIONS_RADIO=	SUPPORT
OPTIONS_RADIO_SUPPORT=	CXX PARALLEL
OPTIONS_DEFAULT=CXX SZIP
OPTIONS_SUB=	yes
PARALLEL_DESC=	Parallel support

CXX_CONFIGURE_ENABLE=	cxx
DEBUG_CONFIGURE_OFF=	--enable-build-mode=production
DEBUG_CONFIGURE_ON=	--enable-build-mode=debug
FORTRAN_CONFIGURE_ENABLE=	fortran
FORTRAN_CONFIGURE_ENV=	F9X=${FC}
FORTRAN_USES=		fortran
PARALLEL_CONFIGURE_ENABLE=	parallel
PARALLEL_LDFLAGS=	-L${LOCALBASE}/lib -lmpi
PARALLEL_LIB_DEPENDS=	libmpi.so:net/mpich
SZIP_CONFIGURE_ON=	--with-szlib=${LOCALBASE}
SZIP_LIB_DEPENDS=	libsz.so:science/libaec

post-patch:
	@${REINPLACE_CMD} -e 's|hdf5_examples|examples/hdf5${PKGNAMESUFFIX}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	@${REINPLACE_CMD} \
		-e '/LD_LIBRARY_PATH/ s|^|#|' \
		-e 's|(INSTALL)|(INSTALL_DATA)|' \
			`${FIND} ${WRKSRC} -regex '.*/examples/Makefile.in'`
	@${REINPLACE_CMD} -e 's|\[ -a|\[ -f|g' `${FIND} ${WRKSRC} -name \*.sh\*`
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|libhdf5|libhdf5${PKGNAMESUFFIX}|g' \
			-e 's|libhdf5${PKGNAMESUFFIX}.settings|libhdf5.settings|g'
	@${REINPLACE_CMD} -e 's|libhdf5|libhdf5${PKGNAMESUFFIX}|g' ${WRKSRC}/test/testlibinfo.sh.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libhdf5.settings	${STAGEDIR}${PREFIX}/lib/libhdf5${PKGNAMESUFFIX}.settings

post-install-CXX-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/h5cc ${STAGEDIR}${PREFIX}/bin/h5cc${PKGNAMESUFFIX}

post-install-FORTRAN-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/h5fc ${STAGEDIR}${PREFIX}/bin/h5fc${PKGNAMESUFFIX}

.include <bsd.port.mk>
