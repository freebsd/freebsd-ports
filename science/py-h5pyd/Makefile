PORTNAME=	h5pyd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.0
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	H5py compatible client lib for HDF REST API
WWW=		https://github.com/HDFGroup/h5pyd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>0:security/py-google-auth-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-unixsocket>0:www/py-requests-unixsocket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.13.0:devel/py-six@${PY_FLAVOR}
# run-dependencies are messed up in the package, see https://github.com/HDFGroup/h5pyd/issues/285

USES=		pkgconfig python
USE_PYTHON=	pep517 concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	HDFGroup

NO_ARCH=	yes

.include <bsd.port.mk>
