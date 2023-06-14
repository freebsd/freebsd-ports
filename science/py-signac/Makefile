PORTNAME=	signac
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Manage large and heterogeneous data spaces on the file system
WWW=		https://signac.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=3.0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=15.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.10.0:misc/py-tqdm@${PY_FLAVOR}
PY_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} # optional dependency
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zarr>0:devel/py-zarr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # some tests fail because of https://github.com/zarr-developers/zarr-python/issues/1407

USE_GITHUB=	yes
GH_ACCOUNT=	glotzerlab

BINARY_ALIAS=	python=${PYTHON_CMD}

NO_ARCH=	yes

.include <bsd.port.mk>
