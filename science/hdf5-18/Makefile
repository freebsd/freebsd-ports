PORTNAME=	hdf5
PORTVERSION=	1.8.23
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8/${PORTNAME}-${PORTVERSION}/src/	\
		http://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8/${PORTNAME}-${PORTVERSION}/src/	\
		ftp://ftp.hdfgroup.org/HDF5/releases/hdf5-1.8/${PORTNAME}-${PORTVERSION}/src/
PKGNAMESUFFIX=	-18

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA) 1.8
WWW=		https://www.hdfgroup.org/HDF5/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	EXAMPLES FORTRAN SZIP

USES=		cmake:testing cpe localbase pkgconfig tar:bzip2
CPE_VENDOR=	hdfgroup
USE_LDCONFIG=	yes
PORTSUFF=	${PORTNAME}${PKGNAMESUFFIX}
CMAKE_ARGS=	-DHDF5_LIB_INFIX:STRING="-18"
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTSUFF}

SHRFILES=	COPYING RELEASE.txt USING_HDF5_CMake.txt

SUFF2FIX=	c++/src/h5c++.in fortran/src/h5fc.in

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	HDF5_BUILD_FORTRAN
FORTRAN_PLIST_SUB=	FORTRAN=""
FORTRAN_PLIST_SUB_OFF=	FORTRAN="@comment "
FORTRAN__VARS=		FCFLAGS_f90="${FCFLAGS}" LIBS="-lstdc++"

SZIP_CMAKE_BOOL=	HDF5_ENABLE_SZIP_SUPPORT
SZIP_LIB_DEPENDS=	libsz.so:science/libaec

EXAMPLES_CMAKE_BOOL=	HDF5_BUILD_EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	${REINPLACE_CMD} \
		-e '/LD_LIBRARY_PATH/ s|^|#|' \
		-e 's|/share/hdf5_examples|/${EXAMPLESDIR_REL}|' \
		-e 's|(INSTALL)|(INSTALL_DATA)|' \
			`${FIND} ${WRKSRC} -regex '.*/examples/Makefile.in'`
	${REINPLACE_CMD} -e 's|\[ -a|\[ -f|g' `${FIND} ${WRKSRC} -name \*.sh\*`
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|libhdf5|libhdf5${PKGNAMESUFFIX}|g'
	${REINPLACE_CMD} -e 's|libhdf5|libhdf5${PKGNAMESUFFIX}|g'	\
		${WRKSRC}/test/testlibinfo.sh.in
.for pf in ${SUFF2FIX}
	${REINPLACE_CMD} -e 's|%%SUFF%%|${PKGNAMESUFFIX}|g' ${WRKSRC}/${pf}
.endfor
	${CP} ${WRKSRC}/src/libhdf5.settings.in	\
		${WRKSRC}/src/libhdf5-18.settings.in

post-stage:
	cd ${STAGEDIR}${PREFIX}/bin && ( \
		for f in `${FIND} . -type f`; do \
			${MV} $$f $${f}-18; \
		done; \
	)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/hdf5-18
	${MV} ${STAGEDIR}${PREFIX}/include/*.h	\
		${STAGEDIR}${PREFIX}/include/hdf5-18/
	@${MKDIR} ${STAGEDIR}${DATADIR}-18 ${STAGEDIR}${PREFIX}/lib/cmake/hdf5-18
	${MV} ${STAGEDIR}${PREFIX}/cmake/* ${STAGEDIR}${PREFIX}/lib/cmake/hdf5-18
.for f in ${SHRFILES}
	${MV} ${STAGEDIR}${PREFIX}/share/${f} ${STAGEDIR}${DATADIR}-18
.endfor
	${MV} ${STAGEDIR}${PREFIX}/lib/libhdf5.settings	\
		${STAGEDIR}${PREFIX}/lib/libhdf5-18.settings
	${RMDIR} ${STAGEDIR}${PREFIX}/cmake

post-stage-FORTRAN-on:
.for ext in mod f90
	${MV} ${STAGEDIR}${PREFIX}/include/*.${ext}	\
		${STAGEDIR}${PREFIX}/include/hdf5-18/
.endfor
	${MV} ${STAGEDIR}${PREFIX}/mod/* ${STAGEDIR}${PREFIX}/include/hdf5-18/
	${RMDIR} ${STAGEDIR}${PREFIX}/mod

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
