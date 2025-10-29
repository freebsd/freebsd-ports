PORTNAME=	hiPhive
DISTVERSION=	1.5
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-order force constants for the masses
WWW=		https://hiphive.materialsmodeling.org/ \
		https://gitlab.com/materials-modeling/hiphive/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.55:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>0:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.1:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trainstation>=0.2:science/py-trainstation@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail due to the numba bug: https://github.com/numba/numba/issues/9130

USE_GITLAB=	yes
GL_ACCOUNT=	materials-modeling
GL_PROJECT=	${PORTNAME:tl}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 1.5: 102 passed, 4 warnings, 1 error in 90.96s (0:01:30), see https://gitlab.com/materials-modeling/hiphive/-/issues/578

.include <bsd.port.mk>
