# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hdf5
PORTVERSION=	1.8.21 # When PORTVERSION changes, please update french/med/files/patch-configure
PORTREVISION=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8/${PORTNAME}-${PORTVERSION}/src/	\
		http://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8/${PORTNAME}-${PORTVERSION}/src/	\
		ftp://ftp.hdfgroup.org/HDF5/releases/hdf5-1.8/${PORTNAME}-${PORTVERSION}/src/
PKGNAMESUFFIX=	-18

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA) 1.8

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DEBUG EXAMPLES FORTRAN SZIP

USES=		libtool:keepla localbase tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
PORTSUFF=	${PORTNAME}${PKGNAMESUFFIX}
CONFIGURE_ARGS=	--enable-cxx \
		--enable-instrument \
		--enable-strict-format-checks \
		--with-pthread=/usr \
		--with-zlib=/usr \
		--program-suffix=${PKGNAMESUFFIX} \
		--includedir=${PREFIX}/include/${PORTSUFF}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTSUFF}

SUFF2FIX=	tools/misc/h5cc.in tools/misc/h5redeploy.in	\
		c++/src/h5c++.in fortran/src/h5fc.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--disable-production --enable-debug=all
.endif

.if ${PORT_OPTIONS:MFORTRAN}
USES+=		fortran
CONFIGURE_ARGS+=--enable-fortran
CONFIGURE_ENV+=	F9X=${FC}
PLIST_SUB+=	FORTRAN=""
FCFLAGS_f90=	${FCFLAGS}
LIBS+=		-lstdc++
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if ${PORT_OPTIONS:MSZIP}
LIB_DEPENDS+=	libsz.so:science/szip
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	${REINPLACE_CMD} \
		-e '/LD_LIBRARY_PATH/ s|^|#|' \
		-e 's|/share/hdf5_examples|/${EXAMPLESDIR_REL}|' \
		-e 's|(INSTALL)|(INSTALL_DATA)|' \
			`${FIND} ${WRKSRC} -regex '.*/examples/Makefile.in'`
	${REINPLACE_CMD} -e 's|\[ -a|\[ -f|g' `${FIND} ${WRKSRC} -name \*.sh\*`
.if !${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/^install:/ s|install-examples||' ${WRKSRC}/Makefile.in
.endif
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|libhdf5|libhdf5${PKGNAMESUFFIX}|g'
	${REINPLACE_CMD} -e 's|libhdf5|libhdf5${PKGNAMESUFFIX}|g'	\
		${WRKSRC}/test/testlibinfo.sh.in
.for pf in ${SUFF2FIX}
	${REINPLACE_CMD} -e 's|%%SUFF%%|${PKGNAMESUFFIX}|g' ${WRKSRC}/${pf}
.endfor

post-configure:
	${CP} -p ${WRKSRC}/src/libhdf5.settings.in	\
		${WRKSRC}/src/libhdf5${PKGNAMESUFFIX}.settings.in
	${CP} -p ${WRKSRC}/src/libhdf5.settings		\
		${WRKSRC}/src/libhdf5${PKGNAMESUFFIX}.settings
post-stage:
.if ${PORT_OPTIONS:MFORTRAN}
	${MV} ${STAGEDIR}${PREFIX}/bin/h5fc ${STAGEDIR}${PREFIX}/bin/h5fc${PKGNAMESUFFIX}
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
