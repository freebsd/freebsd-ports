# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scikit-learn
PORTVERSION=	0.15.2
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=source/s/scikit-learn
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Machine learning algorithms for python

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0.8.0:${PORTSDIR}/science/py-scipy

USES=		fortran python
USE_PYTHON=	distutils autoplist

OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	CBLAS ATLAS
OPTIONS_DEFAULT=	CBLAS
CBLAS_DESC=	Use math/cblas as BLAS library
ATLAS_DESC=	Use math/atlas as BLAS library

CBLAS_LIB_DEPENDS=	libcblas.so:${PORTSDIR}/math/cblas
ATLAS_LIB_DEPENDS=	libcblas.so:${PORTSDIR}/math/atlas

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCBLAS}
LDFLAGS+=	-lblas
.endif

LATEST_LINK=	py-${PORTNAME}

.include <bsd.port.mk>
