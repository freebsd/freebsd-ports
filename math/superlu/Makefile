# New ports collection makefile for:	SuperLU
# Date created:		31 Oct 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	superlu
PORTVERSION=	3.0.20040410
CATEGORIES=	math
MASTER_SITES=	http://crd.lbl.gov/~xiaoye/SuperLU/ \
		http://crd.lbl.gov/~xiaoye/
DISTNAME=	${PORTNAME}_3.0
.ifndef NOPORTDOCS
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} superlu_ug.ps.gz SLU_general.ps.gz simax95.ps.gz
.endif
DIST_SUBDIR=	superlu
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A library of routines for performing sparse factorization

BUILD_DEPENDS=	${LOCALBASE}/lib/libf77blas.a:${PORTSDIR}/math/atlas

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/SuperLU_3.0
ALL_TARGET=	superlulib

BLAS_LIBS=	${LOCALBASE}/lib/libf77blas.a ${LOCALBASE}/lib/libatlas.a

post-patch:
	@${REINPLACE_CMD} -e 's+%%BLAS_LIBS%%+${BLAS_LIBS}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%CFLAGS%%+${CFLAGS}+' \
	${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's+%%FFLAGS%%+${FFLAGS}+' \
	${WRKSRC}/make.inc

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu.* ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/superlu
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${PREFIX}/include/superlu
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/SLU_general.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/simax95.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/superlu_ug.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
