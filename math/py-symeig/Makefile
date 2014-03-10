# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	symeig
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	SF/mdp-toolkit/mdp-toolkit/2.3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symmetrical eigenvalue routines for NumPy

BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}

LATEST_LINK=	py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-numpy/options

USE_FORTRAN=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

OPTIONS_DEFINE=	ATLAS
ATLAS_DESC=	Use optimized blas library

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
.if !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATIC for symeig to function properly
.endif
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack \
		blas.2:${PORTSDIR}/math/blas
.endif

.include <bsd.port.mk>
