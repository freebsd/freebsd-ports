PORTNAME=	morphio
PORTVERSION=	3.4.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Neuron morphology IO library
WWW=		https://github.com/openbraininstitute/MorphIO

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		ninja:devel/ninja \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
