# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hdf5
PORTVERSION=	1.8.18
PORTREVISION=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/current18/src/	\
		http://support.hdfgroup.org/ftp/HDF5/current18/src/	\
		ftp://ftp.hdfgroup.org/HDF5/current18/src/
PKGNAMESUFFIX=	-18

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA) 1.8

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DEBUG EXAMPLES FORTRAN SZIP

USES=		libtool:keepla tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx \
		--enable-instrument \
		--enable-strict-format-checks \
		--with-pthread=/usr \
		--with-zlib=/usr \
		--program-suffix=${PKGNAMESUFFIX} \
		--includedir=${PREFIX}/include/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
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

post-configure:
	${CP} -p ${WRKSRC}/src/libhdf5.settings.in	\
		${WRKSRC}/src/libhdf5${PKGNAMESUFFIX}.settings.in
	${CP} -p ${WRKSRC}/src/libhdf5.settings		\
		${WRKSRC}/src/libhdf5${PKGNAMESUFFIX}.settings

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
