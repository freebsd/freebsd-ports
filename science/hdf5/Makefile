# Created by: ijliao

PORTNAME=	hdf5
PORTVERSION=	1.10.9
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${PORTVERSION:R}/${DISTNAME}/src/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe libtool localbase tar:bzip2
CONFIGURE_ARGS=	--enable-hl \
		--enable-instrument \
		--enable-strict-format-checks \
		--with-default-api-version=v110
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	hdf

CPE_VENDOR=	hdfgroup

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
	@${REINPLACE_CMD} -e 's|hdf5_examples|examples/hdf5|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	@${REINPLACE_CMD} \
		-e '/LD_LIBRARY_PATH/ s|^|#|' \
		-e 's|(INSTALL)|(INSTALL_DATA)|' \
			`${FIND} ${WRKSRC} -regex '.*/examples/Makefile.in'`
	@${REINPLACE_CMD} -e 's|\[ -a|\[ -f|g' `${FIND} ${WRKSRC} -name \*.sh\*`

.include <bsd.port.mk>
