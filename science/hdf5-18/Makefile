# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hdf5
PORTVERSION=	1.8.9
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF5/current/src/ \
		ftp://ftp.hdfgroup.org/HDF5/current/src/ \
		http://www.hdfgroup.org/ftp/HDF5/releases/${PORTNAME}-${PORTVERSION}/src/ \
		ftp://ftp.hdfgroup.org/HDF5/releases/${PORTNAME}-${PORTVERSION}/src/
#DISTNAME=	${PORTNAME}-${PORTVERSION}-patch1

MAINTAINER=	koziol@hdfgroup.org
COMMENT=	Hierarchical Data Format library (from NCSA)

CONFLICTS=	hdf-4.* hdf5-1.6.*
NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx \
		--enable-instrument \
		--enable-strict-format-checks \
		--with-pthread=/usr \
		--with-zlib=/usr

OPTIONS_DEFINE=	DEBUG FORTRAN SZIP EXAMPLES
FORTRAN_DESC=	Fortran support
SZIP_DESC=	SZIP support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug=all --disable-production
.endif

.if ${PORT_OPTIONS:MFORTRAN}
USE_FORTRAN=	yes
CONFIGURE_ENV+=	F9X=${FC}
CONFIGURE_ARGS+=--enable-fortran
PLIST_SUB+=	FORTRAN=""
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if ${PORT_OPTIONS:MSZIP}
LIB_DEPENDS+=	sz:${PORTSDIR}/science/szip
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	@${REINPLACE_CMD} \
		-e '/LD_LIBRARY_PATH/ s|^|#|' \
		-e 's|/share/hdf5_examples|/${EXAMPLESDIR_REL}|' \
		-e 's|(INSTALL)|(INSTALL_DATA)|' \
			`${FIND} ${WRKSRC} -regex '.*/examples/Makefile.in'`
	@${REINPLACE_CMD} -e 's|\[ -a|\[ -f|g' `${FIND} ${WRKSRC} -name \*.sh\*`
.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e '/^install:/ s|install-examples||' ${WRKSRC}/Makefile.in
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
