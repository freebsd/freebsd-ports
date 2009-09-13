# New ports collection makefile for:	SuperLU
# Date created:		31 Oct 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	superlu
PORTREVISION=	3
DISTVERSION=	${P_VERSION}.20060201
CATEGORIES=	math
MASTER_SITES=	http://crd.lbl.gov/~xiaoye/SuperLU/ \
		http://crd.lbl.gov/~xiaoye/:doc
DISTNAME=	${PORTNAME}_${P_VERSION}
.ifndef NOPORTDOCS
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} superlu_ug.pdf SLU_general.ps.gz:doc simax95.ps.gz:doc
.endif
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A library of routines for performing sparse factorization

USE_BLAS?=	reference

.if exists(${LOCALBASE}/lib/libgoto.so)
USE_BLAS=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
USE_BLAS=	atlas
.endif

. if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIBS=		-lblas
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto:${PORTSDIR}/math/gotoblas
BLAS_LIBS=		-lgotop
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS_LIBS=		-lptf77blas -lptcblas -latlas_r
.endif

USE_FORTRAN=	yes

P_VERSION=	3.0
WRKSRC=		${WRKDIR}/SuperLU_${P_VERSION}
ALL_TARGET=	lib

ARCH2FIX=	SRC/Makefile TESTING/MATGEN/Makefile CBLAS/Makefile make.inc	\
		MAKE_INC/make.alpha MAKE_INC/make.inc

pre-build:
	@${REINPLACE_CMD} -e 's+%%BLAS_LIBS%%+-L${LOCALBASE}/lib ${BLAS_LIBS}+ ; \
			s+%%CC%%+${CC}+; s+%%FC%%+${FC}+; \
			s+%%CFLAGS%%+${CFLAGS}+; \
			s+%%FFLAGS%%+${FFLAGS}+' \
	${WRKSRC}/make.inc
.for fmk in ${ARCH2FIX}
	@${REINPLACE_CMD} -e 's|^ARCH *.= ar|ARCMD = ar| ; \
		s|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${fmk}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu_${P_VERSION}.a \
		${PREFIX}/lib/libsuperlu.a
	@${MKDIR} ${PREFIX}/include/superlu
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${PREFIX}/include/superlu
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/SLU_general.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/simax95.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/superlu_ug.pdf ${DOCSDIR}
.endif

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} testing )
	@(cd ${WRKSRC}/TESTING && ${CAT} *.out )
	
.include <bsd.port.mk>
