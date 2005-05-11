# New ports collection makefile for:    lapack++
# Date created:         5 May 2002
# Whom:                 NAKATA Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	lapack++
PORTVERSION=	2.2.0
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE} \
		http://math.nist.gov/lapack++/:doc
MASTER_SITE_SUBDIR=	lapackpp
DISTNAME=	lapackpp-${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} lapack++.ps.gz:doc lapackpp1_1.ps.gz:doc \
		lapackppman1_1.ps.gz:doc lapack++_install.ps.gz:doc
.endif
DIST_SUBDIR=	lapack++
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Linear Algebra PACKage in C++, a wrapper for LAPACK

.if !defined(WITH_BLAS)
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if defined(WITH_BLAS)
BLAS_LIB=	-L${LOCALBASE}/lib -lblas
LAPACK_LIB=	-L${LOCALBASE}/lib -llapack
.else
BLAS_LIB=	-L${LOCALBASE}/lib -lf77blas -latlas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas
.endif

#BLAS_LIB=	-L${LOCALBASE}/lib -lptf77blas -latlas_r ${PTHREAD_LIBS}
#LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack_r -lptcblas ${PTHREAD_LIBS}

#lapack++ forces to use atlas when detected, so we should disable here.
CONFIGURE_ARGS+=	--with-blas="${BLAS_LIB}" --with-lapack="${LAPACK_LIB}" --disable-atlas

do-install:
	@(cd ${WRKSRC} ; ${GMAKE} install)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++_install.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackpp1_1.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackppman1_1.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
