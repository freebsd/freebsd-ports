PORTNAME=	costa
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2
PORTREVISION=	4
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Distributed Communication-Optimal Shuffle and Transpose Algorithm
WWW=		https://github.com/eth-cscs/COSTA

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas \
		libscalapack.so:math/scalapack

USES=		cmake:testing pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eth-cscs
GH_PROJECT=	COSTA

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DCOSTA_SCALAPACK=CUSTOM
CMAKE_OFF=	COSTA_WITH_TESTS
CMAKE_TESTING_ON=	COSTA_WITH_TESTS

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

post-install: # workaround for https://github.com/eth-cscs/COSTA/issues/9
	@cd ${STAGEDIR}${PREFIX} && ${RMDIR} \
		include/costa/pxtran \
		include/costa/pxtranc \
		include/costa/pxtranu

.include <bsd.port.mk>
