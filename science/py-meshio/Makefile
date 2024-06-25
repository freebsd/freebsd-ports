PORTNAME=	meshio
PORTVERSION=	5.3.5
CATEGORIES=	science cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	I/O for many mesh formats
WWW=		https://github.com/nschloe/meshio

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}	\
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}netCDF4>0:science/py-netCDF4@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 pytest
PLIST_SUB=	VER=${PORTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
