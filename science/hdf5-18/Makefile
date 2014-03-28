# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	hdf5
PORTVERSION=	1.8.10
PORTREVISION=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF5/current/src/ \
		ftp://ftp.hdfgroup.org/HDF5/current/src/ \
		http://www.hdfgroup.org/ftp/HDF5/releases/${DISTNAME}/src/ \
		ftp://ftp.hdfgroup.org/HDF5/releases/${DISTNAME}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-patch1
PKGNAMESUFFIX=	-18

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

OPTIONS_DEFINE=	DEBUG EXAMPLES FORTRAN SZIP

CONFLICTS_INSTALL=	hdf-4.[0-9]* hdf5-1.6.[0-9]*

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx \
		--enable-instrument \
		--enable-strict-format-checks \
		--with-pthread=/usr \
		--with-zlib=/usr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--disable-production --enable-debug=all
.endif

.if ${PORT_OPTIONS:MFORTRAN}
USES+=		fortran
CONFIGURE_ARGS+=--enable-fortran
CONFIGURE_ENV+=	F9X=${FC}
PLIST_SUB+=	FORTRAN=""
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if ${PORT_OPTIONS:MSZIP}
LIB_DEPENDS+=	libsz.so:${PORTSDIR}/science/szip
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
.endif

.include <bsd.port.pre.mk>

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
.if !${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e '/^install:/ s|install-examples||' ${WRKSRC}/Makefile.in
.endif

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
