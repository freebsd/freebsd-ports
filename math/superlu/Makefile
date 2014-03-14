# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	superlu
PORTREVISION=	6
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

USES=		fortran

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	goto2:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
.endif

USE_LDCONFIG=	yes

P_VERSION=	3.0
WRKSRC=		${WRKDIR}/SuperLU_${P_VERSION}
ALL_TARGET=	lib

ARCH2FIX=	SRC/Makefile TESTING/MATGEN/Makefile CBLAS/Makefile make.inc	\
		MAKE_INC/make.alpha MAKE_INC/make.inc

pre-build:
	@${REINPLACE_CMD} -e 's+%%BLAS%%+-L${LOCALBASE}/lib ${BLAS}+ ; \
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
	${INSTALL_DATA} ${WRKSRC}/libsuperlu_${P_VERSION}.so \
		${PREFIX}/lib/libsuperlu.so.${PORTREVISION}
	${LN} -fs ${PREFIX}/lib/libsuperlu.so.${PORTREVISION} \
		${PREFIX}/lib/libsuperlu_${P_VERSION}.so
	${LN} -fs ${PREFIX}/lib/libsuperlu_${P_VERSION}.so \
		${PREFIX}/lib/libsuperlu.so
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
	
.include <bsd.port.post.mk>
