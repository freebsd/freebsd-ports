PORTNAME=	petiga
DISTVERSION=	g20210307
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for High Performance Isogeometric Analysis

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libpetsc.so:science/PETSc

USES=		gmake compiler:c++14-lang fortran
USE_LDCONFIG=	yes

MAKEFILE=	makefile

MAKE_ENV=	PETSC_DIR=${LOCALBASE}
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX} # https://bitbucket.org/dalcinl/petiga/issues/6/installs-into-prefix-tmp-petiga-instead-of

BB_ACCOUNT=	dalcinl
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	063a0ad5f450

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpetiga.so

.include <bsd.port.mk>
