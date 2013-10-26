# Created by: Tz-Huan Huang <tzhuan@gmail.com>
# $FreeBSD$

PORTNAME=	libtsnnls
PORTVERSION=	2.3.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.jasoncantarella.com/downloads/

MAINTAINER=	tzhuan@gmail.com
COMMENT=	Fast Sparse Nonnegative Least Squares Solver

GNU_CONFIGURE=	yes
USE_FORTRAN=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GOTOBLAS ATLAS
GOTOBLAS_DESC=	Use gotoblas (conflict with USE_ATLAS)
ATLAS_DESC=	Use atlas (conflict with USE_GOTOBLAS)
# DMALLOC "Use dmalloc" off

NO_STAGE=	yes
.include <bsd.port.options.mk>

WITH_BLAS=reference
.if ${PORT_OPTIONS:MGOTOBLAS}
WITH_BLAS=gotoblas
.elif ${PORT_OPTIONS:MATLAS}
WITH_BLAS=atlas
.endif

# FIXME compiling error when using dmalloc
#.if ${PORT_OPTIONS:MDMALLOC}
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
BLAS=-lptf77blas
LAPACK=-lalapack -lptcblas
.endif

CONFIGURE_ARGS=	--with-blas="${BLAS}" --with-lapack="${LAPACK}"

.include <bsd.port.mk>
