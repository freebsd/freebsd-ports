PORTNAME=	suitesparse
PORTVERSION=	7.11.0
CATEGORIES=	math

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Set of packages for sparse matrix calculation
WWW=		https://faculty.cse.tamu.edu/davis/suitesparse.html

RUN_DEPENDS=	suitesparse-config>0:math/suitesparse-config		\
		suitesparse-amd>0:math/suitesparse-amd			\
		suitesparse-btf>0:math/suitesparse-btf			\
		suitesparse-camd>0:math/suitesparse-camd		\
		suitesparse-ccolamd>0:math/suitesparse-ccolamd		\
		suitesparse-colamd>0:math/suitesparse-colamd		\
		suitesparse-cholmod>0:math/suitesparse-cholmod		\
		suitesparse-cxsparse>0:math/suitesparse-cxsparse	\
		suitesparse-graphblas>0:math/suitesparse-graphblas	\
		suitesparse-klu>0:math/suitesparse-klu			\
		suitesparse-lagraph>0:math/suitesparse-lagraph		\
		suitesparse-ldl>0:math/suitesparse-ldl			\
		suitesparse-mongoose>0:math/suitesparse-mongoose	\
		suitesparse-rbio>0:math/suitesparse-rbio		\
		suitesparse-spex>0:math/suitesparse-spex		\
		suitesparse-spqr>0:math/suitesparse-spqr		\
		suitesparse-umfpack>0:math/suitesparse-umfpack		\
		suitesparse-paru>0:math/suitesparse-paru
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	suitesparse-csparse>0:math/suitesparse-csparse		\
		suitesparse-example>0:math/suitesparse-Example
.endif

USES=		metaport

.include <bsd.port.mk>
