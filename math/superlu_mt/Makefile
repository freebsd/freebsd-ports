# New ports collection makefile for:	SuperLU_MT
# Date created:		31 Apr 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	superlu_mt
DISTVERSION=	1.0.20050524
CATEGORIES=	math
MASTER_SITES=	http://crd.lbl.gov/~xiaoye/SuperLU/ \
		http://crd.lbl.gov/~xiaoye/
DISTNAME=	${PORTNAME}_1.0
.ifndef NOPORTDOCS
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} simax97.ps.gz
.endif
DIST_SUBDIR=	superlu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Routines for performing multithreaded sparse factorization

BUILD_DEPENDS=	${LOCALBASE}/lib/libblas.a:${PORTSDIR}/math/blas

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/SuperLU_MT
ALL_TARGET=	superlulib

BLAS_LIBS=	${LOCALBASE}/lib/libblas.a

ARCH2FIX=	CBLAS/Makefile make.alpha make.exemplar TESTING/MATGEN/Makefile	\
		make.origin make.inc make.pthreads SRC/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's+%%BLAS_LIBS%%+${BLAS_LIBS}+ ; \
	  s+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+ ; \
	  s+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+ ' \
		${WRKSRC}/make.inc
.for fmk in ${ARCH2FIX}
	@${REINPLACE_CMD} -e 's|^ARCH *.= ar|ARCMD = ar| ; \
		s|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${fmk}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu_mt.* ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${PREFIX}/include/${PORTNAME}
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL/*.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*.ps
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/simax97.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
