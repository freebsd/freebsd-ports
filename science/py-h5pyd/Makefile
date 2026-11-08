PORTNAME=	h5pyd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
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
		${PYTHON_PKGNAMEPREFIX}h5json>=2.0.0:science/py-h5json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-unixsocket>0:www/py-requests-unixsocket@${PY_FLAVOR}
RUN_DEPENDS_google=	\
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>0:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>0:security/py-google-auth-oauthlib@${PY_FLAVOR}
RUN_DEPENDS+=	${RUN_DEPENDS_google}
# run-dependencies are messed up in the package, see https://github.com/HDFGroup/h5pyd/issues/285

USES=		pkgconfig python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	HDFGroup

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# most tests fail: ValueError: no endpoint set (they expect a running HDF REST server)

.include <bsd.port.mk>
