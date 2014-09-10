# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	superlu
PORTVERSION=	${P_VERSION}
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://crd.lbl.gov/~xiaoye/SuperLU/ \
		http://crd.lbl.gov/~xiaoye/:doc
DISTNAME=	${PORTNAME}_${P_VERSION}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of routines for performing sparse factorization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/README

USES=		fortran

USE_LDCONFIG=	yes

P_VERSION=	4.3
P_VER=		${P_VERSION:R}
WRKSRC=		${WRKDIR}/SuperLU_${P_VERSION}
ALL_TARGET=	lib
PLIST_SUB=	P_VERSION=${P_VERSION} P_VER=${P_VER}

ARCH2FIX=	SRC/Makefile TESTING/MATGEN/Makefile CBLAS/Makefile make.inc	\
		MAKE_INC/make.alpha MAKE_INC/make.inc

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} superlu_ug.pdf SLU_general.ps.gz:doc simax95.ps.gz:doc
.endif

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
BLAS=		-lblas
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2.so:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
.endif

pre-build:
	${REINPLACE_CMD} -e 's+%%BLAS%%+-L${LOCALBASE}/lib ${BLAS}+ ; \
			s+%%CC%%+${CC}+; s+%%FC%%+${FC}+; \
			s+%%WRKSRC%%+${WRKSRC}+; \
			s+%%CFLAGS%%+${CFLAGS}+; \
			s+%%FFLAGS%%+${FFLAGS}+' \
	${WRKSRC}/make.inc
.for fmk in ${ARCH2FIX}
	${REINPLACE_CMD} -e 's|^ARCH *.= ar|ARCMD = ar| ; \
		s|\$$(ARCH)|$$(ARCMD)|' ${WRKSRC}/${fmk}
.endfor
	${FIND} ${WRKSRC} -name Makefile | ${XARGS}	\
		${REINPLACE_CMD} -E -e 's|\( cd (.*); \$$\(MAKE\) \)|\$$(MAKE) -C \1|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libsuperlu_${P_VERSION}.a \
		${STAGEDIR}${PREFIX}/lib/libsuperlu.a
	${INSTALL_DATA} ${WRKSRC}/libsuperlu_${P_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libsuperlu.so.${P_VER}
	${LN} -fs libsuperlu.so.${PORTREVISION} \
		${STAGEDIR}${PREFIX}/lib/libsuperlu_${P_VERSION}.so
	${LN} -fs libsuperlu_${P_VERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libsuperlu.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/superlu
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${STAGEDIR}${PREFIX}/include/superlu
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/SLU_general.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/simax95.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/superlu_ug.pdf ${STAGEDIR}${DOCSDIR}
.endif

regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} testing )
	(cd ${WRKSRC}/TESTING && ${CAT} *.out )

.include <bsd.port.post.mk>
