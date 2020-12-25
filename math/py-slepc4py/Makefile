# $FreeBSD$

PORTNAME=	slepc4py
DISTVERSION=	3.10.0
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SLEPc for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

DEPRECATED=	Depends on broken and expiring math/slepc
EXPIRATION_DATE=	2020-12-29

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libmpich.so:net/mpich \
		libpetsc.so:science/PETSc \
		libslepc.so:math/slepc
RUN_DEPENDS=	${PYNUMPY}

USES=		fortran python
USE_PYTHON=	distutils autoplist

MAKE_ENV=	PETSC_DIR=${LOCALBASE} SLEPC_DIR=${LOCALBASE}

.include <bsd.port.mk>
