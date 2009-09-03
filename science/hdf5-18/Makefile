# New ports collection makefile for:	hdf5-18
# Date created:			Nov 20, 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.8.3
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF5/current/src/ \
		ftp://ftp.hdfgroup.org/HDF5/prev-releases/hdf5-1.8.2/src/

MAINTAINER=	koziol@hdfgroup.org
COMMENT=	Hierarchical Data Format library (from NCSA)

CONFLICTS=	hdf5-1.6.*
NO_LATEST_LINK=	yes

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug \
		--enable-cxx \
		--enable-instrument \
		--enable-production \
		--enable-strict-format-checks \
		--with-pthread=/usr \
		--with-ssl=/usr \
		--with-zlib=/usr

.include <bsd.port.pre.mk>

.if defined(WITH_FORTRAN)
USE_FORTRAN=		yes
CONFIGURE_ENV+=		F9X=${FC}
CONFIGURE_ARGS+=	--enable-fortran
PLIST_SUB+=		FORTRAN=""
.else
PLIST_SUB+=		FORTRAN="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.for i in gif2h5 h52gif h5debug h5diff h5dump h5import h5jam h5ls h5repack h5repart h5unjam
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
