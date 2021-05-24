# Created by: Maho Nakata <maho@FreeBSD.org>

PORTNAME=	suitesparse
PORTVERSION=	5.10.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Set of packages for sparse matrix calculation

LICENSE=	GPLv2+

RUN_DEPENDS=	suitesparse-AMD>0:math/suitesparse-amd			\
		suitesparse-BTF>0:math/suitesparse-btf			\
		suitesparse-CCOLAMD>0:math/suitesparse-ccolamd		\
		suitesparse-CHOLMOD>0:math/suitesparse-cholmod		\
		suitesparse-COLAMD>0:math/suitesparse-colamd		\
		suitesparse-config>0:math/suitesparse-config		\
		suitesparse-CXSparse>0:math/suitesparse-cxsparse	\
		suitesparse-GraphBLAS>0:math/suitesparse-graphblas	\
		suitesparse-KLU>0:math/suitesparse-klu			\
		suitesparse-LDL>0:math/suitesparse-ldl			\
		suitesparse-Mongoose>0:math/suitesparse-mongoose	\
		suitesparse-RBio>0:math/suitesparse-rbio		\
		suitesparse-SLIP_LU>0:math/suitesparse-slip_lu		\
		suitesparse-SPQR>0:math/suitesparse-spqr		\
		suitesparse-UMFPACK>0:math/suitesparse-umfpack
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	suitesparse-CSparse>0:math/suitesparse-csparse
.endif

USES=		metaport

.include <bsd.port.mk>
