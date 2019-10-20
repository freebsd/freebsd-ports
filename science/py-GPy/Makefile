# $FreeBSD$

PORTNAME=	GPy
DISTVERSION=	1.9.9
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gaussian process toolbox

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/lib/libomp.so:devel/openmp
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.16:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramz>=0.9.0:science/py-paramz@${PY_FLAVOR} \
		${LOCALBASE}/lib/libomp.so:devel/openmp

USES=		localbase python:-3.6
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
