# Created by: ijliao
# $FreeBSD$

PORTNAME=	hdf5
PORTVERSION=	1.8.15
DISTVERSIONSUFFIX=	-patch1
PORTREVISION=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF5/current/src/ \
		ftp://ftp.hdfgroup.org/HDF5/current/src/ \
		http://www.hdfgroup.org/ftp/HDF5/releases/${DISTNAME}/src/ \
		ftp://ftp.hdfgroup.org/HDF5/releases/${DISTNAME}/src/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LICENSE=	BSD4CLAUSE

CONFLICTS_INSTALL=	hdf-4.[0-9]* hdf5-1.6.[0-9]*

PORTSCOUT=	skipv:1.8.15-patch1

OPTIONS_DEFINE=	DEBUG EXAMPLES FORTRAN SZIP
OPTIONS_DEFAULT=SZIP
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--enable-cxx \
		--enable-hl \
		--enable-instrument \
		--enable-strict-format-checks
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		libtool tar:bzip2

PORTEXAMPLES=	*

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON=	does not compile

DEBUG_CONFIGURE_OFF=	--enable-production
DEBUG_CONFIGURE_ON=	--disable-production --enable-debug=all
FORTRAN_CONFIGURE_ENV=	F9X=${FC}
FORTRAN_CONFIGURE_OFF=	--disable-fortran --disable-fortran2003
FORTRAN_CONFIGURE_ON=	--enable-fortran --enable-fortran2003
FORTRAN_USES=		fortran
SZIP_CONFIGURE_ON=	--with-szlib=${LOCALBASE}
SZIP_LIB_DEPENDS=	libsz.so:${PORTSDIR}/science/szip

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	@${REINPLACE_CMD} \
		-e '/LD_LIBRARY_PATH/ s|^|#|' \
		-e 's|/share/hdf5_examples|/${EXAMPLESDIR_REL}|' \
		-e 's|(INSTALL)|(INSTALL_DATA)|' \
			`${FIND} ${WRKSRC} -regex '.*/examples/Makefile.in'`
	@${REINPLACE_CMD} -e 's|\[ -a|\[ -f|g' `${FIND} ${WRKSRC} -name \*.sh\*`

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
