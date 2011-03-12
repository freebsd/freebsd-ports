# New ports collection makefile for:	hdf5-18
# Date created:			Nov 20, 2008
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.8.6
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF5/prev-releases/hdf5-${PORTVERSION}/src/
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

OPTIONS=	DEBUG	"Debug"			off \
		FORTRAN	"Fortran support"	off \
		SZIP	"SZIP support"		off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=all --disable-production
.endif

.if defined(WITH_FORTRAN)
USE_FORTRAN=	yes
CONFIGURE_ENV+=	F9X=${FC}
CONFIGURE_ARGS+=--enable-fortran
PLIST_SUB+=	FORTRAN=""
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if defined(WITH_SZIP)
LIB_DEPENDS+=	sz.2:${PORTSDIR}/science/szip
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
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e '/^install:/ s|install-examples||' ${WRKSRC}/Makefile.in
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
