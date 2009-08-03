# New ports collection makefile for:    sdpa
# Date created:                         October 4 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdpa
PORTVERSION=	7.3.1
CATEGORIES=	math
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTNAME=	${PORTNAME}.${PORTVERSION}.src-${SRCDATE}
DIST_SUBDIR=	sdpa

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SDPA(SemiDefinite Programming Algorithm) Very efficent SDP Solver

.include <bsd.port.pre.mk>

SRCDATE=	20090729
MANUALFILE=	sdpa7-manual.pdf
USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}.src
USE_BLAS?=	reference

.if exists(${LOCALBASE}/lib/libgoto.so)
USE_BLAS=     gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
USE_BLAS=     atlas
.endif

. if ${USE_BLAS} == reference
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${USE_BLAS} == gotoblas
LIB_DEPENDS+=	goto:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lgotop
LAPACK=		-lgotop -llapack
.elif ${USE_BLAS} == atlas
LIB_DEPENDS+=   atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas -lptcblas -latlas_r
LAPACK=		-lalapack_r
.endif

CONFIGURE_ARGS+=--with-blas="-L${LOCALBASE}/lib ${BLAS}" --with-lapack="-L${LOCALBASE}/lib ${LAPACK}"

PLIST_SUB+=	MANUALFILE=${MANUALFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpa ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${MANUALFILE} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
