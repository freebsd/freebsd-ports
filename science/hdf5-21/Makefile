PORTNAME=	hdf5
PORTVERSION=	2.1.1
CATEGORIES=	science archivers graphics
PKGNAMESUFFIX=	-21

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA) 2.1
WWW=		https://www.hdfgroup.org/HDF5/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	FORTRAN SZIP
OPTIONS_DEFAULT=	FORTRAN

USES=		cmake:testing cpe localbase pkgconfig tar:bzip2
CPE_VENDOR=	hdfgroup
TEST_TARGET=	test
USE_LDCONFIG=	yes
PORTSUFF=	${PORTNAME}${PKGNAMESUFFIX}
CMAKE_ARGS=	-DHDF5_LIB_INFIX:STRING="-21"
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTSUFF}

USE_GITHUB=	yes
GH_ACCOUNT=	HDFGroup

SUFF2FIX=	c++/src/h5c++.in fortran/src/h5fc.in

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	HDF5_BUILD_FORTRAN
FORTRAN_PLIST_SUB=	FORTRAN=""
FORTRAN_PLIST_SUB_OFF=	FORTRAN="@comment "
FORTRAN__VARS=		FCFLAGS_f90="${FCFLAGS}" LIBS="-lstdc++"

SZIP_CMAKE_BOOL=	HDF5_ENABLE_SZIP_SUPPORT
SZIP_LIB_DEPENDS=	libsz.so:science/libaec

post-stage:
	cd ${STAGEDIR}${PREFIX}/bin && ( \
		for f in `${FIND} . -type f`; do \
			${MV} $$f $${f}-21; \
		done; \
	)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/hdf5-21
	${MV} ${STAGEDIR}${PREFIX}/include/*.h	\
		${STAGEDIR}${PREFIX}/include/hdf5-21/
	@${MKDIR} ${STAGEDIR}${DATADIR}-21 ${STAGEDIR}${PREFIX}/lib/cmake/hdf5-21
	${MV} ${STAGEDIR}${PREFIX}/cmake/* ${STAGEDIR}${PREFIX}/lib/cmake/hdf5-21

	${MV} ${STAGEDIR}${PREFIX}/lib/libhdf5.settings	\
		${STAGEDIR}${PREFIX}/lib/libhdf5-21.settings
	${RMDIR} ${STAGEDIR}${PREFIX}/cmake

post-stage-FORTRAN-on:
.for ext in mod
	${MV} ${STAGEDIR}${PREFIX}/include/*.${ext}	\
		${STAGEDIR}${PREFIX}/include/hdf5-21/
.endfor
	${MV} ${STAGEDIR}${PREFIX}/mod/* ${STAGEDIR}${PREFIX}/include/hdf5-21/
	${RMDIR} ${STAGEDIR}${PREFIX}/mod

.include <bsd.port.mk>
