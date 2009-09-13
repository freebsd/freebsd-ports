# New ports collection makefile for:	arpack
# Date created:         31 Jan 2003
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	arpack
PORTVERSION=	96
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz patch.tar.gz
.ifndef NOPORTDOCS
DISTFILES+=	ug.ps.gz
.endif
DIST_SUBDIR=	arpack
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION}.tar.gz

PATCH_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/

MAINTAINER=	stephen@missouri.edu
COMMENT=	Argand Library: large eigenvalue subroutines (serial version)

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=		yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=		atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS?=		"-L${LOCALBASE}/lib -lf77blas -latlas"
.else
LIB_DEPENDS+=		blas.2:${PORTSDIR}/math/blas
BLAS_LIBS?=		"-L${LOCALBASE}/lib -lblas"
.endif

ALL_TARGET=	lib
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=       -fPIC
.else
PICFLAG?=       -fpic
.endif

USE_FORTRAN=	yes

WRKSRC=		${WRKDIR}/ARPACK
WRKSRC_SHARED=	${WRKDIR}/ARPACK_SHARED
FFLAGS_SHARED=	${FFLAGS} ${PICFLAG}
USE_LDCONFIG=	yes

pre-patch:
	@(cd ${WRKSRC}; ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/patch.tar.gz)

pre-build:
	${CP} -R ${WRKSRC} ${WRKSRC_SHARED}
	@${REINPLACE_CMD} -e 's+%FC%+${FC}+g ; s+%FFLAGS%+${FFLAGS}+g ; \
	s+%%WRKSRC%%+${WRKSRC}+ ; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+' ${WRKSRC}/ARmake.inc
	@${REINPLACE_CMD} -e 's+%FC%+${FC}+g ; s+%FFLAGS%+${FFLAGS_SHARED}+g ; \
	s+%%WRKSRC%%+${WRKSRC_SHARED}+ ; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+' ${WRKSRC_SHARED}/ARmake.inc

do-build:
	cd ${WRKSRC} ; ${MAKE} ${ALL_TARGET}
	cd ${WRKSRC_SHARED} ; ${MAKE} ${ALL_TARGET} ; ld -Bshareable -o libarpack.so.1 -x -soname libarpack.so.1 --whole-archive libarpack.a

do-install:
	@${INSTALL_DATA} ${WRKSRC}/libarpack.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC_SHARED}/libarpack.so.1 ${PREFIX}/lib
	@${LN} -sf libarpack.so.1 ${PREFIX}/lib/libarpack.so

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${FILESDIR}/arpack.h ${PREFIX}/include
	${MKDIR} ${DOCSDIR}
	-${GZIP_CMD} ${GZIP} ${WRKSRC}/DOCUMENTS/ex-*.doc
	${CP} ${WRKSRC}/DOCUMENTS/ex-*.doc.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ug.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
