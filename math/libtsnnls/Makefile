# New ports collection makefile for:   libtsnnls
# Date created:        18 October 2010
# Whom:                Tz-Huan Huang <tzhuan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libtsnnls
PORTVERSION=	2.3.3
CATEGORIES=	math
MASTER_SITES=	http://www.jasoncantarella.com/downloads/

MAINTAINER=	tzhuan@gmail.com
COMMENT=	Fast Sparse Nonnegative Least Squares Solver

GNU_CONFIGURE=	yes
USE_FORTRAN=	yes
USE_LDCONFIG=	yes

OPTIONS=	GOTOBLAS "Use gotoblas (conflict with USE_ATLAS)" off \
		ATLAS "Use atlas (conflict with USE_GOTOBLAS)" off
# DMALLOC "Use dmalloc" off

.include <bsd.port.options.mk>

WITH_BLAS?=reference
.if defined(WITH_GOTOBLAS)
WITH_BLAS=gotoblas
.endif
.if defined(WITH_ATLAS)
WITH_BLAS=atlas
.endif

# FIXME compiling error when using dmalloc
#.if defined(WITH_DMALLOC)
#CONFIGURE_ARGS+=--with-dmalloc
#LIB_DEPENDS+=dmalloc.1:${PORTSDIR}/devel/dmalloc
#.endif

.if ${WITH_BLAS} == reference
LIB_DEPENDS+=blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=lapack.4:${PORTSDIR}/math/lapack
BLAS=-lblas
LAPACK=-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=goto2:${PORTSDIR}/math/gotoblas
BLAS=-lgoto2p
LAPACK=-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=atlas:${PORTSDIR}/math/atlas
BLAS=-lptf77blas -lptcblas -latlas_r
LAPACK=-lalapack_r
.endif

CONFIGURE_ARGS=	--with-blas="${BLAS}" --with-lapack="${LAPACK}"

.include <bsd.port.mk>
