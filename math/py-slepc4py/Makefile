# $FreeBSD$

PORTNAME=	slepc4py
DISTVERSION=	3.9.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# https://bitbucket.org/slepc/slepc4py/issues/34/freebsd-compatibility-patches
PATCH_SITES=	https://bitbucket.org/petsc/petsc4py/commits/
PATCHFILES=	ab877906425e/raw:-p1 ecf673e8b8da/raw:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SLEPc for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libmpich.so:net/mpich2 \
		libpetsc.so:science/PETSc \
		libslepc.so:math/slepc
RUN_DEPENDS=	${PYNUMPY}

USES=		fortran python
USE_PYTHON=	distutils autoplist

MAKE_ENV=	PETSC_DIR=${LOCALBASE} SLEPC_DIR=${LOCALBASE}

.include <bsd.port.mk>
