# $FreeBSD$

PORTNAME=	moab
DISTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Component for representing and evaluating mesh data

LICENSE=	BSD2CLAUSE
xLICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libopenblas.so:math/openblas

USES=		cmake:outsource,noninja eigen:3 fortran
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so -DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so

BB_ACCOUNT=	fathomteam
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	c4eed56fd6d2

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

OPTIONS_DEFINE=		MPI
OPTIONS_DEFAULT=	MPI
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi

.include <bsd.port.mk>
