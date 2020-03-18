# $FreeBSD$

PORTNAME=	lis
DISTVERSION=	2.0.21
CATEGORIES=	math
MASTER_SITES=	https://www.ssisc.org/lis/dl/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of Iterative Solvers for linear systems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	EXAMPLES MPI OPENMPI

MPI_CONFIGURE_ENABLE=		mpi
MPI_LIB_DEPENDS=		libmpi.so:net/mpich

OPENMPI_CONFIGURE_ENABLE=	omp

PORTEXAMPLES=	*

.include <bsd.port.mk>
