# Created by: Tz-Huan Huang <tzhuan@gmail.com>
# $FreeBSD$

PORTNAME=	libtsnnls
PORTVERSION=	2.3.3
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://www.jasoncantarella.com/downloads/

MAINTAINER=	tzhuan@gmail.com
COMMENT=	Fast Sparse Nonnegative Least Squares Solver

GNU_CONFIGURE=	yes
USES=		fortran libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GOTOBLAS ATLAS
GOTOBLAS_DESC=	Use gotoblas (conflict with USE_ATLAS)
ATLAS_DESC=	Use atlas (conflict with USE_GOTOBLAS)
# DMALLOC "Use dmalloc" off

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
#LIB_DEPENDS+=dmalloc.1:devel/dmalloc
#.endif

.if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:math/blas
LIB_DEPENDS+=	liblapack.so:math/lapack
BLAS=-lblas
LAPACK=-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2.so:math/gotoblas
BLAS=-lgoto2p
LAPACK=-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=-lptf77blas
LAPACK=-lalapack -lptcblas
.endif

CONFIGURE_ARGS+=--with-blas="${BLAS}" --with-lapack="${LAPACK}"
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
