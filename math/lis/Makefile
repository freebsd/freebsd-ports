PORTNAME=	lis
DISTVERSION=	2.1.10
CATEGORIES=	math
MASTER_SITES=	https://www.ssisc.org/lis/dl/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of Iterative Solvers for linear systems
WWW=		https://www.ssisc.org/lis/index.en.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool zip
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	EXAMPLES MPI OPENMPI

MPI_CONFIGURE_ENABLE=		mpi
MPI_LIB_DEPENDS=		libmpi.so:net/mpich

OPENMPI_CONFIGURE_ENABLE=	omp

PORTEXAMPLES=	*

.include <bsd.port.mk>
