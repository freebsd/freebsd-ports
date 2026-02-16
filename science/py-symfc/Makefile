PORTNAME=	symfc
DISTVERSION=	1.6.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generate symmetrized force constants
WWW=		https://github.com/symfc/symfc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>0:science/py-spglib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phono3py>0:science/py-phono3py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

NO_ARCH=	yes

# tests as of 1.1.5: 21 failed, 36 passed, 22 warnings in 26.89s, see https://github.com/symfc/symfc/issues/133
# tests as of 1.3.1: 26 failed, 41 passed, 27 warnings in 45.46s
# tests as of 1.6.1: Tests fail: No such file or directory: 'phono3py_params_Si-111-222-rd.yaml.xz', see https://github.com/symfc/symfc/issues/273

.include <bsd.port.mk>
