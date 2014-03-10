# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	symeig
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	math python
MASTER_SITES=	SF/mdp-toolkit/mdp-toolkit/2.3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Symmetrical eigenvalue routines for NumPy

BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}

LATEST_LINK=	py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-numpy/options

USES=		fortran
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	ATLAS
ATLAS_DESC=	Use optimized blas library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
.if !exists(${LOCALBASE}/lib/libalapack.a)
IGNORE=		atlas needs to be built with WITH_STATIC for symeig to function properly
.endif
.else
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack \
		libblas.so:${PORTSDIR}/math/blas
.endif

.include <bsd.port.mk>
