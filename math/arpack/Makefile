# New ports collection makefile for:	arpack
# Date created:         31 Jan 2003
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	arpack
PORTVERSION=	96
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz patch.tar.gz
.ifndef NOPORTDOCS
DISTFILES+=	ug.ps.gz
.endif
DIST_SUBDIR=	arpack
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION}.tar.gz

PATCH_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Argand Library: large eigenvalue subroutines (serial version)

BUILD_DEPENDS=	${LOCALBASE}/bin/f2c:${PORTSDIR}/lang/f2c \
		${LOCALBASE}/lib/libf77blas.a:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/ARPACK
ALL_TARGET=	lib

BLAS_LIBS=	${LOCALBASE}/lib/libf77blas.a ${LOCALBASE}/lib/libatlas.a

INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

pre-patch:
	@(cd ${WRKSRC}; ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/patch.tar.gz)

pre-build:
	@${REINPLACE_CMD} -e 's+%FC%+${FC}+g ; s+%FFLAGS%+${FFLAGS}+g ; \
	s+%%WRKDIR%%+${WRKDIR}+ ; \
	s+%%BLAS_LIBS%%+${BLAS_LIBS}+' ${WRKSRC}/ARmake.inc

do-install:
	${INSTALL} ${WRKSRC}/libarpack.a ${PREFIX}/lib
	(${MKDIR} ${WRKSRC}/include ;\
	  cd ${WRKSRC}/include ;\
	  f2c -C++ -P  ${WRKSRC}/SRC/*.f ;\
	  f2c -C++ -P  ${WRKSRC}/BLAS/*.f ;\
	  f2c -C++ -P  ${WRKSRC}/LAPACK/*.f ;\
	  ${CAT} *.P | ${GREP} -v :ref: > arpack.h)
	${INSTALL_DATA} ${WRKSRC}/include/arpack.h ${PREFIX}/include

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	-${GZIP_CMD} ${GZIP} ${WRKSRC}/DOCUMENTS/ex-*.doc
	${CP} ${WRKSRC}/DOCUMENTS/ex-*.doc.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ug.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
