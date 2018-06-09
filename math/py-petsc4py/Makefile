# $FreeBSD$

PORTNAME=	petsc4py
DISTVERSION=	3.9.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://bitbucket.org/petsc/petsc4py/commits/
PATCHFILES=	ab877906425e/raw:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PETSc for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libmpich.so:net/mpich2 \
		libpetsc.so:science/PETSc
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

MAKE_ENV=	PETSC_DIR=${LOCALBASE}

.include <bsd.port.mk>
