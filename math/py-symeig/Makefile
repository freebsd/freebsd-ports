# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	symeig
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	SF/mdp-toolkit/mdp-toolkit/2.4
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Symmetrical eigenvalue routines for NumPy

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}

LATEST_LINK=	py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-numpy/options

USES=		fortran python:2
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-shared

OPTIONS_DEFINE=	ATLAS
ATLAS_DESC=	Use optimized blas library

ATLAS_LIB_DEPENDS=	libatlas.so:${PORTSDIR}/math/atlas
ATLAS_LIB_DEPENDS_OFF=	libblas.so:${PORTSDIR}/math/blas \
			liblapack.so:${PORTSDIR}/math/lapack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS} && !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATIC for symeig to function properly
.endif

.include <bsd.port.mk>
