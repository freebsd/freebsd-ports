# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	symeig
PORTVERSION=	1.5
PORTREVISION=	5
CATEGORIES=	math python
MASTER_SITES=	SF/mdp-toolkit/mdp-toolkit/2.4
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Symmetrical eigenvalue routines for NumPy

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}

USES=		fortran python:2.7
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-shared

OPTIONS_DEFINE=	ATLAS
ATLAS_DESC=	Use optimized blas library

ATLAS_LIB_DEPENDS=	libatlas.so:math/atlas
ATLAS_LIB_DEPENDS_OFF=	libblas.so:math/blas \
			liblapack.so:math/lapack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS} && !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATIC for symeig to function properly
.endif

.include <bsd.port.mk>
