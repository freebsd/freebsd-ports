# $FreeBSD$

PORTNAME=	moab
DISTVERSION=	5.1.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Component for representing and evaluating mesh data

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libnetcdf.so:science/netcdf \
		libopenblas.so:math/openblas

USES=		cmake:noninja compiler:c++11-lang eigen:3 fortran
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so \
		-DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so

BB_ACCOUNT=	fathomteam
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	7bde9dfb84a8

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

OPTIONS_DEFINE=		MPI
OPTIONS_DEFAULT=	MPI
OPTIONS_SUB=		yes

MPI_CMAKE_BOOL=		ENABLE_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi

.include <bsd.port.mk>
