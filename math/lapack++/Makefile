# New ports collection makefile for:    lapack++
# Date created:         5 May 2002
# Whom:                 NAKATA Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	lapack++
PORTVERSION=	1.1
CATEGORIES=	math
MASTER_SITES=	http://math.nist.gov/lapack++/
DISTNAME=	Lapackpp1_1a
EXTRACT_SUFX=	.tgz
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} lapack++.ps.gz lapackpp1_1.ps.gz \
		lapackppman1_1.ps.gz lapack++_install.ps.gz
.endif
DIST_SUBDIR=	lapack++
EXTRACT_ONLY=	Lapackpp1_1a.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Linear Algebra PACKage in C++, a wrapper for LAPACK

LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/Lapackpp1.1a
USE_REINPLACE=	yes

#ATLAS_BLAS
BLAS_LIB=	-lf77blas -latlas
LAPACK_LIB=	-lalapack -lcblas

#Vanilla BLAS
#BLAS_LIB=	-lblas
#LAPACK_LIB=	-llapack

#SMP version (KSE required)
#BLAS_LIB=	-lptf77blas -latlas_r ${PTHREAD_LIBS}
#LAPACK_LIB=	-lalapack_r -lptcblas ${PTHREAD_LIBS}

post-patch:
	@(cd ${WRKSRC} ; ${MV} makefile Makefile)
	@${REINPLACE_CMD} -e 's+%%BLAS_LIB%%+${BLAS_LIB}+g;' \
			-e 's+%%LAPACK_LIB%%+${LAPACK_LIB}+g;' \
		${WRKSRC}/makefile.def

do-install:
.for i in libblas++ liblamatrix++ liblapack++
	${INSTALL_DATA} ${WRKSRC}/${i}.a ${PREFIX}/lib
.endfor
	@${MKDIR} ${PREFIX}/include/lapack++
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/lapack++
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++_install.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackpp1_1.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackppman1_1.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
