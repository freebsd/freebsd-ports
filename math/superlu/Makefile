# New ports collection makefile for:	SuperLU
# Date created:		31 Oct 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	superlu
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

.ifdef WITH_ATLAS
LIB_DEPENDS=    atlas:${PORTSDIR}/math/atlas
.else
LIB_DEPENDS= 	blas.1:${PORTSDIR}/math/blas
.endif

P_VERSION=	3.0
WRKSRC=		${WRKDIR}/SuperLU_${P_VERSION}
ALL_TARGET=	superlulib

.ifdef WITH_ATLAS
BLAS_LIBS=	-lf77blas -latlas
.else
BLAS_LIBS?=	-lblas
.endif

ARCH2FIX=	SRC/Makefile TESTING/MATGEN/Makefile CBLAS/Makefile make.inc	\
		MAKE_INC/make.alpha MAKE_INC/make.inc

post-patch:
	@${REINPLACE_CMD} -e 's+%%BLAS_LIBS%%+-L${LOCALBASE}/lib ${BLAS_LIBS}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%CFLAGS%%+${CFLAGS}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%FFLAGS%%+${FFLAGS}+' \
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
